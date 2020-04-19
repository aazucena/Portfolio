#ifndef CHARACTERMANAGER_H_INCLUDED
#define CHARACTERMANAGER_H_INCLUDED
#include <vector>
#include <string>
#include <locale>
#include "Character.h"
#include "Exceptions.h"

class CharacterManager {
 public:
  CharacterManager() {}
  virtual ~CharacterManager() {}

  void initCharacter();
  /**
  *sets the character list
  *@param character list
  */
  void setList(std::vector<Character*> list);

  /**
  *gets a list of characters
  *@return a list of characters
  */
  std::vector<Character*> getList();

  /**
  *adds character
  *@param a character object
  */
  void addCharacter(Character* character);

  /**
  * gets character object
  * @param fn first name of a character
  * @param ln last name of a character
  * @param g character representation of a gender 'm' for male or 'f' for female
  * @return the character
  */
  Character* getCharacter(Person charc);

  static CharacterManager* getInstance() {
    if (instance == nullptr) {
      instance = new CharacterManager();
    }

    return instance;
  }

 private:
  static CharacterManager* instance;

  std::vector<Character*> characters;
};


#endif // CHARACTERMANAGER_H_INCLUDED
