#include "Character.h"
#include "CharacterManager.h"
#include "Player.h"
#include "Stat.h"
#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool FileManager::writeSaveFile(EventManager em) {
  std::ofstream outiFile;
  outiFile.open("src/game/PlayerSave.txt");

  Player* p = Player::getInstance();

  outiFile << p->getFirstName()
           << " " << p->getLastName()
           << " " << p->getGender()
           << " " << p->getMoney()
           << " " << formatSaveFile(p->getClub())
           << " " << formatSaveFile(p->getJob())
           << std::endl;

  std::string statNames[6];
  statNames[0] = "athleticism";
  statNames[1] = "charisma";
  statNames[2] = "guts";
  statNames[3] = "understanding";
  statNames[4] = "knowledge";
  statNames[5] = "proficiency";

  Stat* s;

  for (int i = 0; i < 6; i++) {
    s = p->getStat(statNames[i]);
    outiFile << s->getStatName() << " "
             << s->getLevel()
             << std::endl;
  }
  outiFile.close();
  outiFile.open("src/game/CharacterSave.txt");

  CharacterManager* cm = CharacterManager::getInstance();
  std::vector<Character*> cList = cm->getList();

  Character* c;

  for (int i = 0; i < cList.size(); i++) {
    c = cList.at(i);

    outiFile << c->getFirstName()
             << " " << c->getLastName()
             << " " << c->getGender()
             << " " << c->getAffection()
             << " " << formatSaveFile(c->getClub())
             << std::endl;
  }

  outiFile.close();
  outiFile.open("src/game/EventSave.txt");

  int day = em.getCurrentDay();
  if (day <= 6) {
    outiFile << day;
  } else {
    outiFile << 1;
  }

  outiFile.close();

  return true;
}

bool FileManager::readCharacterSave() {
  std::ifstream saviFile;
  saviFile.open("src/game/CharacterSave.txt");

  if (saviFile.fail()) {
    return false;
  }

  CharacterManager* cm = CharacterManager::getInstance();
  std::string fn;
  std::string ln;
  char g;
  int a;
  std::string cn;

  while (!saviFile.eof()) {
    saviFile >> fn >> ln >> g >> a >> cn;
    //std::getline(saviFile, cn);
    if (saviFile.eof()) {
      saviFile.close();
      return true;
    }
    Character* c = new Character(fn, ln, g);
    c->setAffection(a);
    c->setClub(formatReadFile(cn));
    cm->addCharacter(c);
  }
  return true;
}

bool FileManager::readPlayerSave() {
  std::ifstream saviFile;
  std::string fn;
  std::string ln;
  char g;
  double m;
  std::string cn;
  std::string jn;
  Player* p = Player::getInstance();
  std::string sn;
  unsigned int sl;

  saviFile.open("src/game/PlayerSave.txt");
  if (saviFile.fail()) {
    return false;
  }

  saviFile >> fn >> ln >> g >> m >> cn >> jn;

  p->setFirstName(fn);
  p->setLastName(ln);
  p->setGender(g);
  p->setMoney(m);
  p->setClub(formatReadFile(cn));
  p->setJob(formatReadFile(jn));

  for (int i = 0; i < 6; i++) {
    saviFile >> sn >> sl;
    Stat* s = new Stat(sn);
    s->setLevel(sl);
    p->setStat(s);
  }
  saviFile.close();
  return true;
}

bool FileManager::readEventSave() {
  std::ifstream saviFile;
  int day = 1;
  EventManager em;

  saviFile.open("src/game/EventSave.txt");
  if (saviFile.fail()) {
    return false; // Should be bool
  }
  saviFile >> day;

  em.setCurrentDay(day);

  saviFile.close();
  return true;
}

EventManager FileManager::getEventFile() {
  std::ifstream saviFile;
  EventManager em;
  int day = 1;
  saviFile.open("src/game/EventSave.txt");

  if (saviFile.fail()) {
    return em; // Should be bool
  }

  while (saviFile >> day) {
    em.setCurrentDay(day);
  }
  saviFile.close();
  return em;
}

std::string FileManager::formatReadFile(std::string val) {
  std::replace(val.begin(), val.end(), '*', ' ');
  return val;
}

std::string FileManager::formatSaveFile(std::string val) {
  std::replace(val.begin(), val.end(), ' ', '*');
  return val;
}
