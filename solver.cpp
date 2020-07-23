/*  File: solver.cpp
 *  Solver class
 *  Yang Gan    21/07/2020
 */

#include "deal_class.hpp"
#include "solver.hpp"
#include <unordered_map>

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
    (got->second).first = new_lo;
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
    (got->second).second = new_hi;
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
    if (ret) update_lo(memo, ds.play_state, 1, search_max);
    return ret;
  }

  bool trick_start = false;
  // if this is the start of a new trick, check hashmap
  if (ds.curr_trick.size() == 4 || ds.curr_trick.empty())
  {
    trick_start = true;
    auto got = memo.find(ds.play_state);
    if (got != memo.end())
    {
      int lo = (got->second).first;
      int hi = (got->second).second;
      if (goal <= lo) return true;
      if (goal >= hi) return false;
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
  int hi = ds.tricks_left;
  int lo = 0;
  while(lo + 1 < hi)
  {
    int goal = (lo + hi) / 2;
    if (ddSearch(goal)) lo = goal;
    else hi = goal;
  }
  return lo;
}