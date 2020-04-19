#include "KeyLines.h"
#include "StringMagician.h"
#include <iostream>
#include <string>

KeyLines::KeyLines(std::string name,
                   std::string contents) {
  textLine = contents;
  textName = name;
}
std::string KeyLines::getKeyLines() {
  textLine = StringMagician::bold(textLine);
  return textLine;
}

std::string KeyLines::getKeyTitle() {
  textName = StringMagician::bold(textName);
  return textName;
}

//string stream
bool KeyLines::containsKeyWord(std::string con) {
  if (con.find(textLine) != std::string::npos) {
    return true;
  } else {
    return false;
  }
}

void KeyLines::printKeyLine() {
  std::cout << getKeyLines();
}
