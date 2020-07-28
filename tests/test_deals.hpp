#ifndef TEST_DEALS_H
#define TEST_DEALS_H

#include "../deal_parser.hpp"

class Test_deals
{
public:
  std::vector<Deal> data;

  Test_deals()
  {
    deal_loading(data, "./tests/deals/01.txt");
    deal_loading(data, "./tests/deals/02.txt");
    deal_loading(data, "./tests/deals/03.txt");
    deal_loading(data, "./tests/deals/04.txt");
    deal_loading(data, "./tests/deals/05.txt");
    deal_loading(data, "./tests/deals/06.txt");
    deal_loading(data, "./tests/deals/07.txt");
  }
};

#endif