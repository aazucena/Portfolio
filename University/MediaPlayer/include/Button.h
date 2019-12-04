/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "Widget.h"
#include "Mode.h"
#include "Variant.h"
#include <iostream>
#include <iomanip>
#include <string>

class Button: public Widget {
 public:
  enum action {PLAY, PAUSE, FORWARD, REWIND, CHANGE};
  Button(): Widget() {}
  Button(std::string bn): Widget{bn} {}
  Button(std::string bn, unsigned int bs): Widget{bn, bs} {}
  virtual ~Button() {}
  void printContent(int col);
  void setAction(Button::action br);
  Button::action getAction();
  Mode::ModeType getMDType();
  Variant::VariantType getVType();
  std::string getActionName();
  std::string getModeType();
  void play();
  void pause();
  void rewind();
  void forward();
  void change();
  int getCounter();
  void buttonPressed(Button *b);

 private:
  unsigned int MAX_SIZE = 10;
  int counter = 0;
  Button::action current;
  Mode * mode;
  Variant *var;
};
#endif // BUTTON_H_INCLUDED
