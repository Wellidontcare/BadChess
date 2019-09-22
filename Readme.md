## A game of chess for the console written in C++.

This is an early version. Currently winning is only possible by taking the enemies king.
There might be some errors that need fixing.

###### Currently (more or less) working:
- Drawing of unicode chess board
- Parsing of input
- Info about last taken action
- Movement logic for all pieces
- en passant

###### Plans for the future:
- add a proper check for mate
- check if the king is under attack
- make castling possible
- promotion of pawns that reach the opposing home row

Project can be build via CMAKE (minimum version 3.5) and should be portable (you need a compatible font DejaVu Sans Mono works) - no external dependencies are required.