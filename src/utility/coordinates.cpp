//
// Created by joris on 17.08.19.
//

#include "coordinates.h"

bool Coordinates::operator==(const Coordinates &other) const
{
    return (other.x == this->x && other.y == this->y);
}
bool Coordinates::operator!=(const Coordinates &other) const
{
    return !this->operator==(other);
}
Coordinates Coordinates::operator-(const Coordinates &other) const
{
    return {this->x - other.x, this->y - other.y};
}
Coordinates Coordinates::operator+(const Coordinates &other) const
{
    return {this->x + other.x, this->y + other.y};
}
Coordinates Coordinates::operator-() const
{
    return {-this->x, -this->y};
}
Coordinates Coordinates::operator+=(const Coordinates &other)
{
    *this = *this + other;
    return *this;
}
Coordinates Coordinates::operator-=(const Coordinates &other)
{
    *this = *this - other;
    return *this;
}
