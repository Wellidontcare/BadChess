//
// Created by joris on 09.08.19.
//
#pragma once
#include <vector>
namespace chess
{

enum
{
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    PAWN,
    EMPTY_ROLE
};

enum
{
    WHITE,
    BLACK,
    EMPTY_COLOR
};
//a mask that contains the valid move pattern for a chess piece in an array
class Mask
{
public:
    Mask(const int &role, const int &color);
    Mask(std::vector<int> mask, const int &width, const int &height);
    Mask() = default;
    int width() const;
    int height() const;
    int &operator[](const size_t &index);
    int operator[](const size_t &index) const;
private:
    std::vector<int> m_mask{};
    int m_width = 0;
    int m_height = 0;
};
} //namespace chess
