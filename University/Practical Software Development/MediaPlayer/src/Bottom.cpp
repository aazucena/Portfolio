/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Bottom.h"
#include "Widget.h"
#include "Button.h"
#include "Display.h"
#include <iostream>
#include <vector>
void Bottom::initModel() {
  Button b1("Change Mode");
  Button b2("Rewind");
  Button b3("Forward");
  Button b4("Pause");
  Button b5("Play");
  Display d("Display", 8);
  Bottom::addWidget(&b1);
  Bottom::addWidget(&b2);
  Bottom::addWidget(&b3);
  Bottom::addWidget(&b4);
  Bottom::addWidget(&b5);
  Bottom::addWidget(&d);
  printModel();
}
void Bottom::printModel() {
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

    getWidgets()[3]->printLines(2);
    getWidgets()[4]->printLines(2);
    std::cout << std::endl;
    getWidgets()[3]->printContent(2);
    getWidgets()[4]->printContent(2);
    std::cout << std::endl;
    getWidgets()[3]->printLines(2);
    getWidgets()[4]->printLines(2);
    std::cout << std::endl;
////////////////////
    getWidgets()[5]->printLines(1);
    getWidgets()[5]->printContent(1);
    getWidgets()[5]->printLines(1);
  }
}

