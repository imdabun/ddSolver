#include "../quick_tricks.hpp"
#include "test_deals.hpp"

using namespace std;

int main()
{
  Test_deals test;
  
  for (auto &x: test.data)
  {
    cout << "Deal info: Action>> " << x.action << " Trp >> " << x.trump << endl;

    cout << "Solving quick_tricks... " << endl;
    QT_Solver solver = QT_Solver(x);
    cout << "No. of quick tricks >> " << solver.qt() << endl << endl;
  }
return 0;
}