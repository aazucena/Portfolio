#include "ButtonObserver.h"
#include "Button.h"
#include <iostream>
#include <fstream>
void ButtonObserver::update(Button *b) {
  std::ofstream outiFile;
  outiFile.open("src/logs/log.txt");
  if (b->getActionName() == "Play") {
    outiFile << "Play: " << b->getCounter() << std::endl;
  }
  if (b->getActionName() == "Pause") {
    outiFile << "Pause: " << b->getCounter() << std::endl;
  }
  if (b->getActionName() == "Forward") {
    outiFile << "Forward: " << b->getCounter() << std::endl;
  }
  if (b->getActionName() == "Rewind") {
    outiFile << "Rewind: " << b->getCounter() << std::endl;
  }
  if (b->getActionName() == "Change") {
    outiFile << "Change: " << b->getCounter() << std::endl;
  }
}
