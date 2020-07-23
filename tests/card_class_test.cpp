#include "../card_class.hpp"

using namespace std;

int main()
{
  cout << "Testing card_class" << endl << endl;
  
  vector<Card> cards;

  Card heart_five = Card(3, 2, 3);

  Card dime_ace = Card(12, 1, 2);

  Card club_eight = Card(6, 0, 1);

  Card club_nine = Card(7, 0, 0);

  for (int v = 0; v < 13; ++v)
  {
    for (int s = 0; s < 4; ++s)
    {
      Card new_card = Card(v, s);
      cout << "New card created: " << new_card;
      cards.push_back(new_card);
      cout << "Is it larger than heart 5? " << (new_card > heart_five) << endl;
      cout << "Is it smaller than dime A? " << (new_card < dime_ace) << endl;
    }
  }

  cards.clear();
  cards.push_back(club_eight);
  cards.push_back(club_nine);
  cards.push_back(dime_ace);
  cards.push_back(heart_five);

  cout << "Winner of the trick is player " << trick_winner(cards, 2) << endl;
return 0;
}