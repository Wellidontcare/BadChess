//
// Created by joris on 09.08.19.
//
#pragma once
#include <vector>
#include <map>
#include "mask.h"

namespace chess {

class Piece {
protected:
  int m_color = NONE;
  Mask m_pseudo_legal_move_mask{};

public:
  virtual ~Piece() = 0;
  Piece(const int &color);
  virtual std::string get_icon() const = 0;
  virtual int get_role() const = 0;
  virtual std::string get_role_str() const = 0;
  int get_color() const;
  Mask get_mask() const;
  std::string get_color_str() const;
  void set_mask(const Mask &new_mask);
  bool empty() const;
};

//enum to string

} //chess
