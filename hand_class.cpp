/*  File: hand_class.cpp
 *  Hands class
 *  Yang Gan    21/07/2020
 */

#include <algorithm>
#include "hand_class.hpp"

using namespace std;

// Helper function
void insert_cd(vector<Card>& target, Card& obj)
{
  auto it = lower_bound( target.begin(), target.end(), obj );
  target.insert( it, obj );
}


/*** *** *** Hand *** *** ***/

Hand::Hand() {}

Hand::Hand(const vector<pair<int, int>>& cards, const int dir)
  : direction(dir)
{
  for (auto &p : cards) 
  {
    try
    {
      add_card(p.first, p.second) ? : throw 1;
    }
    catch (int e)
    {
      cout << "Exception: failed to add card using Hand constructor." << endl;
    }
  }
}

bool Hand::card_exists(int val, int suit)
{
  for (auto &x : cards[suit])
  {
    if (x.val == val) return true;
  }
  return false;
}

bool Hand::add_card(int val, int suit)
{
  if (suit < 0 || suit > 3) return false;
  if (card_exists(val, suit))
  {
    cout << "add_card: Card " << Card(val, suit) << "already exists!" << endl;
    return false;
  }
  else 
  {
    Card c = Card(val, suit, direction);
    insert_cd(cards[suit], c);
    return true;
  }
}

bool Hand::rem_card(int val, int suit)
{
  if (!card_exists(val, suit)) return false;
  else
  {
    cards[suit].erase(remove_if(cards[suit].begin(), cards[suit].end(), 
    [val](Card cd)
    {
      return cd.val == val;
    }));
    return true;
  }
}

vector<Card> Hand::all() const
{
  vector<Card> out;
  for (int i = 0; i < 4; ++i)
  {
    for (auto &x : cards[i])
    {
      out.push_back(x);
    }
  }
  return out;
}

int Hand::get_size() const
{
  int res = 0;
  for (int i = 0; i < 4; ++i)
  {
    res += (cards[i].size());
  }
  return res;
}

ostream& operator<<(ostream& os, Hand& cd)
{
  for (int i = 0; i < 4; ++i)
  {
    for (auto c = cd.cards[3-i].rbegin(); c != cd.cards[3-i].rend(); ++c)
    {
      os << (*c);
    }
    os << endl;
  }
  return os;
}