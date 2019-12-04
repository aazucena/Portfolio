#ifndef CLUB_H_INCLUDED
#define CLUB_H_INCLUDED
#include <iostream>
#include <string>
#include "Player.h"
#include "Stat.h"

class Club {
 public:
  Club() {}

  /**
  * Constructor of a club.
  */
  Club(std::string cn): clubName{cn} {}

  virtual ~Club() {}

  /**
  * Returns the club name
  * @return The name of the club
  */
  std::string getClubName();

  /**
  * Goes through a sequence of printout statements that will be shown to the Player
  * @return true as the Player shoudn't die here
  */
  bool playClub();

 private:
  std::string clubName;
};
#endif // CLUB_H_INCLUDED
