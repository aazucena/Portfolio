#include <string>
#include <cmath>
#include "Person.h"
#include "Stat.h"
#include "Player.h"
#include "StringMagician.h"

Player* Player::instance;

void Player::setMoney(double money) {
  Player::money = money;
}

double Player::spendMoney(double cost) {
  double result = cost - money;

  if (getMoney() <= 0) {
    return 0;
  } else {
    return abs(result);
  }
}
double Player::getMoney() {
  return Player::money;
}

Stat* Player::getStat(std::string stat) {
  stat = StringMagician::stringToLower(stat);

  for (int i = 0; i < 6; i++) {
    if (stat == stats[i]->getStatName()) {
      return stats[i];
    }
  }
}

void Player::setStat(Stat* s) {
  std::string st = s->getStatName();
  st = StringMagician::stringToLower(st);

  for (int i = 0; i < 6; i++) {
    if (st == stats[i]->getStatName()) {
      stats[i]->setLevel(s->getLevel());
    }
  }
}
std::string Player::getStatLevelName(Stat* s) {
  int lvl = s->getLevel();
  std::string st = s->getStatName();
  st = StringMagician::stringToLower(st);

  for (int i = 0; i < 6; i++) {
    if (st == stats[i]->getStatName()
        && stats[i]->getLevel() == s->getLevel()) {
      if (s->getLevel() <= s->MAX_LEVEL && s->getLevel() >= 50) {
        return statLevels[i][5];
        break;
      } else if (s->getLevel() < 50 && s->getLevel() >= 40) {
        return statLevels[i][4];
        break;
      } else if (s->getLevel() < 40 && s->getLevel() >= 30) {
        return statLevels[i][3];
        break;
      } else if (s->getLevel() < 30 && s->getLevel() >= 20) {
        return statLevels[i][2];
        break;
      } else if (s->getLevel() < 20 && s->getLevel() >= 10) {
        return statLevels[i][1];
        break;
      } else if (s->getLevel() < 10 && s->getLevel() > 0) {
        return statLevels[i][0];
        break;
      } else {
        return StringMagician::bold("Unknown");
        break;
        //write exception here
      }
    }
  }
}

void Player::setClub(std::string cn) {
  Player::cn = cn;
}

std::string Player::getClub() {
  return Player::cn;
}

void Player::setJob(std::string jn) {
  Player::jn = jn;
}

std::string Player::getJob() {
  return Player::jn;
}

void Player::initializeStats() {
  std::string statNames[6];
  statNames[0] = "athleticism";
  statNames[1] = "charisma";
  statNames[2] = "guts";
  statNames[3] = "understanding";
  statNames[4] = "knowledge";
  statNames[5] = "proficiency";

  for (int i = 0; i < 6; i++) {
    Stat* s = new Stat(statNames[i]);

    stats.push_back(s);
  }
}
