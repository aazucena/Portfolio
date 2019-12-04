#include <string>
#include "Stat.h"
#include "StringMagician.h"

Stat::Stat(std::string stat) {
  statName = stat;
}

unsigned int Stat::levelUp() {
  return level++;
}

void Stat::setLevel(unsigned int lvl) {
  if (level > MAX_LEVEL) {
    //write exception
  } else {
    level = lvl;
  }
}

void Stat::setStatName(std::string stat) {
  statName = stat;
}

unsigned int Stat::getLevel() {
  return level;
}

std::string Stat::getStatName() {
  return statName;
}

