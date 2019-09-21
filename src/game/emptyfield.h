#ifndef EMPTYFIELD_H
#define EMPTYFIELD_H

#include "Piece.h"
namespace chess {

class EmptyField : public chess::Piece
{
// Piece interface
public:
    EmptyField();
    std::string get_icon() const;
    int get_role() const;
    std::string get_role_str() const;
};
}

#endif // EMPTYFIELD_H
