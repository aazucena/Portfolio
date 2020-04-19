#ifndef BUTTONOBSERVER_H_INCLUDED
#define BUTTONOBSERVER_H_INCLUDED
#include "ButtonCommand.h"
#include "Button.h"
class ButtonObserver {
 public:
  ButtonObserver() {}
  void update(Button *b);
};
#endif // BUTTONOBSERVER_H_INCLUDED
