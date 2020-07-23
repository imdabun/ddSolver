#include "deal_class.hpp"

Deal test_case_1()
{
  vector<pair<card_v, card_s>> north;
  north.push_back(pair<card_v, card_s> (VT, SPADE));
  north.push_back(pair<card_v, card_s> (V7, SPADE));
  north.push_back(pair<card_v, card_s> (V8, HEART));
  north.push_back(pair<card_v, card_s> (V6, HEART));
  north.push_back(pair<card_v, card_s> (V3, HEART));
  north.push_back(pair<card_v, card_s> (V9, CLUB));
  north.push_back(pair<card_v, card_s> (V7, CLUB));
  auto north_hand = Hand(north, NORTH);
  cout << "North hand loaded." << endl << north_hand << endl;

  vector<pair<card_v, card_s>> east;
  east.push_back(pair<card_v, card_s> (VQ, SPADE));
  east.push_back(pair<card_v, card_s> (V9, DIME));
  east.push_back(pair<card_v, card_s> (V7, DIME));
  east.push_back(pair<card_v, card_s> (V6, DIME));
  east.push_back(pair<card_v, card_s> (VK, CLUB));
  east.push_back(pair<card_v, card_s> (V8, CLUB));
  east.push_back(pair<card_v, card_s> (V5, CLUB));
  auto east_hand = Hand(east, EAST);
  cout << "East hand loaded." << endl << east_hand << endl;

  vector<pair<card_v, card_s>> south;
  south.push_back(pair<card_v, card_s> (V4, SPADE));
  south.push_back(pair<card_v, card_s> (VA, HEART));
  south.push_back(pair<card_v, card_s> (VK, HEART));
  south.push_back(pair<card_v, card_s> (VT, HEART));
  south.push_back(pair<card_v, card_s> (VA, DIME));
  south.push_back(pair<card_v, card_s> (VQ, DIME));
  south.push_back(pair<card_v, card_s> (V5, DIME));
  auto south_hand = Hand(south, SOUTH);
  cout << "South hand loaded." << endl << south_hand << endl;

  vector<pair<card_v, card_s>> west;
  west.push_back(pair<card_v, card_s> (V9, SPADE));
  west.push_back(pair<card_v, card_s> (VJ, HEART));
  west.push_back(pair<card_v, card_s> (V7, HEART));
  west.push_back(pair<card_v, card_s> (V4, HEART));
  west.push_back(pair<card_v, card_s> (VK, DIME));
  west.push_back(pair<card_v, card_s> (VT, DIME));
  west.push_back(pair<card_v, card_s> (V3, DIME));
  auto west_hand = Hand(west, WEST);
  cout << "West hand loaded." << endl << west_hand << endl;

  return Deal(north_hand, east_hand, south_hand, west_hand, 1, NORTH);
}


int main()
{
  Solver test = Solver(test_case_1());
  cout << test.ddSearch(8);
return 0;
}