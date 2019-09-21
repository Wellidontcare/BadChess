#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
namespace chess {

class Bishop : public Piece
{
public:
    Bishop(const int& color);

    // Piece interface
public:
    std::string get_icon() const;
    int get_role() const;
    std::string get_role_str() const;
};
}

#endif // BISHOP_H
