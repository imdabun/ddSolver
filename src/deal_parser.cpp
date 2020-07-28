#include "deal_parser.hpp"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int parse_val(string s)
{
  if (s == "A") return 12;
  if (s == "K") return 11;
  if (s == "Q") return 10;
  if (s == "J") return 9;
  if (s == "T") return 8;
  else
    return stoi(s) - 2;
}

void deal_loading(std::vector<Deal>& target, std::string file_name)
{
  int to_play, trump;
  string line;
  ifstream deal_src;
  deal_src.open(file_name);
  if (!deal_src) {
    cerr << "Unable to open file datafile.txt";
    exit(1);   // call system to stop
  }
  deal_src >> to_play;
  deal_src >> trump;

  deal_src.ignore(1000, '\n');
  deal_src.ignore(1000, '\n');

  // North
  vector<pair<int, int>> north_cards;
  for (int suit = 3; suit > -1; --suit)
  {
    getline(deal_src, line);
    istringstream iss(line);
    for (string s; iss >> s;)
    {
      north_cards.push_back(pair<int, int> (parse_val(s), suit));
    } 
  }
  Hand north_hand(north_cards, 0);
  deal_src.ignore(1000, '\n');

  // East
  vector<pair<int, int>> east_cards;
  for (int suit = 3; suit > -1; --suit)
  {
    getline(deal_src, line);
    istringstream iss(line);
    for (string s; iss >> s;)
      east_cards.push_back(pair<int, int> (parse_val(s), suit));
  }
  Hand east_hand(east_cards, 1);
  deal_src.ignore(1000, '\n');

  // South
  vector<pair<int, int>> south_cards;
  for (int suit = 3; suit > -1; --suit)
  {
    getline(deal_src, line);
    istringstream iss(line);
    for (string s; iss >> s;)
      south_cards.push_back(pair<int, int> (parse_val(s), suit));
  }
  Hand south_hand(south_cards, 2);
  deal_src.ignore(1000, '\n');
  
  // West
  vector<pair<int, int>> west_cards;
  for (int suit = 3; suit > -1; --suit)
  {
    getline(deal_src, line);
    istringstream iss(line);
    for (string s; iss >> s;)
      west_cards.push_back(pair<int, int> (parse_val(s), suit));
  }
  Hand west_hand(west_cards, 3);
  
  target.push_back( Deal(north_hand, east_hand, south_hand, west_hand, 
                    to_play, trump));
  deal_src.close();
}