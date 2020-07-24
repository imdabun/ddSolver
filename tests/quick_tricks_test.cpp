#include "../quick_tricks.hpp"
#include "test_deals.hpp"

using namespace std;

int main()
{
  cout << "Loading test deal 1" << endl;
  Test_deals deals = Test_deals();
  Deal test_deal_nt = deals.data[0];
  cout << "Deal loaded." << endl;

  cout << "Solving quick_tricks... " << endl;

  QT_Solver solver = QT_Solver(test_deal_nt);
  cout << "No. of quick tricks >> " << solver.friendly_QT() << endl;
return 0;
}

// Pending more tests