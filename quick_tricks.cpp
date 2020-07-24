/*  File: quick_tricks.cpp
 *  Quick Tricks Solver
 *  Yang Gan
 */

#include "quick_tricks.hpp"

using namespace std;

QT_Solver::QT_Solver(const Deal& deal): ds(deal), 
  entry_from{false, false, false, false}, quick_tricks{0, 0, 0, 0}
{
  if (ds.trump < 0)
    nt_quicktricks();
  else
    suited_quicktricks();
}

void QT_Solver::nt_quicktricks()
{
  for (int suit = 0; suit < 4; ++suit)
  {
    int ctrl_hand = 0;
    int top_card = ds.highest_card[suit][0];
    int sec_best = -1;
    for (int dir = 1; dir < 4; ++dir)
    {
      int curr_card = ds.highest_card[suit][dir];
      if (curr_card > top_card)
      {
        sec_best = top_card;
        top_card = curr_card;
        ctrl_hand = dir;
      }
      else if (curr_card > sec_best)
        sec_best = curr_card;
    }

    if (!ds.hands[(ctrl_hand + 2) % 4].cards[suit].empty())
      entry_from[(ctrl_hand + 2) % 4] = true;

    if (top_card != -1)
    {
      auto it = ds.hands[ctrl_hand].cards[suit].rbegin();
      quick_tricks[ctrl_hand]++;
      while ((++it)->val > sec_best)
      {
        quick_tricks[ctrl_hand]++;
      }
    }
  }
}

void QT_Solver::suited_quicktricks()
{
  for (int suit = 0; suit < 4; ++suit)
  {
    int to_add = 0;
    int ctrl_hand = 0;
    int top_card = ds.highest_card[suit][0];
    int sec_best = -1;
    for (int dir = 1; dir < 4; ++dir)
    {
      int curr_card = ds.highest_card[suit][dir];
      if (curr_card > top_card)
      {
        sec_best = top_card;
        top_card = curr_card;
        ctrl_hand = dir;
      }
    }

    int opp_ctrl;
    if (suit != ds.trump)
    {
      int opp_ctrl = min<int> (ds.hands[(ctrl_hand + 1) % 2].cards[suit].size(), 
                      ds.hands[(ctrl_hand + 1) % 2 + 2].cards[suit].size());
    }

    if (opp_ctrl != 0 && !ds.hands[(ctrl_hand + 2) % 4].cards[suit].empty())
      entry_from[(ctrl_hand + 2) % 4] = true;

    if (top_card != -1)
    {
      auto it = ds.hands[ctrl_hand].cards[suit].rbegin();
      if (to_add < opp_ctrl) to_add ++;
      while ((*(++it)).val > sec_best)
        if (to_add < opp_ctrl) to_add ++;
    }
    quick_tricks[ctrl_hand] += to_add;
  }
}

int QT_Solver::friendly_QT()
{
  int pard = (ds.action + 2) % 4;
  return (entry_from[ds.action]) ? (quick_tricks[ds.action] + quick_tricks[pard])
                            : (quick_tricks[ds.action]);
}
