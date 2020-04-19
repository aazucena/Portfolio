#include "GameDataManager.h"
#include "FileManager.h"
#include "Player.h"
#include "ItemInventory.h"
#include "Character.h"
#include "Dialogue.h"
#include "CharacterManager.h"
#include "GameStateManager.h"
#include "EventManager.h"
#include "StringMagician.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <iostream>
#include <string>
#include <locale>

void GameDataManager::saveGame(EventManager em) {
  GameDataManager::fileManager.writeSaveFile(em);
}

bool GameDataManager::loadGame() {
  Dialogue d;
  if (!GameDataManager::fileManager.readPlayerSave()
      || !GameDataManager::fileManager.readCharacterSave()
      || !GameDataManager::fileManager.readEventSave()) {
    std::cout << "A save file does not exist.\n";
    d.dialogueContinue();
    return false;
  }
  return true;
}

EventManager GameDataManager::loadEventManager() {
  return GameDataManager::fileManager.getEventFile();
}

bool GameDataManager::setupPlayer() {
  std::string dontCareInput;
  std::string fn;
  std::string ln;
  std::string gender;
  std::string response;
  std::string decision;
  Dialogue d;
  char g;
  bool correctInput = false;
  bool cInput = false;
  bool failed = false;

  std::cout << "\nHello there, "
            << "and welcome again!\n";
  d.dialogueContinue();
  std::cin.ignore();
  do {
    std::cout << "Before you start, "
              <<"Tell me your first name? (Default: Avery)\n";
    getline(std::cin, fn); // Get first name

    if (fn.empty()) {
      fn = "Avery";
    }
    std::cout << "\nOkay " << fn
              << ", what is your last name? (Default: Doe)"
              << std::endl;
    getline(std::cin, ln); // Get last name

    if (ln.empty()) {
      ln = "Doe";
    }
    std::cout << "\nIs your name: "
              << fn << " "
              << ln << "? (Yes or No)"
              << std::endl;
    getline(std::cin, decision); // Getting yes or no

    decision = StringMagician::stringToLower(decision);
    if (!decision.empty()) {
      if (decision == "yes"
          || decision == "ye"
          || decision == "y"
          || decision == "yee") {
        cInput = true;
      } else {
        std::cout << "I assume you mean no... \n\n";
      }
    } else {
      std::cout << "I assume you mean no... \n\n";
    }
  } while (cInput == false);
  std::cout << "\n"
            << fn
            << ", How would you identify your gender "
            << "(Male or Female)?"
            << std::endl;

  while (!correctInput) {
    if (failed) {
      std::cout << "Please identify a PROPER gender"
                << " (Male or Female)?"
                << std::endl;
    }

    getline(std::cin, gender); // Getting gender

    gender = StringMagician::stringToLower(gender);

    if (gender == "male"
        || gender == "m") {
      g = 'm';
      correctInput = true;
    } else if (gender == "female"
               || gender == "f") {
      g = 'f';
      correctInput = true;
    } else if (gender == "none of them"
               || gender == "none") {
      std::cout << "Does that gender even exist. Huh..." << std::endl;
      d.dialogueContinue();

      std::cout << "The type of person who"
                << " can't throw something important away, "
                << "can never hope to change anything."
                << std::endl;
      d.dialogueContinue();

      return false;
    } else {
      std::cout << "\nI dont know what "
                << gender << " is, but unfortunately, "
                << "I will keep asking for "
                << "your gender, till you give"
                << " me a proper response."
                << std::endl;
      d.dialogueContinue();
      failed = true;
    }
  }

  if (fn == "Aldrin"
      && ln == "Azucena"
      && g == 'm') {
    std::cout << "\n"
              << fn << " " << ln
              << ",\nYou pd the ickemost "
              << "handsomest name of all time." << std::endl;
    d.dialogueContinue();
  } else if ((fn == "Billy"|| fn =="William")
             && ln == "Hughson"
             && g == 'm') {
    std::cout << "\n"
              << fn << " " << ln <<
              ",\nYou picked the most "
              << "charming name of all time."
              << std::endl;
    d.dialogueContinue();
  } else if (fn == "Brian"
             && ln == "Cruz"
             && g == 'm') {
    std::cout << "\n"
              << fn << " " << ln
              << ",\nYou picked the most "
              << "smartest/weebest name of all time."
              << std::endl;
    d.dialogueContinue();
  } else if (fn == "John"
             && ln == "Anvik"
             && g == 'm') {
    std::cout << "\n"
              << fn << " " << ln
              << ",\nThat's an interesting "
              << "name you picked..."
              << std::endl;
    d.dialogueContinue();

    std::cout << "Are you my father?!"<< std::endl;
    d.dialogueContinue();

    std::cout << "No? ok."<< std::endl;
    d.dialogueContinue();
  } else if (fn == "Avery"
             && ln == "Doe"
             && (g =='m'|| g =='f')) {
    std::cout << "\nHAHAHAHA, "
              << "You picked the most "
              << "generic name of all time."
              << std::endl;
    d.dialogueContinue();
  } else {
    std::cout << "\n"
              << fn << " " << ln
              << " is a meh, but atleast a decent one."
              << std::endl;
    d.dialogueContinue();
  }

  std::cout << "Alright I think you are all set. "
            << "Good luck and have fun!"<< std::endl;
  d.dialogueContinue();

  Player* p = Player::getInstance();
  p->setFirstName(fn);
  p->setLastName(ln);
  p->setGender(g);

  return true;
}


