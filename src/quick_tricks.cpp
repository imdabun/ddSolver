/*  File: quick_tricks.cpp
 *  Quick Tricks Solver
 *  Yang Gan
 */

#include "quick_tricks.hpp"

using namespace std;

QT_Solver::QT_Solver(const Deal& deal): ds(deal), entry_from{false, false},
  quick_tricks{0, 0}
{
  if (ds.curr_trick.size() == 4 || ds.curr_trick.empty())
  {
    if (ds.trump < 0)
      nt_quicktricks();
    else
      suited_quicktricks();
  }
}

void QT_Solver::nt_quicktricks()
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
      else if (curr_card > sec_best)
        sec_best = curr_card;
    }

    if ((ctrl_hand - ds.action) % 2 == 0)
    {
      if (!ds.hands[(ctrl_hand + 2) % 4].cards[suit].empty())
      {
        if (ctrl_hand == ds.action)
          entry_from[1] = true;
        else
          entry_from[0] = true;
      }

      if (top_card != -1)
      {
        auto it = ds.hands[ctrl_hand].cards[suit].rbegin();
        to_add++;
        while ( ++it != ds.hands[ctrl_hand].cards[suit].rend() &&
              it->val > sec_best)
        {
          to_add++;
        }
      }
      
      if (ctrl_hand == ds.action)
        quick_tricks[0] += to_add;
      else 
        quick_tricks[1] += to_add;
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

    if ((ctrl_hand - ds.action) % 2 == 0)
      {
      int opp_ctrl = 13;
      if (suit != ds.trump)
      {
        int dir1 = (ctrl_hand + 1) % 2;
        int dir2 = (ctrl_hand + 1) % 2 + 2;
        int len1 = ds.hands[dir1].cards[suit].size();
        int len2 = ds.hands[dir2].cards[suit].size();
        int opp1 = ds.hands[dir1].cards[ds.trump].empty() ? 13 : len1;
        int opp2 = ds.hands[dir2].cards[ds.trump].empty() ? 13 : len2;
        opp_ctrl = min(opp1, opp2);
      }

      if (opp_ctrl != 0 && !ds.hands[(ctrl_hand + 2) % 4].cards[suit].empty())
      {
        if (ctrl_hand == ds.action)
          entry_from[1] = true;
        else
          entry_from[0] = true;
      }

      if (top_card != -1)
      {
        auto it = ds.hands[ctrl_hand].cards[suit].rbegin();
        if (to_add < opp_ctrl) to_add ++;
        while ( ++it != ds.hands[ctrl_hand].cards[suit].rend() &&
              it->val > sec_best)
        {
          if (to_add < opp_ctrl) to_add ++;
        }
      }
      
      if (ctrl_hand == ds.action)
        quick_tricks[0] += to_add;
      else 
        quick_tricks[1] += to_add;
    }
  }
}

int QT_Solver::qt()
{
  return (entry_from[0]) ? (quick_tricks[0] + quick_tricks[1])
                            : (quick_tricks[0]);
}