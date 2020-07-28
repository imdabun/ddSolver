#include <chrono>
#include "test_deals.hpp"
#include "../src/solver.hpp"

using namespace std;

/* 01 >>
 * 
 * 02 >> 
 * 
 * 03 >> [3]
 * 885 ms
 * 
 * 04 >> [7]
 * 131955 ms
 * 
 * 05 >> [4]
 * 9 ms
 * 
 * 06 >> [3]
 * 1 ms
 * 
 * 07 >> [9]
 * 80955 ms 
 */

int main()
{
  int x = 0;
  auto start = chrono::high_resolution_clock::now();
  Test_deals deal = Test_deals();
  Deal deal1 = deal.data[x];
  Solver solve_test_1 = Solver(deal1);
  cout << "Solving deal " << (x + 1) << ": " << solve_test_1.ddSolve() << endl;
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); 
  cout << "Time taken: " << duration.count()/1000 << " ms" << endl;
return 0;
}