/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "Widget.h"
#include <iostream>
#include <iomanip>
#include <string>
class Display: public Widget {
 public:
  Display(std::string dn): Widget{dn} {}
  Display(std::string dn, unsigned int ds): Widget{dn, ds} {}
  virtual ~Display() {}
  void printContent(int col);
 private:
};
#endif // DISPLAY_H_INCLUDED
