#include "emptyfield.h"

chess::EmptyField::EmptyField()
    : Piece(EMPTY_COLOR)
{}

std::string chess::EmptyField::get_icon() const
{
    return " ";
}

int chess::EmptyField::get_role() const
{
    return EMPTY_ROLE;
}

std::string chess::EmptyField::get_role_str() const
{
    return " ";
}
