#ifndef ITEMSHOP_H_INCLUDED
#define ITEMSHOP_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Character.h"
#include "CharacterManager.h"
#include "Dialogue.h"

class ItemShop {
 public:
  ItemShop() {}
  virtual ~ItemShop() {}

  /**
  * Goes through a sequence of printout statements that will be shown to the Player.
  * Simulates the "shop" section of the game.
  */
  bool displayShop();

 private:
  void printChoices();
  Character* printCharacters();
};

#endif // ITEMSHOP_H_INCLUDED
