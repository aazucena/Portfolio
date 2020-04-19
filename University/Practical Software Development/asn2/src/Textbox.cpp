/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Textbox.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
Textbox::~Textbox() {}
char Textbox::getAt(Coordinate c) {
  if (c.x <= getWidth() && c.y <= getHeight()) {
    return contents[c.y][c.x];
  } else {
    Textbox::checkOutOfBounds(c);
  }
}
void Textbox::setText(const string s) {
  //dynamic allocation
  contents = new char*[getHeight()];
  int sSize = 0; // for purposes of counting and not repeating characters
  for (int i = 0; i < getHeight(); i++) {
    contents[i] = new char[getWidth()];
  }
  //input values to dynamic 2d array
  for (int i =0; i < getHeight(); i++) {
    for (int j =0; j < getWidth(); j++) {
      if (sSize < s.size()) {
        contents[i][j] = s[sSize++];
      } else {
        contents[i][j] = ' ';
      }
    }
  }
  if (s.size() > (getWidth()*getHeight())) {
    throw widget_error("Text can't fit in the textbox.");
  }
}



