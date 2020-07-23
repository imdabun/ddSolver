#ifndef TEST_DEALS_H
#define TEST_DEALS_H

#include "../deal_class.hpp"

class Test_deals
{
public:
  std::vector<Deal> data;

  Test_deals()
  {
      /* Building hand:
    *          KQT74
    *          J2
    *          Q765
    *          42
    * J92                  A653
    * T97                  Q86
    * A9                   KJ42
    * KT953                J8
    *          8
    *          AK543
    *          T83
    *          AQ76
    */

    
    // North hand
    std::vector<std::pair<int, int>> north;
    north.push_back(std::pair<int, int> (11, 3));
    north.push_back(std::pair<int, int> (10, 3));
    north.push_back(std::pair<int, int> (8, 3));
    north.push_back(std::pair<int, int> (5, 3));
    north.push_back(std::pair<int, int> (2, 3));
    north.push_back(std::pair<int, int> (9, 2));
    north.push_back(std::pair<int, int> (0, 2));
    north.push_back(std::pair<int, int> (10, 1));
    north.push_back(std::pair<int, int> (5, 1));
    north.push_back(std::pair<int, int> (4, 1));
    north.push_back(std::pair<int, int> (3, 1));
    north.push_back(std::pair<int, int> (2, 0));
    north.push_back(std::pair<int, int> (0, 0));
    Hand north_hand = Hand(north, 0);

    // East hand
    std::vector<std::pair<int, int>> east;
    east.push_back(std::pair<int, int> (12, 3));
    east.push_back(std::pair<int, int> (4, 3));
    east.push_back(std::pair<int, int> (3, 3));
    east.push_back(std::pair<int, int> (1, 3));
    east.push_back(std::pair<int, int> (10, 2));
    east.push_back(std::pair<int, int> (6, 2));
    east.push_back(std::pair<int, int> (4, 2));
    east.push_back(std::pair<int, int> (11, 1));
    east.push_back(std::pair<int, int> (9, 1));
    east.push_back(std::pair<int, int> (2, 1));
    east.push_back(std::pair<int, int> (0, 1));
    east.push_back(std::pair<int, int> (9, 0));
    east.push_back(std::pair<int, int> (6, 0));
    Hand east_hand = Hand(east, 1);

    // South hand
    std::vector<std::pair<int, int>> south;
    south.push_back(std::pair<int, int> (6, 3));
    south.push_back(std::pair<int, int> (12, 2));
    south.push_back(std::pair<int, int> (11, 2));
    south.push_back(std::pair<int, int> (3, 2));
    south.push_back(std::pair<int, int> (2, 2));
    south.push_back(std::pair<int, int> (1, 2));
    south.push_back(std::pair<int, int> (8, 1));
    south.push_back(std::pair<int, int> (6, 1));
    south.push_back(std::pair<int, int> (1, 1));
    south.push_back(std::pair<int, int> (12, 0));
    south.push_back(std::pair<int, int> (10, 0));
    south.push_back(std::pair<int, int> (5, 0));
    south.push_back(std::pair<int, int> (4, 0));
    Hand south_hand = Hand(south, 2);

    // West hand
    std::vector<std::pair<int, int>> west;
    west.push_back(std::pair<int, int> (9, 3));
    west.push_back(std::pair<int, int> (7, 3));
    west.push_back(std::pair<int, int> (0, 3));
    west.push_back(std::pair<int, int> (8, 2));
    west.push_back(std::pair<int, int> (7, 2));
    west.push_back(std::pair<int, int> (5, 2));
    west.push_back(std::pair<int, int> (12, 1));
    west.push_back(std::pair<int, int> (7, 1));
    west.push_back(std::pair<int, int> (11, 0));
    west.push_back(std::pair<int, int> (8, 0));
    west.push_back(std::pair<int, int> (7, 0));
    west.push_back(std::pair<int, int> (3, 0));
    west.push_back(std::pair<int, int> (1, 0));
    Hand west_hand = Hand(west, 3);

    Deal test_deal_1 = Deal(north_hand, east_hand, south_hand, west_hand);
    data.push_back(test_deal_1);

   // North hand
    std::vector<std::pair<int, int>> north1;
    north1.push_back(std::pair<int, int> (10, 3));
    north1.push_back(std::pair<int, int> (8, 3));
    north1.push_back(std::pair<int, int> (9, 2));
    north1.push_back(std::pair<int, int> (0, 2));
    north1.push_back(std::pair<int, int> (10, 1));
    north1.push_back(std::pair<int, int> (5, 1));
    north1.push_back(std::pair<int, int> (4, 1));
    north1.push_back(std::pair<int, int> (3, 1));
    Hand north_hand1 = Hand(north1, 0);

    // East hand
    std::vector<std::pair<int, int>> east1;
    east1.push_back(std::pair<int, int> (12, 3));
    east1.push_back(std::pair<int, int> (10, 2));
    east1.push_back(std::pair<int, int> (6, 2));
    east1.push_back(std::pair<int, int> (11, 1));
    east1.push_back(std::pair<int, int> (9, 1));
    east1.push_back(std::pair<int, int> (2, 1));
    east1.push_back(std::pair<int, int> (0, 1));
    east1.push_back(std::pair<int, int> (6, 0));
    Hand east_hand1 = Hand(east1, 1);

    // South hand
    std::vector<std::pair<int, int>> south1;
    south1.push_back(std::pair<int, int> (12, 2));
    south1.push_back(std::pair<int, int> (11, 2));
    south1.push_back(std::pair<int, int> (8, 1));
    south1.push_back(std::pair<int, int> (6, 1));
    south1.push_back(std::pair<int, int> (1, 1));
    south1.push_back(std::pair<int, int> (12, 0));
    south1.push_back(std::pair<int, int> (5, 0));
    south1.push_back(std::pair<int, int> (4, 0));
    Hand south_hand1 = Hand(south1, 2);

    // West hand
    std::vector<std::pair<int, int>> west1;
    west1.push_back(std::pair<int, int> (9, 3));
    west1.push_back(std::pair<int, int> (7, 2));
    west1.push_back(std::pair<int, int> (5, 2));
    west1.push_back(std::pair<int, int> (12, 1));
    west1.push_back(std::pair<int, int> (7, 1));
    west1.push_back(std::pair<int, int> (11, 0));
    west1.push_back(std::pair<int, int> (8, 0));
    west1.push_back(std::pair<int, int> (7, 0));
    Hand west_hand1 = Hand(west1, 3);
    Deal test_deal_2 = Deal(north_hand1, east_hand1, south_hand1, west_hand1, 2);
    data.push_back(test_deal_2);


    // North hand
    std::vector<std::pair<int, int>> north2;
    north2.push_back(std::pair<int, int> (1, 3));
    north2.push_back(std::pair<int, int> (11, 2));
    north2.push_back(std::pair<int, int> (6, 2));
    north2.push_back(std::pair<int, int> (4, 2));
    north2.push_back(std::pair<int, int> (12, 1));
    north2.push_back(std::pair<int, int> (11, 1));
    north2.push_back(std::pair<int, int> (10, 1));
    north2.push_back(std::pair<int, int> (8, 1));
    north2.push_back(std::pair<int, int> (3, 1));
    Hand north_hand2 = Hand(north2, 0);

    // East hand
    std::vector<std::pair<int, int>> east2;
    east2.push_back(std::pair<int, int> (11, 3));
    east2.push_back(std::pair<int, int> (9, 3));
    east2.push_back(std::pair<int, int> (7, 3));
    east2.push_back(std::pair<int, int> (6, 1));
    east2.push_back(std::pair<int, int> (11, 0));
    east2.push_back(std::pair<int, int> (10, 0));
    east2.push_back(std::pair<int, int> (8, 0));
    east2.push_back(std::pair<int, int> (7, 0));
    east2.push_back(std::pair<int, int> (0, 0));
    Hand east_hand2 = Hand(east2, 1);

    // South hand
    std::vector<std::pair<int, int>> south2;
    south2.push_back(std::pair<int, int> (10, 3));
    south2.push_back(std::pair<int, int> (6, 3));
    south2.push_back(std::pair<int, int> (3, 3));
    south2.push_back(std::pair<int, int> (5, 1));
    south2.push_back(std::pair<int, int> (2, 1));
    south2.push_back(std::pair<int, int> (0, 1));
    south2.push_back(std::pair<int, int> (6, 0));
    south2.push_back(std::pair<int, int> (4, 0));
    south2.push_back(std::pair<int, int> (1, 0));
    Hand south_hand2 = Hand(south2, 2);

    // West hand
    std::vector<std::pair<int, int>> west2;
    west2.push_back(std::pair<int, int> (12, 3));
    west2.push_back(std::pair<int, int> (4, 3));
    west2.push_back(std::pair<int, int> (10, 2));
    west2.push_back(std::pair<int, int> (1, 2));
    west2.push_back(std::pair<int, int> (9, 1));
    west2.push_back(std::pair<int, int> (7, 1));
    west2.push_back(std::pair<int, int> (4, 1));
    west2.push_back(std::pair<int, int> (12, 0));
    west2.push_back(std::pair<int, int> (22, 0));
    Hand west_hand2 = Hand(west2, 3);
    Deal test_deal_3 = Deal(north_hand2, east_hand2, south_hand2, west_hand2, 3, 3);
    data.push_back(test_deal_3);
  }
};

#endif