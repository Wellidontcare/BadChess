//
// Created by joris on 09.08.19.
//

#ifndef _PIECE_H_
#define _PIECE_H_
#include <vector>
#include <map>
#include "Mask.h"

namespace chess {

class Piece {
private:
  int m_color = NONE;
  int m_role = EMPTY;
  Mask m_pseudo_legal_move_mask{};
  std::string m_representing_char = " ";
  const static std::map<int, std::string> role_to_string_lut;
  const static std::map<int, std::string> color_to_string_lut;

public:
  Piece() = default;
  Piece(const int &color, const int &role);
  int get_color() const;
  std::string get_icon() const;
  Mask get_mask() const;
  int get_role() const;
  std::string get_role_str() const;
  std::string get_color_str() const;
  void set_mask(const Mask &new_mask);
  bool empty() const;
};

//enum to string

} //chess
#endif //_PIECE_H_
