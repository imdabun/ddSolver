#include <assert.h>
#include "../hand_class.hpp"

using namespace std;

int main()
{
  vector<pair<int, int>> cards;

  /* Q732 
   * AK43
   * 8
   * T987
   */
  cards.push_back(pair<int, int> (10, 3));
  cards.push_back(pair<int, int> (5, 3));
  cards.push_back(pair<int, int> (1, 3));
  cards.push_back(pair<int, int> (0, 3));
  cards.push_back(pair<int, int> (12, 2));
  cards.push_back(pair<int, int> (11, 2));
  cards.push_back(pair<int, int> (2, 2));
  cards.push_back(pair<int, int> (1, 2));
  cards.push_back(pair<int, int> (6, 1));
  cards.push_back(pair<int, int> (8, 0));
  cards.push_back(pair<int, int> (7, 0));
  cards.push_back(pair<int, int> (6, 0));
  cards.push_back(pair<int, int> (5, 0));


  cout << "Testing card_exists... " << endl;
  Hand test_hand = Hand(cards, 0);
  assert(test_hand.card_exists(5, 3));
  assert(test_hand.card_exists(12, 2));
  assert(!test_hand.card_exists(10, 2));
  cout << "Passed." << endl;

  cout << "Hand is:" << endl;
  for (auto &x: test_hand.all())
  {
    cout << x;
  }
  cout << endl;

  cout << "Removing all hearts." << endl;

  assert(test_hand.rem_card(12, 2));
  assert(test_hand.rem_card(11, 2));
  assert(test_hand.rem_card(2, 2));
  assert(test_hand.rem_card(1, 2));
  cout << endl;

  cout << "Hand is:" << endl;
  for (auto &x: test_hand.all())
  {
    cout << x;
  }
  cout << endl;

  cout << "Adding some new hearts." << endl;
  assert(test_hand.add_card(3, 2));
  assert(test_hand.add_card(4, 2));
  assert(test_hand.add_card(8, 2));
  assert(test_hand.add_card(9, 2));

  cout << "Hand is:" << endl;
  for (auto &x: test_hand.all())
  {
    cout << x;
  }
  cout << endl;
  
return 0;
}