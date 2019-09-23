//
// Created by joris on 09.08.19.
//

#include "piece.h"

namespace chess
{
Piece::~Piece() = default;

Piece::Piece(const int &color)
    : m_color(color)
{}

int Piece::get_color() const
{
    return m_color;
}

Mask Piece::get_mask() const
{
    return m_pseudo_legal_move_mask;
}

std::string Piece::get_color_str() const
{
    return m_color == BLACK ? "black" : "white";
}

void Piece::set_mask(const Mask &new_mask)
{
    m_pseudo_legal_move_mask = new_mask;
}

bool Piece::empty() const
{
    return m_color == EMPTY_COLOR;
}

} //chess
