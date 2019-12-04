/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Button.h"
#include "Mode.h"
#include "ButtonObserver.h"
#include "Variant.h"
#include <iostream>
#include <iomanip>
#include <string>
void Button::printContent(int col) {
  int size = getName().length();
  int eq = (size/2)+1;
  int check = eq % 2;
  int nwidth;
  if (col <= 1) {
    std::cout << "|"
              << std::string(eq, ' ')
              << getName()
              << std::string(eq-1, ' ')
              << "|" << (col == 1 ? "\n" : " ");
  } else if (col == 2) {
    if (check == 1) {
      std::cout << "|"
                << getName()
                << " |" << (col == 2 ? " " : "\n");
    } else {
      std::cout << "|"
                << getName()
                << "|" << (col == 2 ? " " : "\n");
    }
  } else {
    std::cout << "Lol" << std::endl;
  }
}

void Button::setAction(Button::action br) {
  current = br;
}

std::string Button::getActionName() {
  if (current == Button::PLAY) {
    return "Play";
  } else if (current == PAUSE) {
    return "Pause";
  } else if (current == REWIND) {
    return "Rewind";
  } else if (current == FORWARD) {
    return "Forward";
  } else if (current == CHANGE) {
    return "Change";
  } else {
    throw "No such type";
  }
}

Button::action Button::getAction() {
  if (current == Button::PLAY) {
    return Button::PLAY;
  } else if (current == PAUSE) {
    return Button::PAUSE;
  } else if (current == REWIND) {
    return Button::REWIND;
  } else if (current == FORWARD) {
    return Button::FORWARD;
  } else if (current == CHANGE) {
    return Button::CHANGE;
  } else {
    throw "No such type";
  }
}

int Button::getCounter() {
  return counter;
}

void Button::buttonPressed(Button *b) {
  ButtonObserver bo;
  counter++;
  bo.update(b);
}

std::string Button::getModeType() {
  if (mode->getModeType() == Mode::MP3) {
    return "Song";
  } else if (mode->getModeType() == Mode::VIDEO) {
    return "Video";
  } else if (mode->getModeType() == Mode::RADIO) {
    return "Radio";
  } else {
    return "None";
  }
}

Mode::ModeType Button::getMDType() {
  return mode->getModeType();
}

Variant::VariantType Button::getVType() {
  return var->getVType();
}

void Button::play() {
  std::cout << "Playing " + getModeType() << "\n";
}

void Button::pause() {
  if (getModeType() == "Radio") {
    std::cout << "Stopping ";
  } else {
    std::cout << "Pausing ";
  }
  std::cout << getModeType() << "\n";
}

void Button::rewind() {
  if (getModeType() == "Radio") {
    std::cout << "Seeking Previous Station"<< "\n";
  } else {
    std::cout << "Previous " + getModeType()<< "\n";
  }
}

void Button::forward() {
  if (getModeType() == "Radio") {
    std::cout << "Seeking Next Station"<< "\n";
  } else {
    std::cout << "Next " + getModeType()<< "\n";
  }
}
void Button::change() {
  mode->setMode(getMDType(), getVType());
}

