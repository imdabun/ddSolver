/*  File: hand_class.hpp
 *  Hands class
 *  Yang Gan
 */

#ifndef DDS_HAND_CLASS_H
#define DDS_HAND_CLASS_H

#include "card_class.hpp"


/*** *** *** Hand *** *** ***/

class Hand
{
public:
  std::vector<Card> cards[4];

  int direction;

  Hand();

  Hand(const std::vector<std::pair<int, int>>& cards, const int dir = 0);

  bool card_exists(int val, int suit);

  bool add_card(int val, int suit);

  bool rem_card(int val, int suit);

  std::vector<Card> all() const;

  int get_size() const;

  friend std::ostream& operator<<(std::ostream& os, Hand& cd);
};

std::ostream& operator<<(std::ostream& os, Hand& cd);

#endif