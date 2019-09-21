#include "king.h"

chess::King::King(const int& color) : Piece(color)
{
m_pseudo_legal_move_mask = Mask(KING, color);
}

std::string chess::King::get_icon() const
{
    return m_color == WHITE ? "♔" : "♚";
}
