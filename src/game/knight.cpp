#include "knight.h"

chess::knight::knight(const int &color) : Piece(color) {
    m_pseudo_legal_move_mask = Mask(KNIGHT, color);
}

std::string chess::knight::get_icon() const
{
    return m_color == WHITE ? "♘" : "♞";
}

int chess::knight::get_role() const
{
    return KNIGHT;
}

std::string chess::knight::get_role_str() const
{
    return "knight";
}
