//
// Created by joris on 09.08.19.
//

#ifndef _BOARD_H_
#define _BOARD_H_
#include <algorithm>
#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "MoveMessage.h"
#include "Piece.h"
#include "../utility/Grid.hpp"
#include "../utility/Coordinates.h"
#include "../utility/Input.h"

namespace chess {
const int BOARD_SIZE = 64;
const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 8;

class Board {
private:
  Grid2d<chess::Piece> m_board_matrix;
  std::vector<Piece> m_taken_pieces;
  void set_piece(const int &x, const int &y, const chess::Piece &piece);

  //game logic
  MoveMessage valid_move(const Coordinates &from,
                         const Coordinates &to,
                         const int &current_turn_color) const;
  bool en_passant(Piece &selected_piece, Piece &left_piece, Piece &right_piece);
  bool collides(const Coordinates &from, const Coordinates &to) const;
  static bool correct_color(const int &current_turn_color, const Piece &piece);
  static bool inside_board(const Coordinates &to);
  static bool inside_mask(const int &d_x, const int &d_y, const Piece &piece);
  static bool on_move_mask(const int &d_x, const int &d_y, const Piece &piece, const bool &takes_piece);

public:
  Board();

  //Draw the board
  void show();
  MoveMessage move_piece(const std::string &from, const std::string &to, const int &current_turn_color);
  std::vector<Piece> taken_pieces() const;
};

}
#endif //_BOARD_H_
