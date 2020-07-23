#include "deal_class.hpp"

Deal test_case()
{
  vector<pair<card_v, card_s>> north;
  north.push_back(pair<card_v, card_s> (VA, SPADE));
  north.push_back(pair<card_v, card_s> (VT, SPADE));
  north.push_back(pair<card_v, card_s> (V6, HEART));
  north.push_back(pair<card_v, card_s> (V3, HEART));
  north.push_back(pair<card_v, card_s> (V8, DIME));
  north.push_back(pair<card_v, card_s> (V7, CLUB));
  auto north_hand = Hand(north, NORTH);
  if (north_hand.get_size() == 6) 
    cout << "North hand loaded." << endl << north_hand << endl;
  else cout << "North hand does not have 13 cards." << endl;

  vector<pair<card_v, card_s>> east;
  east.push_back(pair<card_v, card_s> (VQ, SPADE));
  east.push_back(pair<card_v, card_s> (V2, DIME));
  east.push_back(pair<card_v, card_s> (VK, CLUB));
  east.push_back(pair<card_v, card_s> (V8, CLUB));
  east.push_back(pair<card_v, card_s> (V5, CLUB));
  east.push_back(pair<card_v, card_s> (V3, CLUB));
  auto east_hand = Hand(east, EAST);
  if (east_hand.get_size() == 6) 
    cout << "East hand loaded." << endl << east_hand << endl;
  else cout << "East hand does not have 13 cards." << endl;

  vector<pair<card_v, card_s>> south;
  south.push_back(pair<card_v, card_s> (VJ, SPADE));
  south.push_back(pair<card_v, card_s> (VK, HEART));
  south.push_back(pair<card_v, card_s> (VT, HEART));
  south.push_back(pair<card_v, card_s> (V5, HEART));
  south.push_back(pair<card_v, card_s> (VA, DIME));
  south.push_back(pair<card_v, card_s> (V4, DIME));
  auto south_hand = Hand(south, SOUTH);
  if (south_hand.get_size() == 6)
    cout << "South hand loaded." << endl << south_hand << endl;
  else cout << "South hand does not have 13 cards." << endl;

  vector<pair<card_v, card_s>> west;
  west.push_back(pair<card_v, card_s> (VK, SPADE));
  west.push_back(pair<card_v, card_s> (V7, HEART));
  west.push_back(pair<card_v, card_s> (V4, HEART));
  west.push_back(pair<card_v, card_s> (VK, DIME));
  west.push_back(pair<card_v, card_s> (VJ, DIME));
  west.push_back(pair<card_v, card_s> (V2, CLUB));
  auto west_hand = Hand(west, WEST);
  if (west_hand.get_size() == 6) 
    cout << "West hand loaded." << endl << west_hand << endl;
  else cout << "West hand does not have 13 cards." << endl;

  return Deal(north_hand, east_hand, south_hand, west_hand, 1, NORTH);
}