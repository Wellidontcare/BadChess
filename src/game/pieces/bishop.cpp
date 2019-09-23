#include "bishop.h"

chess::Bishop::Bishop(const int &color)
    : Piece(color)
{
    m_pseudo_legal_move_mask = Mask(BISHOP, color);
}

std::string chess::Bishop::get_icon() const
{
    return m_color == WHITE ? "♝" : "♗";
}

int chess::Bishop::get_role() const
{
    return BISHOP;
}

std::string chess::Bishop::get_role_str() const
{
    return "bishop";
}
