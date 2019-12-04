#ifndef BUTTONCOMMAND_H_INCLUDED
#define BUTTONCOMMAND_H_INCLUDED
#include "Button.h"
#include "Mode.h"

class ButtonCommand {
 public:
  ButtonCommand(Button *b): button{b} {}
  void execute();
 private:
  Button *button;
};

#endif // BUTTONCOMMAND_H_INCLUDED
