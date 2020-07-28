// Currently not utilized as it is counter productive to running speed

#include "later_tricks.hpp"

using namespace std;

LT_Solver::LT_Solver(Deal& deal): ds(deal), winner(-1)
{
  suit = ds.curr_trick.front().suit;
  winner = ds.curr_trick.front().hand;
  int top_card = ds.curr_trick.front().val;

  for (auto &x: ds.curr_trick)
  {
    if (x.suit != suit)
    {
      winner = -1;
      goto stop;
    }
    else if (x.val > top_card)
    {
      winner = x.hand;
    }
  }

  for (int played = 0; played < (4 - ds.curr_trick.size()); ++played)
  {
    int curr_card = ds.highest_card[suit][(ds.action + played) % 4];
    if (curr_card < 0)
    {
      winner = -1;
      goto stop;
    }
    else if (curr_card > top_card)
    {
      winner = ds.action + played;
    }
  }
  
  stop: ;
}

bool LT_Solver::follow_trick()
{
  return (winner >= 0);
}

int LT_Solver::trick_winner()
{
  return winner;
}

int LT_Solver::lt()
{
  if (winner < 0) 
  {
    cout << "lt() error" << endl;
    return -1;
  }
  int finish = 4 - ds.curr_trick.size();
  for (int i = 0; i < finish; ++i)
  {
    int val = ds.highest_card[suit][ds.action];
    ds.play_card(Card(val, suit, ds.action));
  }

  // Likely follow_trick is wrong, check that then fix this.

  QT_Solver solver = QT_Solver(ds);
  int out = solver.qt();

  for (int i = 0; i < finish; ++i)
    ds.unplay_card();
  
  return out;
}