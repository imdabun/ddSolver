#ifndef TEST_DEALS_H
#define TEST_DEALS_H

#include "../src/deal_parser.hpp"

class Test_deals
{
public:
  std::vector<Deal> data;

  Test_deals()
  {
    deal_loading(data, "./tests/deals/07.txt");
  }
};

#endif