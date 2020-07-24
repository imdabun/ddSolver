/*  File: deal_class.cpp
 *  Play_state, State_hasher, State_eq, Deal classes
 *  Yang Gan
 */

#include "deal_class.hpp"

using namespace std;


/*** *** *** Play_state *** *** ***/
/* Play information is stored as 64-bit integer
 * Rightmost 52 bits: 0 = unplayed, 1 = played
 */

Play_state::Play_state()
{
  data = 0; // 0 is unplayed, 1 is played
}

bool Play_state::unplayed() const
{
  return data == 0;
}

void Play_state::play_all()
{
  data = 0x000FFFFFFFFFFFFF;
}

bool Play_state::play_card(const Card& card, int action)
{
  to_play = action;
  int index = card.suit * 13 + card.val;
  if ((data >> index) % 2) return false;
  else
  {
    data = data | (static_cast<unsigned long long int> (1) << index);
    return true;
  }
}

bool Play_state::unplay_card(const Card& card, int action)
{
  to_play = action;
  int index = card.suit * 13 + card.val;
  if (!((data >> index) % 2)) return false;
  else
  {
    data &= ~((static_cast<unsigned long long int> (1)) << index);
    return true;
  }
}

bool Play_state::card_state(const Card& card) const
{
  // true if card is played, false if unplayed
  int index = card.suit * 13 + card.val;
  return static_cast<bool> ((data >> index) % 2);
}

int Play_state::A() const
{ // For hasher; represents state of top 5 cards in each suit
  int A = 0;
  for (int i = 8; i < 13; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      int index = j * 13 + i;
      A <<= 1;
      A += ((data >> index) & (static_cast<unsigned long long int> (1)));
    }
  }
  return A;
}

int Play_state::B() const
{ // For hasher; represents state of next 5 cards in each suit
  int B = 0;
  for (int i = 3; i < 8; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      int index = j * 13 + i;
      B <<= 1;
      B += ((data >> index) & (static_cast<unsigned long long int> (1)));
    }
  }
  return B;
}


/*** *** *** State_hasher *** *** ***/
size_t State_hasher::operator()(const Play_state& S) const
{ // XOR on top 5 and next 5 cards in each suit
  return static_cast<size_t> (S.A() ^ S.B());
}


/*** *** *** State_eq *** *** ***/

bool State_eq::operator() (const Play_state& state1, const Play_state& state2) const
{
  return state1.data == state2.data && state1.to_play == state2.to_play;
}


/*** *** *** Deal *** *** ***/

Deal::Deal( const Hand& north, const Hand& east, 
      const Hand& south, const Hand& west, int to_play, int trp)
  : hands{ north, east, south, west }, action(to_play),
  trump(trp)
{
  // calculate play state
  play_state.play_all();
  play_state.to_play = action;
  
  // unplay all cards newly added
  for (int i = 0; i < 4; ++i)
  {
    for (auto &x : hands[i].all())
    {
      play_state.unplay_card(x, 0);
    }
  }

  for (int suit = 0; suit < 4; ++suit)
  {
    for (int dir = 0; dir < 4; ++dir)
    {
      if (hands[dir].cards[suit].empty())
        highest_card[suit][dir] = -1;
      else
        highest_card[suit][dir] = hands[dir].cards[suit].back().val;
    }
  }

  play_state.to_play = action;

  // calculate tricks_left
  tricks_left = hands[static_cast<int> (to_play)].get_size();
}

bool Deal::play_card(const Card card)
{
  hands[card.hand].rem_card(card.val, card.suit);

  // Recycle curr_trick memory if new trick initiated
  if (curr_trick.size() == 4 || curr_trick.empty()) 
  {
    past_tricks.push_back(curr_trick);
    curr_trick.clear();
    curr_trick.push_back(card);
    curr_suit = card.suit;
  }
  else 
  {
    curr_trick.push_back(card);
  }

  // If played card completes a trick winner calculated
  if (curr_trick.size() == 4) 
  {
    --tricks_left;
    action = trick_winner(curr_trick, trump);
    curr_suit = -1;
  }
  else action = (action + 1) % 4;
  play_state.to_play = action;

  bool res = play_state.play_card(card, action);
  
  if (res && card.val == highest_card[card.suit][card.hand])
  {
    if (hands[card.hand].cards[card.suit].empty())
      highest_card[card.suit][card.hand] = -1;
    else 
      highest_card[card.suit][card.hand] 
      = hands[card.hand].cards[card.suit].back().val;
  }

  return res;
}

bool Deal::unplay_card()
{
  if (play_state.unplayed()) return false;
  if (curr_trick.size() == 4) ++tricks_left;

  // Debugging
  try
  {
    if (curr_trick.empty()) throw 1;
  }
  catch (int e)
  {
    cout << "unplay_card: trick is empty somehow" << endl;
    return false;
  }

  Card last_played = curr_trick.back();
  curr_trick.pop_back();
  hands[last_played.hand].add_card(last_played.val, last_played.suit);
  action = last_played.hand;
  play_state.unplay_card(last_played, action);
  play_state.to_play = last_played.hand;

  // If unplaying first card of trick retrieve last trick
  if (curr_trick.empty() && !play_state.unplayed())
  {
    curr_suit = -1;
    curr_trick = past_tricks.back();
    past_tricks.pop_back();
  } 

  int suit = last_played.suit;
  int dir = last_played.hand;
  if (last_played.val > highest_card[suit][dir])
    highest_card[suit][dir] = last_played.val;

  return true;
}

bool Deal::suit_empty(int suit) const
{
  return hands[action].cards[suit].empty();
}

void Deal::get_from_suit(vector<Card>& target, int suit) const
{ // Retrieve top of equal valued cards, taking into account played cards
  for (auto it = hands[action].cards[suit].rbegin(); 
        it != hands[action].cards[suit].rend(); ++it)
  {
    if (target.empty() || target.back().suit != (*it).suit) 
      target.push_back(*it);
    else
    {
      auto prev = it - 1;
      if (!((*prev).val - 1 == (*it).val))
      {
        int prev_val = target.back().val;
        int prev_suit = target.back().suit;
        bool check = false;
        if (curr_trick.empty() || curr_trick.size() == 4)
        {
          for (int j = prev_val - 1; j > (*it).val; --j)
          {
            if (!play_state.card_state(Card(j, prev_suit))) 
              check = true;
          }
        }
        else
        {
          check = true;
        }
        if (check) target.push_back(*it);
      }
    }
  }
}

void Deal::generate_moves(vector<Card>& target) const
{ // Generate all valid cards to play
  if (curr_suit == -1 || suit_empty(curr_suit))
  {
    for (int i = 0; i < 4; ++i)
    {
      get_from_suit(target, i);
    }
  }
  else
  {
    get_from_suit(target, curr_suit);
  }
}


bool Deal::last_trick()
{
  // Requires exactly 4 cards left to play
  vector<Card> trick;
  for (int i = 0; i < 4; ++i)
  {
    Card last = Card(-1, -1);
    for (int j = 0; j < 4; ++j)
    {
      if (!hands[i].cards[j].empty())
      {
        last = hands[i].cards[j].front();
        break;
      }
    }
    trick.push_back(last);
  }
  return trick_winner(trick, trump) == action;
}