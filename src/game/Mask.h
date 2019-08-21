//
// Created by joris on 09.08.19.
//

#ifndef _MASK_H_
#define _MASK_H_
#include <vector>
namespace chess {

enum {
  ROOK,
  KNIGHT,
  BISHOP,
  QUEEN,
  KING,
  PAWN,
  EMPTY
};

enum {
  WHITE,
  BLACK,
  NONE
};
//a mask that contains the valid move pattern for a chess piece in an array
class Mask {
public:
  Mask(const int &role, const int &color);
  Mask(std::vector<int> mask, const int &width, const int &height);
  Mask() = default;
  int width() const;
  int height() const;
  int &operator[](const int &index);
  int operator[](const int &index) const;
private:
  std::vector<int> m_mask{};
  int m_width = 0;
  int m_height = 0;
};
} //namespace chess

#endif //_MASK_H_
