#ifndef KING_H
#define KING_H
#include "../piece.h"

namespace chess
{

class King: public Piece
{
public:
    explicit King(const int &color);

    // Piece interface
public:
    std::string get_icon() const override;
    int get_role() const override;
    std::string get_role_str() const override;
};
}

#endif // KING_H
