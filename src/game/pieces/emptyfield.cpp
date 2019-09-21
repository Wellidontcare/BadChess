#include "emptyfield.h"

chess::EmptyField::EmptyField() : Piece(NONE){}

std::string chess::EmptyField::get_icon() const
{
    return " ";
}

int chess::EmptyField::get_role() const
{
    return EMPTY;
}

std::string chess::EmptyField::get_role_str() const
{
    return " ";
}
