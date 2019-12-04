#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>
#include "Person.h"


class Character : public Person {
 public:
  Character(std::string fn, std::string ln, char g): Person{fn, ln, g} {
    affectionPoint = 0;
    clubName = "Go-Home Club";
  }
  Character(std::string fn, std::string ln,
            char g,
            std::string club): Person{fn, ln, g}, clubName{club} {
    affectionPoint = 0;
  }
  virtual ~Character() {}

  /**
  *@return true if affection is raised
  */
  void affectionUp();

  std::string affectionLevelName();

  std::string getClub();

  /**
  *sets the affection of a character
  *@param affection, affection of a character to the player
  */
  void setAffection(int affection);


  /**
  *sets the affection of a character
  *@param affection, affection of a character to the player
  */
  void setClub(std::string club);

  /**
  *gets the affection level of a character
  *@return affectionPoint
  */
  int getAffection();

  /**
  * Max affection for a Character
  */
  int MAX_AFFECTION = 60;

 private:
  int affectionPoint;
  std::string clubName;
};

#endif // CHARACTER_H_INCLUDED
