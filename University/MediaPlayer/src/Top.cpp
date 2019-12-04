/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Top.h"
#include "Widget.h"
#include "Button.h"
#include "Display.h"
#include <iostream>
#include <vector>

void Top::initModel() {
  Display d("Display", 8);
  Button b1("Play");
  Button b2("Pause");
  Button b3("Rewind");
  Button b4("Forward");
  Button b5("Change Mode");
  Top::addWidget(&d);
  Top::addWidget(&b1);
  Top::addWidget(&b2);
  Top::addWidget(&b3);
  Top::addWidget(&b4);
  Top::addWidget(&b5);
  printModel();
}
void Top::printModel() {
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
