/*
*CPSC 2720 Fall 2019
*Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Coordinate.h"
#include "Widget.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
using namespace std;
Widget::Widget(Coordinate c, unsigned int w, unsigned int h): location{c}, width{w},
  height{h} {
  if (w <= 0 || h <= 0 ) {
    throw illegal_size_error("The width and height are zero!");
  }
}
bool Widget::locatedAt(Coordinate c) {
  int yLimit = getLocation().y + getHeight();
  int xLimit = getLocation().x + getWidth();
  if (c.x <= xLimit && c.y <= yLimit && c.x >= getLocation().x
      && c.y >= getLocation().y) {
    return true;
  } else {
    return false;
  }
}
unsigned int Widget::getWidth() {
  return width;
}
unsigned int Widget::getHeight() {
  return height;
}
Coordinate Widget::getLocation() {
  return location;
}
void Widget::checkOutOfBounds(Coordinate c) {
  if (c.x > getWidth() || c.y > getHeight()) {
    throw widget_error("The coordinate you scanned is out of bounds");
  }
}
