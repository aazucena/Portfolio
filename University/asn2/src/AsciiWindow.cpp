/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Image.h"
#include "Textbox.h"
#include "Coordinate.h"
#include "AsciiWindow.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;
void AsciiWindow::draw(ostream& os) {
  char c = ' ';
  const int maxWidth = getWidth()-1;
  for (int i = 0; i < getHeight(); i++) {
    for (int j = 0; j < getWidth(); j++) {
      if (i == 0 || i == getHeight()-1) {
        if (j==0) {
          os << "+";
        }
        else if (j == maxWidth) {
          os << "+\n";
        }
        else {
          os << "-";
        }
      }
      else {
        if (j==0) {
          os << "|";
        }
        else if (j == maxWidth) {
          os << "|\n";
        }
        else {
          for (int k = 0; k < getWidgets().size(); k++) {
            if (getWidgets()[k]->locatedAt(Coordinate (j, i))) {
              c = getWidgets()[k]->getAt(Coordinate(getWidgets()[k]->getLocation().x, getWidgets()[k]->getLocation().y));
              os << c;
            } else {
              os << " ";

            }
              os << " ";
          }
        }
      }
    }
  }
}
