#include "ButtonCommand.h"
#include "Button.h"

void ButtonCommand::execute() {
  if (button->getAction() == Button::PLAY) {
    button->play();
    button->buttonPressed(button);

  } else if (button->getAction() == Button::PAUSE) {
    button->pause();
    button->buttonPressed(button);

  } else if (button->getAction() == Button::FORWARD) {
    button->forward();
    button->buttonPressed(button);


  } else if (button->getAction() == Button::REWIND) {
    button->rewind();
    button->buttonPressed(button);


  } else if (button->getAction() == Button::CHANGE) {
    button->change();
    button->buttonPressed(button);

  } else {
    throw "What the F*** is that error. THere is no such command that exists";
  }
}
