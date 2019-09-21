#ifndef EMPTYFIELD_H
#define EMPTYFIELD_H

#include "../piece.h"
namespace chess {

class EmptyField : public chess::Piece
{
// Piece interface
public:
    EmptyField();
    std::string get_icon() const override;
    int get_role() const override;
    std::string get_role_str() const override;
};
}

#endif // EMPTYFIELD_H
