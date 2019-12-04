#ifndef HELPERPERSON_H_INCLUDED
#define HELPERPERSON_H_INCLUDED

#include <iostream>
#include <string>
#include "Character.h"
#include "CharacterManager.h"

class HelperPerson {
 public:
  HelperPerson() {}
  virtual ~HelperPerson() {}

  /**
  * This method prints to screen the controls for the game and some tips
  */
  void printHelp();

  /**
  * This function prints to screen all Characters affection status toward the player
  */
  void printAffectionStatus(CharacterManager* characterManager);

 private:
  std::string firstName = "Alex";
  std::string lastName = "Caruso";
};

#endif // HELPERPERSON_H_INCLUDED
