#ifndef ROOK_H
#define ROOK_H
#include "../piece.h"
namespace chess {

class Rook : public Piece
{
public:
    Rook(const int& color);
    std::string get_icon() const override;
    std::string get_role_str() const override;
    int get_role() const override;
    ~Rook() override;
};
}

#endif // ROOK_H