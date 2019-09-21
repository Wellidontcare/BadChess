#include "queen.h"

chess::Queen::Queen(const int& color) : Piece(color)
{
    m_pseudo_legal_move_mask = Mask(QUEEN, color);
}

std::string chess::Queen::get_icon() const
{
    return m_color == WHITE ? "♕" : "♛";
}

std::string chess::Queen::get_role_str() const
{
    return "queen";
}
