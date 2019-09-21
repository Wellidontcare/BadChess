//
// Created by joris on 09.08.19.
//

#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "movemessage.h"
#include "piece.h"
#include "../utility/grid.hpp"
#include "../utility/coordinates.h"
#include "../utility/input.h"
#include "chesspiecefactory.h"

namespace chess {
const int BOARD_SIZE = 64;
const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 8;

class Board {
private:
  Grid2d<std::shared_ptr<Piece>> m_board_matrix;
  std::vector<std::shared_ptr<Piece>> m_taken_pieces;
  void set_piece(const int &x, const int &y, const std::shared_ptr<Piece>& piece);

  //game logic
  MoveMessage valid_move(const Coordinates &from,
                         const Coordinates &to,
                         const int &current_turn_color) const;
  bool en_passant(const std::shared_ptr<Piece>& selected_piece, const std::shared_ptr<Piece>& left_piece, const std::shared_ptr<Piece>& right_piece);
  bool collides(const Coordinates &from, const Coordinates &to) const;
  static bool correct_color(const int &current_turn_color, const std::shared_ptr<Piece>& piece);
  static bool inside_board(const Coordinates &to);
  static bool inside_mask(const int &d_x, const int &d_y, const std::shared_ptr<Piece>& piece);
  static bool on_move_mask(const int &d_x, const int &d_y, const std::shared_ptr<Piece>& piece, const bool &takes_piece);

public:
  Board();

  //Draw the board
  void show();
  MoveMessage move_piece(const std::string &from, const std::string &to, const int &current_turn_color);
  std::vector<std::shared_ptr<Piece>> taken_pieces() const;
};

}
