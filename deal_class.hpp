/*  File: deal_class.hpp
 *  Play_state, State_hasher, State_eq, Deal classes
 *  Yang Gan
 */

#ifndef DDS_DEAL_CLASS_H
#define DDS_DEAL_CLASS_H

#include "hand_class.hpp"


/*** *** *** Play_state *** *** ***/
class Play_state
{
public:
  unsigned long long int data;

  int to_play;

  Play_state();

  bool unplayed() const;

  void play_all();

  bool play_card(const Card& card, int action);

  bool unplay_card(const Card& card, int action);

  bool card_state(const Card& card) const;

  int A() const;

  int B() const;
};


/*** *** *** State_hasher *** *** ***/
class State_hasher
{
public:
  std::size_t operator()(const Play_state& S) const;
};


/*** *** *** State_eq *** *** ***/
class State_eq
{
public:
  bool operator() (const Play_state& state1, const Play_state& state2) const;
};


/*** *** *** Deal *** *** ***/
class Deal
{
public: 
  Play_state play_state;

  int highest_card[4][4]; // [suit][dir]

  int action;

  int trump;
  
  int tricks_left;

  Hand hands[4];

  std::vector<Card> curr_trick;

  std::vector<std::vector<Card>> past_tricks;

  int curr_suit = -1;

  Deal( const Hand& north, const Hand& east, const Hand& south, 
        const Hand& west, int to_play = 0, int trp = -1);

  bool play_card(const Card);

  bool unplay_card();

  bool suit_empty(int suit) const;

  void get_from_suit(std::vector<Card>& target, int suit) const;

  void generate_moves(std::vector<Card>& target) const;

  bool last_trick();
};

#endif