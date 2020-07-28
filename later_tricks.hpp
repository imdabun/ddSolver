// Currently not utilized as it is counter productive to running speed

#include "quick_tricks.hpp"

class LT_Solver
{
private:
  Deal& ds;

  int suit;

  int winner;

public:
  LT_Solver(Deal& deal);

  bool follow_trick(); // whether action hand can win current trick

  int trick_winner(); //

  int lt();
};