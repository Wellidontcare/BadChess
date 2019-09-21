//
// Created by joris on 17.08.19.
//

#pragma once
#include "Board.h"

//TODO inplement proper game over logic
//TODO check for chess and chess mate
namespace chess {
class ChessGame {
private:
  Board m_board;
  bool check_game_over();
public:
  void run();
};
}//chess
