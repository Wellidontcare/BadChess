#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"


namespace chess {

class knight : public Piece
{
public:
    knight(const int& color);

    // Piece interface
public:
    std::string get_icon() const;
    int get_role() const;
    std::string get_role_str() const;
};
}

#endif // KNIGHT_H
