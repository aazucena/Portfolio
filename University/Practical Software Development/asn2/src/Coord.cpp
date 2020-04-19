/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Coordinate.h"
using namespace std;
bool Coordinate::operator==(const Coordinate& c) const {
  return (x == c.x && y == c.y);
}
bool Coordinate::operator!=(const Coordinate& c) const {
  return (x != c.x || y != c.y);
}
ostream&operator<<(ostream& os, const Coordinate& c) {
  os << "[" << c.x << "," << c.y << "]";
  return os;
}
