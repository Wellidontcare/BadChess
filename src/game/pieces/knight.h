#ifndef KNIGHT_H
#define KNIGHT_H

#include "../piece.h"

namespace chess {

class Knight : public Piece {
public:
  explicit Knight(const int &color);

  // Piece interface
public:
  std::string get_icon() const override;
  int get_role() const override;
  std::string get_role_str() const override;
};
}

#endif // KNIGHT_H
