#ifndef QUEEN_H
#define QUEEN_H

#include "../piece.h"
namespace chess {
class Queen : public Piece {
public:
  Queen(const int &color);

  // Piece interface
public:
  std::string get_icon() const override;
  int get_role() const override;
  std::string get_role_str() const override;
};
}
#endif // QUEEN_H
