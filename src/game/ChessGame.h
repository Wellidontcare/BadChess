//
// Created by joris on 17.08.19.
//

#ifndef _CHESSGAME_H_
#define _CHESSGAME_H_
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

#endif //_CHESSGAME_H_
