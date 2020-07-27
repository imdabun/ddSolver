#ifndef TEST_DEALS_H
#define TEST_DEALS_H

#include "../deal_parser.hpp"

class Test_deals
{
public:
  std::vector<Deal> data;

  Test_deals()
  {
    deal_loading(data, "./tests/test/01.txt");
    deal_loading(data, "./tests/test/02.txt");
    deal_loading(data, "./tests/test/03.txt");
    deal_loading(data, "./tests/test/04.txt");
    deal_loading(data, "./tests/test/05.txt");
    deal_loading(data, "./tests/test/06.txt");
  }
};

#endif