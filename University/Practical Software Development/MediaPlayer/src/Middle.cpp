/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Middle.h"
#include "Widget.h"
#include "Button.h"
#include "Display.h"
#include <iostream>
#include <vector>

void Middle::initModel() {
  Button b1("Play");
  Button b2("Rewind");
  Button b3("Forward");
  Display d("Display", 8);
  Button b4("Change Mode");
  Button b5("Pause");
  Middle::addWidget(&b1);
  Middle::addWidget(&b2);
  Middle::addWidget(&b3);
  Middle::addWidget(&d);
  Middle::addWidget(&b4);
  Middle::addWidget(&b5);
  printModel();
}
void Middle::printModel() {
  for (int j = 0; j < 1; j++) {
////////////////////////
    getWidgets()[0]->printLines(1);
    getWidgets()[0]->printContent(1);
    getWidgets()[0]->printLines(1);
////////////////////////////////////////
    getWidgets()[1]->printLines(2);
    getWidgets()[2]->printLines(2);
    std::cout << std::endl;
    getWidgets()[1]->printContent(2);
    getWidgets()[2]->printContent(2);
    std::cout << std::endl;
    getWidgets()[1]->printLines(2);
    getWidgets()[2]->printLines(2);
    std::cout << std::endl;
//////////////////////////////////////////
    getWidgets()[3]->printLines(1);
    getWidgets()[3]->printContent(1);
    getWidgets()[3]->printLines(1);
////////////////////
    getWidgets()[4]->printLines(1);
    getWidgets()[4]->printContent(1);
    getWidgets()[4]->printLines(1);
////////////////////////
    getWidgets()[5]->printLines(1);
    getWidgets()[5]->printContent(1);
    getWidgets()[5]->printLines(1);
////////////////////////
  }
}
