#ifndef CHOICE_H_INCLUDED
#define CHOICE_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include "Person.h"
#include "HelperPerson.h"

class Choice {
 public:
  Choice() {}
  Choice(std::string cn, bool f);
  virtual ~Choice() {}

  /**
  * Returns the choice display name
  * @return string of the choice name
  */
  std::string getChoiceName();

  /**
  * Returns the boolean that will decide whether the player lives or not
  * @return bool value of the Player's fate. True he/she lives. False he/she will die.
  */
  bool getFate();

  /**
  * Sets the boolean whether a stat will be affected or not.
  * @param a bool value whether a choice will affect a player's stat or not
  */
  void setAffectStat(bool a);

  /**
  * Sets the boolean whether a Character will be affected or not.
  * @param a bool value whether a choice will affect a Character's affection or not
  */
  void setAffectCharacter(bool a);

  /**
  * Sets the name of the stat to be affected
  * @param stat Name of the stat to affect
  */
  void setStatToAffect(std::string stat);

  /**
  * Sets the Character to be affected
  * @param c Person object that holds a first name, last name, and gender
  */
  void setCharacterToAffect(Person c);

  /**
  * Asks for help if true. Won't if false.
  * @param a boolean value that depicts whether the Player asks for help or not
  */
  void printStatHelp(bool a);

  /**
  * Asks for help if true. Won't if false.
  * @param a boolean value that depicts whether the Player asks for help or not
  */
  void printAffHelp(bool a);

  /**
  * Adds a string to the result sentence and is played when Player picks this choice
  * @param s String to add to the result sentence
  */
  void addResultSentence(std::string s);

  /**
  * Plays through the result sentence and may raise a Player's stat or Character's affection.
  * Depending on the outcome the Player may die.
  * @return bool depicting whether the Player lives through the choice he/she chose
  */
  bool playChoice();

  /**
  * Returns a boolean determining whether the Player has a job
  * @return bool that determines whether Player is in a job
  */
  void getAJob(bool a);

 private:
  HelperPerson hp;
  std::string choiceName;
  bool fate;

  bool affectingStat = false;
  bool affectingCharacter = false;
  bool getStatHelp = false;
  bool getAffHelp = false;

  bool getJob = false;
  std::string statToAffect;
  Person characterToAffect;

  std::vector<std::string> sentences;
};

#endif // CHOICE_H_INCLUDED
