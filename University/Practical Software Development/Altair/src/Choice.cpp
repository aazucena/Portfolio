#include "Person.h"
#include "HelperPerson.h"
#include "Player.h"
#include "Dialogue.h"
#include "CharacterManager.h"
#include "Choice.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <vector>
#include <string>
#include <iostream>

Choice::Choice(std::string cn, bool f): choiceName{cn}, fate{f} {}

std::string Choice::getChoiceName() {
  return Choice::choiceName;
}

bool Choice::getFate() {
  return Choice::fate;
}

void Choice::setAffectStat(bool a) {
  Choice::affectingStat = a;
}

void Choice::setAffectCharacter(bool a) {
  Choice::affectingCharacter = a;
}

void Choice::setStatToAffect(std::string stat) {
  Choice::statToAffect = stat;
}

void Choice::setCharacterToAffect(Person c) {
  Choice::characterToAffect = c;
}

void Choice::printStatHelp(bool a) {
  Choice::getStatHelp = a;
}

void Choice::printAffHelp(bool a) {
  Choice::getAffHelp = a;
}

void Choice::addResultSentence(std::string s) {
  Choice::sentences.push_back(s);
}

void Choice::getAJob(bool a) {
  Choice::getJob = a;
}

bool Choice::playChoice() {
  CharacterManager* cm = CharacterManager::getInstance();
  std::string sentence;
  Dialogue d;
  Player* p = Player::getInstance();

  for (size_t i = 0; i < Choice::sentences.size(); i++) {
    sentence = Choice::sentences.at(i);

    std::cout << sentence << std::endl;
    d.dialogueContinue();
  }
  if (Choice::affectingStat) {
    Stat* s = p->getStat(Choice::statToAffect);
    s->levelUp();
  }
  if (Choice::affectingCharacter) {
    CharacterManager* cm = CharacterManager::getInstance();

    Character* c = cm->getCharacter(Choice::characterToAffect);
    c->affectionUp();
  }
  if (Choice::getStatHelp) {
    hp.printHelp();
  }
  if (Choice::getAffHelp) {
    hp.printAffectionStatus(cm);
  }
  if (Choice::getJob) {
    p->setJob(Choice::getChoiceName());
  }

  return Choice::getFate();
}
