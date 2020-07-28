# Introduction
This is an attempt to create my own double dummy solver for bridge, based on principles highlighted in the following papers:\
[Chang 1996](https://pdfs.semanticscholar.org/eed7/025c0ab6e5f693dff53ed7cf2605aa10d768.pdf "Building a Fast Double-Dummy Bridge Solver")\
[Bo Haglund, Soren Hein](http://privat.bahnhof.se/wb758135/bridge/Alg-dds_x.pdf "Search Algorithms for a Bridge Double Dummy Solver")\
The motivation for the project is due to my inability to create a solver that produces an accurate result in a reasonable time for a bridge application I wrote a year ago. 

# Usage
The simplest way to use this solver is to type out a hand following the format highlighted in *.\tests\deals\parser_format.txt*, adding above line 13 of *.\tests\test_deals.cpp*:
```
  deal_loading(data, "./tests/deals/<test_file_name>.txt");
```
After which, compile *.\tests\solver_test.cpp*, e.g.
```
  g++ -std=c++11 .\tests\solver_test.cpp .\src\*.cpp
```

# Files
## Data Structures
Simple data structures for cards, hands and deals contain methods needed to change the state of a deal, and are changed instead of copied for all search operations. Broken down into:
* card_class.hpp
* hand_class.hpp
* deal_class.hpp 

## Quick Tricks
Implementation of "quick_tricks" is used to identify the number of tricks the player on lead can surely win. This provides a lower bound on the goal that is possible to reach for each call to *ddSearch*.

## Later Tricks
At any point when at least one card has been played, check if a player can win this trick by rank for sure and calculate the number of quick tricks possible by that player. This provides an upper or lower bound for current call to *ddSearch*.

Not used in the current solver as the overhead needed to calculate the result exceeds the time saved from pruning.

## Tests
Small test cases run key functions of each feature

# Algorithms
The basic search algorithm highlighted in Chang's paper is used as a main structure.

Various functions noted in the 2014 document are needed for the search to be done in a reasonable time:
* Target too low or high :heavy_check_mark:
* Quick-Tricks :heavy_check_mark:
* Tranposition Table :x:
* MoveOrdering :x:
* 
With current implementation, simpler full hands such *.\tests\deals\07.txt* can be solved in a reasonable amount of time, while most 8-card hands are solvable within 1~2 seconds.

# Future Development
This project is done as an exercise to familiarize myself with bridge search and pruning techniques. One technique to shorten solve time that is not used in the modern iteration of DDS is the single-suit lookup table as suggested in [Chang 1996](https://pdfs.semanticscholar.org/eed7/025c0ab6e5f693dff53ed7cf2605aa10d768.pdf "Building a Fast Double-Dummy Bridge Solver").

This idea involves pre-compiling a lookup table of single suit distributions alongside with information such as controls and entries to get a tighter bound for *ddSearch*. This can be extended to *techniques*, where positions such as finesses, simple endplays, crossruffs, etc. can be identified and cached for quick lookup.