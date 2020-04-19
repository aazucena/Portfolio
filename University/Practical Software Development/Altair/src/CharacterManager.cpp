#include <string>
#include <vector>
#include <algorithm>
#include "Character.h"
#include "Player.h"
#include "CharacterManager.h"
#include "Exceptions.h"
#include "StringMagician.h"


CharacterManager* CharacterManager::instance; // Need this

void CharacterManager::initCharacter() {
  Player* p = Player::getInstance();
  Character* fr =  new Character("Alex", "Caruso", 'm');
    fr->setAffection(60);
    fr->setClub(p->getClub());
  if (std::find(CharacterManager::characters.begin(),
                 CharacterManager::characters.end(),
                 fr) != CharacterManager::characters.end()) {
    Character* newFr = fr;
    newFr->setAffection(60);
    newFr->setClub(p->getClub());
    std::replace(CharacterManager::characters.begin(),
                   CharacterManager::characters.end(),
                   fr, newFr);
  } else {
    CharacterManager::addCharacter(fr);
  }
}
void CharacterManager::setList(std::vector<Character*> list) {
  characters = list;
}

std::vector<Character*> CharacterManager::getList() {
  return characters;
}

void CharacterManager::addCharacter(Character* character) {
  std::string fn = StringMagician::stringToLower(character->getFirstName());
  std::string ln = StringMagician::stringToLower(character->getLastName());
  std::string fnToCompare;
  std::string lnToCompare;
  char gToCompare;

  for (size_t i = 0; i < characters.size(); i++) {
    Character* c;
    c = characters.at(i);

    fnToCompare = StringMagician::stringToLower(c->getFirstName());
    lnToCompare = StringMagician::stringToLower(c->getLastName());

    if (fnToCompare == fn && lnToCompare == ln
        && c->getGender() == character->getGender()) {
      return; // Mostly for Alex's sake
    }
  }
  characters.push_back(character);
}

Character* CharacterManager::getCharacter(Person charc) {
  Character* c;

  std::string fn = StringMagician::stringToLower(charc.getFirstName());
  std::string ln = StringMagician::stringToLower(charc.getLastName());

  std::string fnToCompare;
  std::string lnToCompare;
  char gToCompare;

  for (size_t i = 0; i < characters.size(); i++) {
    c = characters.at(i);

    fnToCompare = StringMagician::stringToLower(c->getFirstName());
    lnToCompare = StringMagician::stringToLower(c->getLastName());

    if (fnToCompare == fn && lnToCompare
        == ln && c->getGender() == charc.getGender()) {
      return c;
    }
  }

  throw character_not_found_error("No such character exists."); // Must throw

  return c; // Will return the last character in the list
}

