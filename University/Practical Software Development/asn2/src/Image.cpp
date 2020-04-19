/*
*CPSC 2720 Fall 2019
*Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Image.h"
#include "Coordinate.h"
using namespace std;
char Image::getAt(Coordinate c) {
  Image::checkOutOfBounds(c);
  return 'I';
}
