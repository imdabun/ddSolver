/*  File: solver.hpp
 *  Solver class
 *  Yang Gan    21/07/2020
 */

#ifndef DDS_SOLVER_H
#define DDS_SOLVER_H

#include <cstdlib>
#include <unordered_map>

#include "deal_class.hpp"

typedef 
std::unordered_map<Play_state, std::pair<int, int>, State_hasher, State_eq> 
deal_hashmp;

class Solver
{
private:
  Deal ds;

  deal_hashmp memo;

public:
  Solver(Deal& initial);

  bool ddSearch(int goal);

  int ddSolve();
};

#endif