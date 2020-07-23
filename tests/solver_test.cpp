#include <chrono>
#include "test_deals.hpp"
#include "../solver.hpp"

using namespace std;

void print_deal(Deal deal)
{
  cout << "North hand: " << endl;
  cout << deal.hands[0] << endl;
  cout << "East hand: " << endl;
  cout << deal.hands[1] << endl;
  cout << "South hand: " << endl;
  cout << deal.hands[2] << endl;
  cout << "West hand: " << endl;
  cout << deal.hands[3] << endl;
}

/* 8 cards
 * TEST: WITHOUT EQUIV CARD SHAVING (ECS)
 * 16419 ms
 * 16583 ms
 * 16611 ms
 * >> 16538 ms
 * 
 * TEST: WITH EQUIV CARD SHAVING
 * 2412 ms
 * 2469 ms
 * 2454 ms
 * >> 2445 ms
 * 
 * 9 cards
 * TEST: ECS
 * 219959 ms
 */

int main()
{
  auto start = chrono::high_resolution_clock::now();
  Test_deals deal = Test_deals();
  Deal deal1 = deal.data[1];
  print_deal(deal1);
  Solver solve_test_1 = Solver(deal1);
  cout << "Solving deal 1: " << solve_test_1.ddSolve() << endl;
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); 
  cout << "Time taken: " << duration.count()/1000 << " ms" << endl;
return 0;
}