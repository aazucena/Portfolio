/*
* CPSC 2720 Fall 2018
* Copyright 2018 Dr. Anvik <john.anvik@uleth.ca>
*/

#ifndef ASCIIWINDOW_H
#define ASCIIWINDOW_H

#include <Window.h>
#include <iostream>


class AsciiWindow : public Window {
 public:
  AsciiWindow(int w, int h): Window(w, h) {}
  virtual ~AsciiWindow() {}
  void draw(std::ostream& os);
};

#endif  // ASCIIWINDOW_H
