#include "movemessage.h"

std::string InvalidMoveMessageNoMovement::get_message() {
  return "Staying in the same place from where you started is not legal! This action will be reported <3";
}

bool InvalidMoveMessageNoMovement::is_valid_move() {
  return false;
}

std::string InvalidMoveMessageNothingMoved::get_message() {
  return "You can't move nothing dummy <3";
}

bool InvalidMoveMessageNothingMoved::is_valid_move() {
  return false;
}

InvalidMoveMessageWrongColor::InvalidMoveMessageWrongColor(const std::shared_ptr<chess::Piece> &selected_piece)
    : MoveMessage(selected_piece) {}

std::string InvalidMoveMessageWrongColor::get_message() {
  return "You can't move that "
      + m_selected_piece->get_color_str() + " "
      + m_selected_piece->get_role_str()
      + ". It has the wrong color sweetheart <3";
}

bool InvalidMoveMessageWrongColor::is_valid_move() {
  return false;
}

MoveMessage::MoveMessage(std::shared_ptr<chess::Piece> selected_piece) : m_selected_piece(std::move(selected_piece)) {}

MoveMessage::MoveMessage(std::shared_ptr<chess::Piece> selected_piece,
                         std::shared_ptr<chess::Piece> taken_piece,
                         std::string from,
                         std::string to)
    : m_selected_piece(std::move(selected_piece)), m_taken_piece(std::move(taken_piece)), m_from(std::move(from)), m_to(std::move(to)) {}

MoveMessage::MoveMessage(std::shared_ptr<chess::Piece> selected_piece, std::string from, std::string to)
    : m_selected_piece(std::move(selected_piece)), m_from(std::move(from)), m_to(std::move(to)) {}
bool MoveMessage::is_valid_move() {
  return false;
}
std::string MoveMessage::get_message() {
  return " ";
}

InvalidMoveMessageOutsideOfBoard::InvalidMoveMessageOutsideOfBoard(const std::shared_ptr<chess::Piece> &selected_piece)
    : MoveMessage(selected_piece) {}

bool InvalidMoveMessageOutsideOfBoard::is_valid_move() {
  return false;
}

std::string InvalidMoveMessageOutsideOfBoard::get_message() {
  return "You can't move that "
      + m_selected_piece->get_color_str() + " "
      + m_selected_piece->get_role_str()
      + ". It would be outside of the board darling <3";
}

InvalidMoveMessageOutOfRange::InvalidMoveMessageOutOfRange(const std::shared_ptr<chess::Piece> &selected_piece)
    : MoveMessage(selected_piece) {}

bool InvalidMoveMessageOutOfRange::is_valid_move() {
  return false;
}

std::string InvalidMoveMessageOutOfRange::get_message() {
  return "You can't move that "
      + m_selected_piece->get_color_str() + " "
      + m_selected_piece->get_role_str()
      + ". This piece can't move that far honey <3";
}

InvalidMoveMessageIllegalMove::InvalidMoveMessageIllegalMove(const std::shared_ptr<chess::Piece> &selected_piece)
    : MoveMessage(selected_piece) {}

bool InvalidMoveMessageIllegalMove::is_valid_move() {
  return false;
}

std::string InvalidMoveMessageIllegalMove::get_message() {
  return "You can't move that "
      + m_selected_piece->get_color_str() + " "
      + m_selected_piece->get_role_str()
      + ". This is not a valid move for this piece sugar <3";
}

bool InvalidMoveMessageCollision::is_valid_move() {
  return false;
}

std::string InvalidMoveMessageCollision::get_message() {
  return "There is a piece in the way my dear ¯\\_(^-^)_/¯";
}

bool ValidMoveMessage::is_valid_move() {
  return true;
}

bool ValidMoveMessageEnPassant::is_valid_move() {
  return true;
}

std::string ValidMoveMessageEnPassant::get_message() {
  return "Nice move, you took that pawn en passant :)\n";
}

ValidMoveMessagePieceTaken::ValidMoveMessagePieceTaken(const std::shared_ptr<chess::Piece> &selected_piece,
                                                       const std::shared_ptr<chess::Piece> &taken_piece,
                                                       const std::string &from,
                                                       const std::string &to)
    : MoveMessage(selected_piece, taken_piece, from, to) {}

bool ValidMoveMessagePieceTaken::is_valid_move() {
  return true;
}

std::string ValidMoveMessagePieceTaken::get_message() {
  return "The " + m_selected_piece->get_color_str() + " "
      + m_selected_piece->get_role_str() + " moved from " + m_from + " to " + m_to + " "
      + "and took the "
      + m_taken_piece->get_color_str() + " "
      + m_taken_piece->get_role_str() + "!\n";
}

ValidMoveMessageJustMoved::ValidMoveMessageJustMoved(const std::shared_ptr<chess::Piece> &selected_piece,
                                                     const std::string &from,
                                                     const std::string &to)
    : MoveMessage(selected_piece, from, to) {}

bool ValidMoveMessageJustMoved::is_valid_move() {
  return true;
}

std::string ValidMoveMessageJustMoved::get_message() {
  return "The " + m_selected_piece->get_color_str() + " "
      + m_selected_piece->get_role_str() + " moved from " + m_from + " to " + m_to + "\n";
}
