/*  File: card_class.hpp
 *  Card class
 *  Yang Gan    21/07/2020
 */

#ifndef DDS_CARD_CLASS_H
#define DDS_CARD_CLASS_H

#include <iostream>
#include <cstdlib>
#include <vector>

class Card
{
public:
  int hand;
  int val; 
  int suit;

  Card(int v, int s, int dir = 0);

  Card(const Card& other);

  bool operator<(const Card& other) const;

  bool operator>(const Card& other) const;

  bool operator==(const Card& other) const;

private:
  friend std::ostream& operator<<(std::ostream& os, const Card& cd);
};

std::ostream& operator<<(std::ostream& os, const Card& cd);

int trick_winner(std::vector<Card> trick, int trump);

#endif