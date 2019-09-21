#ifndef BISHOP_H
#define BISHOP_H
#include "../piece.h"
namespace chess {

class Bishop : public Piece
{
public:
    Bishop(const int& color);

    // Piece interface
public:
    std::string get_icon() const override;
    int get_role() const override;
    std::string get_role_str() const override;
};
}

#endif // BISHOP_H
