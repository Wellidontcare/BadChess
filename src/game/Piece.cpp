//
// Created by joris on 09.08.19.
//

#include "Piece.h"

namespace chess {
Piece::Piece(const int &color, const int &role)
    : m_color(color), m_role(role) {
  //sets the representing unicode chars for each piece
  switch (role) {
  case ROOK: {
    m_pseudo_legal_move_mask = Mask(role, color);
    m_representing_char = color == BLACK ? "♖" : "♜";
    break;
  }
  case BISHOP: {
    m_pseudo_legal_move_mask = Mask(role, color);
    m_representing_char = color == BLACK ? "♗" : "♝";
    break;
  }
  case QUEEN: {
    m_pseudo_legal_move_mask = Mask(role, color);
    m_representing_char = color == BLACK ? "♕" : "♛";
    break;
  }
  case KNIGHT: {
    m_pseudo_legal_move_mask = Mask(role, color);
    m_representing_char = color == BLACK ? "♘" : "♞";
    break;
  }
  case PAWN: {
    m_pseudo_legal_move_mask = Mask(role, color);
    m_representing_char = color == BLACK ? "♙" : "♟";
    break;
  }
  case KING: {
    m_pseudo_legal_move_mask = Mask(role, color);
    m_representing_char = color == BLACK ? "♔" : "♚";
    break;
  }
  default: {
    m_representing_char = " ";
  }
  }
}
int Piece::get_color() const {
  return m_color;
}
std::string Piece::get_icon() const {
  return m_representing_char;
}
Mask Piece::get_mask() const {
  return m_pseudo_legal_move_mask;
}
int Piece::get_role() const {
  return m_role;
}
void Piece::set_mask(const Mask &new_mask) {
  m_pseudo_legal_move_mask = new_mask;
}
std::string Piece::get_role_str() const {
  return role_to_string_lut.at(m_role);
}
std::string Piece::get_color_str() const {
  return color_to_string_lut.at(m_color);
}

bool Piece::empty() const {
  return m_role == EMPTY;
}

const std::map<int, std::string> chess::Piece::role_to_string_lut = {{ROOK, "rook"},
                                                                     {KNIGHT, "knight"},
                                                                     {BISHOP, "bishop"},
                                                                     {QUEEN, "queen"},
                                                                     {PAWN, "pawn"},
                                                                     {KING, "king"}};
const std::map<int, std::string>
    chess::Piece::color_to_string_lut = {{BLACK, "black"}, {WHITE, "white"}, {NONE, "null"}};

} //chess