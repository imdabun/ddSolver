# Introduction
This is an attempt to create my own double dummy solver for bridge, based on principles highlighted in the following papers:\
[Chang 1996](https://pdfs.semanticscholar.org/eed7/025c0ab6e5f693dff53ed7cf2605aa10d768.pdf "Building a Fast Double-Dummy Bridge Solver")\
[Bo Haglund, Soren Hein](http://privat.bahnhof.se/wb758135/bridge/Alg-dds_x.pdf "Search Algorithms for a Bridge Double Dummy Solver")

# Data structures
Simple data structures for cards, hands and deals contain methods needed to change the state of a deal, and are changed instead of copied for all search operations. Broken down into:
* card_class.hpp
* hand_class.hpp
* deal_class.hpp 

Organized for my own convenience, each with my own tests under ./tests

# Algorithms
The basic search algorithm highlighted in Chang's paper is used as a main structure.\
Various functions noted in the 2014 document are needed for the search to be done in a reasonable time. They are:
* Target too low or high :heavy_check_mark:
* Quick-Tricks/Later-Tricks :white_check_mark:
* Tranposition Table :white_check_mark:
* MoveOrdering :white_check_mark: