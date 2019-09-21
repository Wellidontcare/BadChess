#ifndef PAWN_H
#define PAWN_H
#include "../piece.h"

namespace chess {

class Pawn : public Piece
{
public:
    Pawn(const int& color);

    // Piece interface
public:
    std::string get_icon() const override;
    int get_role() const override;
    std::string get_role_str() const override;
};
}

#endif // PAWN_H
