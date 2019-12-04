/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Widget.h"
#include <iostream>
#include <string>

Widget::Widget(std::string n, unsigned int s);

unsigned int Widget::getSize() {
  return size;
}
std::string Widget::getName() {
  return name;
}
void Widget::printLines(int col) {
  int size = getName().length();
  int eq = (size/2)+1;
  int check = eq % 2;
  int nwidth;
  if (col <= 1) {
    if (check == 1) {
      nwidth = (size*2)+ 1;
    } else {
      nwidth = (size*2);
    }
    std::cout << "*" + std::string(nwidth, '-') + "*"<< (col <= 1 ? "\n" : " ");
  } else if (col == 2) {
    if (check == 1) {
      nwidth = size + 1;
    } else {
      nwidth = size;
    }
    std::cout << "*" + std::string(nwidth, '-') <<
     "*"<< (col == 2 ? " " : "\n ");
  } else {
    std::cout << "Lol" << std::endl;
  }
}

