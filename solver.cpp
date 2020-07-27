/*  File: solver.cpp
 *  Solver class
 *  Yang Gan
 */

#include "deal_class.hpp"
#include "solver.hpp"
#include "quick_tricks.hpp"

using namespace std;

Solver::Solver(Deal& initial): ds(initial)
{
  // Store dictionary of checked states
  int upper = ds.tricks_left + 1;
  memo[ds.play_state] = pair<int, int> (0, upper);
} 

void update_lo(deal_hashmp& memo, Play_state state, int new_lo, int max_pos)
{
  auto got = memo.find(state);
  if (got == memo.end())
  {
    // create new entry
    memo[state] = pair<int, int> (new_lo, max_pos + 1);
  }
  else
  {
    // update entry
    (got->second).first = max (new_lo, (got->second).first);

  }
}

void update_hi(deal_hashmp& memo, Play_state state, int new_hi)
{
  auto got = memo.find(state);
  if (got == memo.end())
  {
    // create new entry
    memo[state] = pair<int, int> (0, new_hi);
  }
  else
  {
    // update entry
    (got->second).second = min (new_hi, (got->second).second);
  }
}

bool Solver::ddSearch(int goal)
{
  int search_max = ds.tricks_left;
  int search_action = ds.action;
  if (goal <= 0) return true;
  if (goal > search_max) return false;
  if (search_max == 1)
  {
    bool ret = ds.last_trick();
    return ret;
  }

  bool trick_start = false;
  // if this is the start of a new trick, check hashmap
  if (ds.curr_trick.size() == 4 || ds.curr_trick.empty())
  {
    trick_start = true;

    // check hashmap FIRST
    auto got = memo.find(ds.play_state);
    if (got != memo.end())
    {
      if (goal <= (got->second).first) return true;
      if (goal >= (got->second).second) return false;
    }

    // find quick_tricks
    QT_Solver qt_start = QT_Solver(ds);
    if (goal <= qt_start.friendly_QT())
    {
      update_lo(memo, ds.play_state, qt_start.friendly_QT(), search_max);
      return true;
    }
  }

  vector<Card> moves;
  ds.generate_moves(moves);
  for (auto &c : moves)
  {
    ds.play_card(c);
    bool next;
    // if action belongs to same team, search_action's team won a trick
    if ((search_action - ds.action) % 2 == 0)
    {
      next = ddSearch(goal - 1);
    }
    // else either opponent followed suit or they won the trick
    else
    {
      if (search_max != ds.tricks_left) 
        next = !ddSearch(search_max - goal);
      else
        next = !ddSearch(search_max - goal + 1);
    }
    ds.unplay_card();
    if (next) 
    {
      if (trick_start == true)
        update_lo(memo, ds.play_state, goal, search_max);
      return true;
    }
  }
  // Goal cannot be reached, update hashmap
  {
    if (trick_start == true)
      update_hi(memo, ds.play_state, goal);
    return false;
  }
}

int Solver::ddSolve()
{
  int hi = ds.tricks_left + 1;
  int lo = 0;
  while(lo + 1 < hi)
  {
    int goal = (lo + hi) / 2;
    if (ddSearch(goal)) lo = goal;
    else hi = goal;
  }
  return lo;
}