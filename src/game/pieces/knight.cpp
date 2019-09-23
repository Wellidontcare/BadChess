#include "knight.h"

chess::Knight::Knight(const int &color)
    : Piece(color)
{
    m_pseudo_legal_move_mask = Mask(KNIGHT, color);
}

std::string chess::Knight::get_icon() const
{
    return m_color == WHITE ? "♞" : "♘";
}

int chess::Knight::get_role() const
{
    return KNIGHT;
}

std::string chess::Knight::get_role_str() const
{
    return "knight";
}
