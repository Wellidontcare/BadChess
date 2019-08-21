//
// Created by joris on 17.08.19.
//

#ifndef BADCHESS_SRC_COORDINATES_H
#define BADCHESS_SRC_COORDINATES_H
struct Coordinates {
  int x;
  int y;
  bool operator==(const Coordinates& other) const;
  bool operator!=(const Coordinates& other) const;
  Coordinates operator-(const Coordinates& other) const;
  Coordinates operator+(const Coordinates& other) const;
  Coordinates operator-() const;
  Coordinates operator+=(const Coordinates& other);
  Coordinates operator-=(const Coordinates& other);
};

#endif //BADCHESS_SRC_COORDINATES_H
