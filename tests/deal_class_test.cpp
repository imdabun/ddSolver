#include "test_deals.hpp"

using namespace std;

void print_deal(Deal deal)
{
  cout << "North hand: " << endl;
  cout << deal.hands[0] << endl;
  cout << "East hand: " << endl;
  cout << deal.hands[1] << endl;
  cout << "South hand: " << endl;
  cout << deal.hands[2] << endl;
  cout << "West hand: " << endl;
  cout << deal.hands[3] << endl;
}

int main()
{
  Test_deals deals = Test_deals();
  Deal test_deal_nt = deals.data[0];
  
  cout << "Deal loaded." << endl;
  print_deal(test_deal_nt);

  cout << "Playing SK 3 8 2" << endl;
  test_deal_nt.play_card(Card(11, 3, 0));
  test_deal_nt.play_card(Card(1, 3, 1));
  test_deal_nt.play_card(Card(6, 3, 2));
  test_deal_nt.play_card(Card(0, 3, 3));
  print_deal(test_deal_nt);

  cout << "Playing HJ Q K 7" << endl;
  test_deal_nt.play_card(Card(9, 2, 0));
  test_deal_nt.play_card(Card(10, 2, 1));
  test_deal_nt.play_card(Card(11, 2, 2));
  test_deal_nt.play_card(Card(5, 2, 3));
  print_deal(test_deal_nt);

  cout << "South is supposed to play now >> " << test_deal_nt.action << endl;
  cout << "Checking play_state >> " << test_deal_nt.play_state.to_play << endl;
  cout << "Unplay two cards: " << test_deal_nt.unplay_card() 
       << test_deal_nt.unplay_card() << endl;
  cout << "South is supposed to play now >> " << test_deal_nt.action << endl;
  cout << "Checking play_state >> " << test_deal_nt.play_state.to_play << endl;
  cout << "Using play_state to check missing cards >> " << endl;
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 13; ++j)
    {
      if (test_deal_nt.play_state.card_state(Card(j, i))) cout << j << "  " << i << endl;
    }
  }
  print_deal(test_deal_nt);

  cout << "Unplay two cards: " << test_deal_nt.unplay_card()
       << test_deal_nt.unplay_card() << endl;
  cout << "North is supposed to play now >> " << test_deal_nt.action << endl;
  cout << "Checking play_state >> " << test_deal_nt.play_state.to_play << endl;
  print_deal(test_deal_nt);
  cout << "curr_trick is supposed to be SK 3 8 2 >> " << endl;
  for (auto &x: test_deal_nt.curr_trick)
  {
    cout << x;
  }
  cout << "Unplaying all cards: " << endl;
  while (test_deal_nt.unplay_card())
  {
    cout << "1 card unplayed" << endl;
  }
  cout << "Testing a run of all cards. " << endl;
  
  while (test_deal_nt.tricks_left > 1)
  {
    vector<Card> moves;
    test_deal_nt.generate_moves(moves);
    cout << "Choice of plays are: " << endl;
    for (auto &x: moves)
    {
      cout << x;
    }
    cout << endl;
    test_deal_nt.play_card(moves.back());
  }
  cout << "Last trick is won by : " << test_deal_nt.last_trick() << endl;
  print_deal(test_deal_nt);

  cout << "Now we unplay everything. " << endl;
  int cards_unplayed = 0;
  while (test_deal_nt.unplay_card())
  {
    cout << "1 card unplayed" << endl;
    ++cards_unplayed;
  }
  cout << cards_unplayed << " cards unplayed." << endl;
  print_deal(test_deal_nt);
  cout << "Using play_state to check missing cards >> " << endl;
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 13; ++j)
    {
      if (test_deal_nt.play_state.card_state(Card(j, i))) cout << j << "  " << i << endl;
    }
  }
  cout << "play_state::to_play should be with north >> " << test_deal_nt.play_state.to_play << endl;
return 0;
}