#include "chesspiecefactory.h"

std::shared_ptr<chess::Piece> chess::ChessPieceFactory::make(const int &color, const int &role) {
  switch (role) {
  case ROOK:return std::make_shared<Rook>(Rook(color));
  case KNIGHT:return std::make_shared<Knight>(Knight(color));
  case BISHOP:return std::make_shared<Bishop>(Bishop(color));
  case QUEEN:return std::make_shared<Queen>(Queen(color));
  case KING:return std::make_shared<King>(King(color));
  case PAWN:return std::make_shared<Pawn>(Pawn(color));
  default:return std::make_shared<EmptyField>(EmptyField());
  }
}
