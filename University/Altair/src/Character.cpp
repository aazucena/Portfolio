#include <string>
#include <iostream>
#include "Character.h"
#include "StringMagician.h"

void Character::affectionUp() {
  if (affectionPoint > MAX_AFFECTION) {
    std::cout << "{You have "
          << "maxed you affection with "
          << Character::getFirstName()
          << " "
          << Character::getLastName()
          << "}";
  } else {
    switch (getAffection()) {
    case 10:
    case 20:
    case 30:
    case 40:
    case 50:
    case 60:
      std::cout << "You are now "
           << Character::affectionLevelName()
           << "!"
           << std::endl;
      affectionPoint++;
      break;
    default:
      affectionPoint++;
      break;
    }
  }
}

void Character::setClub(std::string club) {
  clubName = club;
}

std::string Character::getClub() {
  return clubName;
}

std::string Character::affectionLevelName() {
  if (getAffection() > MAX_AFFECTION) {
    return StringMagician::bold("Couple");
  } else if (getAffection() <= MAX_AFFECTION && getAffection() >= 50) {
    return StringMagician::bold("Genuine Friends");
  } else if (getAffection() < 50 && getAffection() >= 40) {
    return StringMagician::bold("Best Friends");
  } else if (getAffection() < 40 && getAffection() >= 30) {
    return StringMagician::bold("Friends");
  } else if (getAffection() < 30 && getAffection() >= 20) {
    return StringMagician::bold("Colleagues");
  } else if (getAffection() < 20 && getAffection() >= 10) {
    return StringMagician::bold("Acquaintances");
  } else if (getAffection() < 10 && getAffection() >= 0) {
    return StringMagician::bold("Strangers");
  } else {
    return StringMagician::bold("Unknown");
    //write exception here
  }
}

void Character::setAffection(int affection) {
  affectionPoint = affection;
}

int Character::getAffection() {
  return affectionPoint;
}
