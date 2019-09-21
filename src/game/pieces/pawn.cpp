#include "pawn.h"

chess::Pawn::Pawn(const int &color) : Piece(color) {
  m_pseudo_legal_move_mask = Mask(PAWN, color);
}

std::string chess::Pawn::get_icon() const {
  return m_color == WHITE ? "♙" : "♟";
}

int chess::Pawn::get_role() const {
  return PAWN;
}

std::string chess::Pawn::get_role_str() const {
  return "pawn";
}
