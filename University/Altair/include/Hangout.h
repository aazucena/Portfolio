#ifndef HANGOUT_H_INCLUDED
#define HANGOUT_H_INCLUDED
#include <iostream>
#include "Character.h"
#include "CharacterManager.h"

class Hangout {
 public:
  Hangout() {}

  virtual ~Hangout() {}

  /**
  * Goes through a sequence of printout statements that will be shown to the Player.
  * Simulates the "hangout" section of the game.
  * @return true as the Player shoudn't die here
  */
  bool playHangout();
};
#endif // HANGOUT_H_INCLUDED
