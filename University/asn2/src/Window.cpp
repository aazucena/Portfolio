/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Window.h"
#include "Widget.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <iomanip>
#include <vector>
using namespace std;
Window::Window(int w, int h) {
  if (w > MAX_WIDTH) {
    throw illegal_size_error("The width is over the max");
  } else if (h > MAX_HEIGHT) {
    throw illegal_size_error("The height is over the max");
  } else if (w <= 0) {
    throw illegal_size_error("The width is 0 or less");
  } else if (h <= 0) {
    throw illegal_size_error("The height is 0 or less");
  } else {
    setWidth(w);
    setHeight(h);
  }
}
Window::~Window() {}
void Window::addWidget(Widget* w) {
  int xLimit = (w->getWidth()+w->getLocation().x);
  int yLimit = (w->getHeight()+w->getLocation().y);
  // if widget placed out or on the window border
  if (xLimit >= getWidth() || yLimit >= getHeight()) {
    throw widget_operation_failed_error("Widget cannot be placed as it cannot fit in window");
  } else {
    for (int i = 0; i < contents.size(); i++) {
      Widget *exWid = getWidgets()[i];
      int exLimit = (exWid->getWidth()+exWid->getLocation().x);
      int eyLimit = (exWid->getHeight()+exWid->getLocation().y);
      if (exLimit >= w->getLocation().x && eyLimit >= w->getLocation().y
          && exWid->getLocation().x <= xLimit && exWid->getLocation().y <= yLimit) {
        throw widget_operation_failed_error("Widget cannot be placed as it cannot be placed on the existing widget");
      }
    }
  }
  Window::contents.push_back(w);
}
void Window::removeWidget(Widget* w) {
  bool foundWidget = false;
  for (int i = 0; i < contents.size(); i++) {
    if (find(getWidgets().begin(), getWidgets().end(), w) != getWidgets().end()) {
      contents.erase(contents.begin()+i);
      foundWidget = true;
      break;
    }
  }
  if (foundWidget==false) {
    throw widget_operation_failed_error("Widget cannot be removed as it doesn't exists");
  }
}
unsigned int Window::getWidth() {
  return width;
}
unsigned int Window::getHeight() {
  return height;
}
vector<Widget*> Window::getWidgets() {
  return contents;
}
void Window::resize(unsigned int w, unsigned int h) {
  if (w > MAX_WIDTH) {
    throw illegal_size_error("The width is over the max");
  } else if (h > MAX_HEIGHT) {
    throw illegal_size_error("The height is over the max");
  } else if (w <= 0) {
    throw illegal_size_error("The width is 0 or less");
  } else if (h <= 0) {
    throw illegal_size_error("The height is 0 or less");
  } else {
    setWidth(w);
    setHeight(h);
  }
}
void Window::setHeight(int h) {
  height = h;
}
void Window::setWidth(int w) {
  width = w;
}
