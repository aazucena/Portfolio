/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Display.h"
#include <iostream>
#include <iomanip>
#include <string>
void Display::printContent(int col) {
  int size = getName().length();
  int eq = (size/2)+1;
  int check = eq % 2;
  int nwidth;
  if (check == 1) {
    nwidth = (size*2)+ 3;
  } else {
    nwidth = (size*2);
  }
  for (int k = 0; k < getSize(); k++) {
    std::cout << "|"
              << std::string(nwidth, 'D')
              << "|" << (col <= 1 ? "\n" : " ");
  }
}
