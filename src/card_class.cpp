/*  File: card_class.cpp
 *  Card class
 *  Yang Gan
 */

#include "card_class.hpp"

using namespace std;

Card::Card(int v, int s, int dir): hand(dir), val(v), suit(s) {}

Card::Card(const Card& other)
{
  hand = other.hand;
  val = other.val;
  suit = other.suit;
}

bool Card::operator<(const Card& other) const
{
  if (suit != other.suit) return (suit < other.suit);
  else return (val < other.val);
}

bool Card::operator>(const Card& other) const
{
  if (suit != other.suit) return (suit > other.suit);
  else return (val > other.val);
}

bool Card::operator==(const Card& other) const
{
  return (suit == other.suit) && (val == other.val);
}

ostream& operator<<(ostream& os, const Card& cd)
{
  int v = cd.val;
  int s = cd.suit;
  string v_str, s_str;

  switch(v)
  {
    case 12:
      v_str = "A";
      break;

    case 11:
      v_str = "K";
      break;

    case 10:
      v_str = "Q";
      break;

    case 9:
      v_str = "J";
      break;

    case 8:
      v_str = "T";
      break;

    default:
      v_str = to_string(v + 2);
      break;
  };

  switch(s)
  {
    case 0:
      s_str = "C";
      break;

    case 1:
      s_str = "D";
      break;

    case 2:
      s_str = "H";
      break;

    case 3:
      s_str = "S";
      break;
      
    default:
      s_str = "?";
      break;
  };
  
  os << s_str << v_str << " ";
  return os;
};

int trick_winner(vector<Card> trick, int trump)
{
  if (trick.size() != 4)
  {
    cout << "winner: Invalid trick." << endl;
    return -1;
  }

  Card& out = trick.front();
  int lead_suit = out.suit;

  for (auto &x : trick)
  {
    if ( (trump == -1 && x.suit == lead_suit && x > out) || // NT and followed suit
          (out.suit != trump && x.suit == trump) || // Trump on a not-yet-trumped trick
          (out.suit != trump && x.suit == lead_suit && x > out) || // Followed suit, win by rank
          (out.suit == trump && x.suit == trump && x > out) ) // Over-trumped
      out = x;
  }
  return out.hand;
}