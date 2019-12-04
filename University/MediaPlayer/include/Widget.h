/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED
#include <iostream>
#include <string>

class Widget {
 public:
  Widget() {}
  Widget(std::string n): name{n} {}
  Widget(std::string n,  unsigned int s): name{n}, size{s} {}
  virtual ~Widget() {}
  unsigned int getSize();
  std::string getName();
  virtual void printContent(int col) {
    std::cout << "|"
              << std::string(0, ' ')
              << getName() + " - Widget"
              << std::string(0, ' ')
              << "|" << (col == 0 ? "\n" : " ");
  }

  void printLines(int it);

 private:
  std::string name;
  unsigned int size = 8;// y of widget
  //write command variable thing here
};
#endif // WIDGET_H_INCLUDED
