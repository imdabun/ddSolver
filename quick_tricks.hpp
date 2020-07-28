/*  File: quick_tricks.hpp
 *  Quick Tricks Solver
 *  Yang Gan
 */

#include "deal_class.hpp"

class QT_Solver
{
private:
  Deal ds;

  bool entry_from[2];

  int quick_tricks[2];
  
  void nt_quicktricks();

  void suited_quicktricks();

public:
  QT_Solver(const Deal& deal);

  int qt();
};