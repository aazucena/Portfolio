#include "RoutineDialogueManager.h"
#include "Choice.h"
#include "KeyLines.h"
#include "DialogueManager.h"
#include "Dialogue.h"
#include "StringMagician.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void Dialogue::dialogueContinue() {
  std::string dontCareInput;
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  system("read");
}

std::string Dialogue::printFromFile(std::string file) {
  std::ifstream f("src/dialogue/" + file);
  std::stringstream ss;
  if (f.is_open()) {
    ss << f.rdbuf();
    f.close();
    return ss.str();
  }
  f.close();
}

std::string Dialogue::highlightWord(std::string dialogue,
                                    const std::string& search,
                                    const std::string& replace) {
  StringMagician text;
  std::string subject = dialogue;
  size_t pos = 0;
  while ((pos = subject.find(search, pos)) != std::string::npos) {
    subject.replace(pos, search.length(), text.bold(replace));
    pos += replace.length();
  }
  return subject;
}

void Dialogue::printDialogue(std::string name, std::string dialogue) {
  StringMagician text;
  if (name == "Instructions") {
    std::cout << text.bold(name) << ": \n";
    std::cout << text.bold(dialogue) << std::endl;
  } else {
    std::cout << name << ": \n";
    std::cout << dialogue << std::endl;
  }
}

void Dialogue::printDialogue(std::string dialogue) {
  std::cout << dialogue << std::endl;
}

std::string Dialogue::getDialogue(std::string name, std::string dialogue) {
  StringMagician text;
  std::stringstream ss;
  if (name == "Instructions") {
    ss << text.bold(name) << ": \n"
       << text.bold(dialogue) << std::endl;
  } else {
    ss << name << ": \n"
       << dialogue << std::endl;
  }
  return ss.str();
}

std::string Dialogue::getDialogue(std::string dialogue) {
  std::stringstream ss;
  ss << dialogue << std::endl;
  return ss.str();
}
