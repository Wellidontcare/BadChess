#include "rook.h"

chess::Rook::Rook(const int &color)
    : Piece(color)
{
    m_pseudo_legal_move_mask = Mask(ROOK, color);
}

std::string chess::Rook::get_icon() const
{
    return m_color == WHITE ? "♜" : "♖";
}

std::string chess::Rook::get_role_str() const
{
    return "rook";
}

int chess::Rook::get_role() const
{
    return ROOK;
}

