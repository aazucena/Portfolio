#include "Character.h"
#include "CharacterManager.h"
#include "GameDataManager.h"
#include "Event.h"
#include "EventManager.h"
#include "RoutineDialogueManager.h"
#include "GameStateManager.h"
#include "Date.h"
#include "Player.h"
#include "Job.h"
#include "Club.h"
#include "Hangout.h"
#include "StringMagician.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <string>
#include <iostream>


EventManager GameStateManager::getEventManager() {
  return eventManager;
}

void GameStateManager::setEventManager(EventManager em) {
  eventManager = em;
}

bool GameStateManager::loadGame() {
  if (gameData.loadGame()
      && GameStateManager::eventManager.getCurrentDay() != 0) {
    setEventManager(gameData.loadEventManager());
    return true;
  } else {
    printMainMenu();
    return true;
  }
  return false;
}

bool GameStateManager::printMainMenu() {
  std::string dontCareInput; // string dump
  char response;
  bool correctInput = false;

  std::cout << dialogue.printFromFile("others/title.txt");

  std::cout << "Welcome to Youth.txt made by Team Altair.\n";
  dialogue.dialogueContinue();

  std::cout << "Here you will have a "
            << "highschool experience in text form.\n";
  dialogue.dialogueContinue();

  std::cout << "I hope you have fun!!\n";
  dialogue.dialogueContinue();

  std::cout << "Main Menu\n";
  usleep(800000);
  std::cout << "-----------\n";
  usleep(800000);
  std::cout << "[1. New Game]\n";
  std::cout << "[2. Load Game]\n";
  std::cout << "[3. Exit Game]\n";

  do {
    if (std::cin >> response) {
      switch (response) {
      case '1':
        return GameStateManager::newGame();
        correctInput = true;
        break;
      case '2':
        if (!gameData.loadGame()) {
          return printMainMenu();
        }
        correctInput = true;
        GameStateManager::eventManager = gameData.loadEventManager();
        return true;
        break;
      case '3':
        correctInput = true;
        break;
      default:
        // User puts anything else ask again
        std::cout << "Not valid input.\n";
        correctInput = false;
        break;
      }
    } else {
      std::cout << "Not valid input.\n";
      correctInput = false;
    }
  } while (!correctInput);
  return false; // Something went wrong so terminate program
}

bool GameStateManager::newGame() {
  std::string dontCareInput;
  StringMagician text;
  bool correctInput = false;
  if (!gameData.setupPlayer()) {
    // If Player failed Player intialization
    // go back to main and terminate program
    return false;
  }
  Player* p = Player::getInstance();

  std::string fn = p->getFirstName();
  std::string ln = p->getLastName();
  std::cout <<"\n|----------Introduction----------|\n\n";
  std::cout << "You are " << text.bold(fn + " " + ln)
            << " who moved into the fresh,"
            " unfamiliar city called Calgary in Canada.\n";
  dialogue.dialogueContinue();

  std::cout << "You came from a small town as "
            << "your father found a better job in the city.\n";
  dialogue.dialogueContinue();

  std::cout << "You are a 3rd year senior student "
            << "who will be attending the big and the best "
            << "highschool around the world.\n";
  dialogue.dialogueContinue();

  std::cout << "Are you up for a challenge to survive "
            << " throughout the school? (Yes or No) \n";

  std::string response;

  while (!correctInput) {
    getline(std::cin, response);

    response = StringMagician::stringToLower(response);

    if (response == "yes"
        || response == "yeah"
        || response == "yee"
        || response == "y") {
      std::cout << "\nYou will encounter such obstacles"
                << " in this school like in real life.\n";
      dialogue.dialogueContinue();

      std::cout << "Your choices in this unpredictable story"
                << " will affect yourself and the direction of this game.\n";
      dialogue.dialogueContinue();

      std::cout << "So "
                << text.bold("BE WARNED")
                << ", and good luck...\n";
      dialogue.dialogueContinue();

      correctInput = true;
    } else if (response == "no"
               || response == "nope"
               || response == "never"
               || response == "n") {
      std::cout << "Why are you even bother to play "
                << "this game in the first place?\n";
      return false;
    } else {
      std::cout << "I don't understand. Can you repeat that?\n";
    }
  }
  printTutorial();
  return true;
}

void GameStateManager::printTutorial() {
  StringMagician text;
  std::string dontCareInput;
  std::string flName;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();
  std::string ln = p->getLastName();
  // Quite long will need help
  std::cout << StringMagician::bold("EVENING\n\n");
  std::cout << "*Day 0*\n";
  std::cout << "|---------Prologue---------|\n\n";
  usleep(800000);

  flName = dialogue.printFromFile("tutorial/tut1.txt");
  dialogue.printDialogue(fn + " " + ln, flName);
  dialogue.dialogueContinue();

  flName = dialogue.printFromFile("tutorial/tut2.txt");
  flName = dialogue.highlightWord(flName, "$location", "Benjamin's");
  dialogue.printDialogue(flName);
  dialogue.dialogueContinue();

  flName = dialogue.printFromFile("tutorial/tut3.txt");
  flName = dialogue.highlightWord(flName, "$location", "humongous school");
  dialogue.printDialogue(flName);
  dialogue.dialogueContinue();

  flName = dialogue.printFromFile("tutorial/tut4.txt");
  flName = dialogue.highlightWord(flName, "$stat", "Bold Guts");
  dialogue.printDialogue(flName);
  dialogue.dialogueContinue();

  flName = dialogue.printFromFile("tutorial/tut5.txt");
  flName = dialogue.highlightWord(flName, "$stat", "Strong Athleticism");
  dialogue.printDialogue(flName);
  dialogue.dialogueContinue();

  flName = dialogue.printFromFile("tutorial/tut6.txt");
  flName = dialogue.highlightWord(flName, "$stat", "Learned Knowledge");
  dialogue.printDialogue(flName);
  dialogue.dialogueContinue();

  flName = dialogue.printFromFile("tutorial/tut7.txt");
  flName = dialogue.highlightWord(flName, "$stat", "Empathetic Understanding");
  dialogue.printDialogue(flName);
  dialogue.dialogueContinue();


  flName = dialogue.printFromFile("tutorial/tut8.txt");
  flName = dialogue.highlightWord(flName, "$emp", "BE YOURSELF");
  dialogue.printDialogue(flName);
  dialogue.dialogueContinue();

  std::cout << "Thinking through that on my bed,"
            << " and fell asleep on the hopes of my dreams"
            << " that they will come true to become a "
            << text.bold("perfect student")
            << ", be in a "
            << text.bold("relationship")
            << ", and "
            << text.bold("number one in school")
            << ". It’s quite a stretch, "
            << "but I will never know what will happen in the future."
            << " We’ll see… \n";
  dialogue.dialogueContinue();

  std::cout << "At school… \n";
  dialogue.dialogueContinue();
  saveGame();
}

bool GameStateManager::playDay() {
  CharacterManager* cm = CharacterManager::getInstance();
  cm->initCharacter();
  dialogueManager.printStartOfDay(eventManager.getCurrentDay());
  if (eventManager.getCurrentDay() != 1) { //special event
    if (!eventManager.printEventsAndGetChosenEvent(
          Event::freeTimeType::MORNING)) {
      return false;
    }
  }

  dialogueManager.printLunchRoutine(eventManager.getCurrentDay());
  if (eventManager.getCurrentDay() != 1) { //special event
    if (!eventManager.printEventsAndGetChosenEvent(
          Event::freeTimeType::LUNCH)) {
      return false;
    }
  }

  dialogueManager.printAfternoonRoutine(eventManager.getCurrentDay());
  if (eventManager.getCurrentDay() != 1) { //special event
    if (!eventManager.printEventsAndGetChosenEvent(
          Event::freeTimeType::AFTERNOON)) {
      return false;
    }
  }

  dialogueManager.printAfterSchoolRoutine(eventManager.getCurrentDay());
  if (eventManager.getCurrentDay() != 1
      && eventManager.getCurrentDay() != 6) { //special event
    if (!eventManager.printEventsAndGetChosenEvent(
          Event::freeTimeType::AFTERSCHOOL)) {
      return false;
    }
  }

  if (eventManager.getCurrentDay() != 6) {
    dialogueManager.printEndOfDay(eventManager.getCurrentDay());
  }
  eventManager.nextDay();

  saveGame();
  return true;
}
//Touch this for ending
void GameStateManager::printEnd() {
  Player *p = Player::getInstance();
  Stat* kno = p->getStat("knowledge");
  Stat* gut = p->getStat("guts");
  Stat* und = p->getStat("understanding");
  Stat* chr = p->getStat("charisma");
  Stat* ath = p->getStat("athleticism");
  Stat* pro = p->getStat("proficiency");
  std::string dontCareInput;
  StringMagician text;
  bool saved = false;

  std::cout << "The span between Fred and me is very far away"
            << " like like two football fields away. So I ran...\n";
  dialogue.dialogueContinue();

  if (ath->getLevel() >= ath->MAX_LEVEL) {
    std::cout << "I was able to keep with my maximized stamina,"
              << " and great form, because I have "
              << text.bold(p->getStatLevelName(ath))
              << " Athleticism.\n";
    dialogue.dialogueContinue();

    std::cout << "Running gracefully, "
              << "I encounter a crowd below where Fred is on the roof. "
              << "I hope I can easily go through the crowd:\n";
    dialogue.dialogueContinue();

    if (pro->getLevel() >= pro->MAX_LEVEL) {
      std::cout << "I am able go nimbling through the "
                << "crowd quickly as possible, because of my "
                << text.bold(p->getStatLevelName(pro))
                << " Proficiency.\n";
      dialogue.dialogueContinue();

      std::cout << "Finally reaching to the roof, "
                << "I am at the point I have to convince Fred to not do it. "
                << "But my body suddenly stopped as my fear got of me."
                << " Am I able to overcome that?\n";
      dialogue.dialogueContinue();

      if (gut->getLevel() >= gut->MAX_LEVEL) {
        std::cout << "Yes, I was able to move as I realized "
                  << "I got the confidence to save him. I believe I got "
                  << text.bold(p->getStatLevelName(gut))
                  << " Guts.\n";
        dialogue.dialogueContinue();

        std::cout << "Then I try opening the door, "
                  << "but it's and I don't what do. Think.. Think!!\n";
        dialogue.dialogueContinue();

        if (kno->getLevel() >= kno->MAX_LEVEL) {
          std::cout << "I got it. So I got my student id card,"
                    << " then I got that to open so easily, "
                    << "because I have "
                    << text.bold(p->getStatLevelName(kno))
                    << " Knowledge.\n";
          dialogue.dialogueContinue();

          std::cout << "I am now on the rooftop where Fred is about to jump."
                    << "I need to say something. What should I say?\n";
          dialogue.dialogueContinue();

          if (chr->getLevel() >= chr->MAX_LEVEL) {
            std::cout << "'Hey Fred, you aren't the sexual assault. "
                      << "You are innocent. You were falsely accused. I-'\n";
            usleep(800000);
            std::cout << "Press [Enter] to continue\n";

            std::cout << "Fred: \n";
            std::cout << "'NOBODY CARES ABOUT ME! "
                      << "YOU DON'T KNOW HOW FAR I'VE BEEN THROUGH,"
                      << "& JUST.. LEAVE ME ALONE!'\n";
            dialogue.dialogueContinue();

            std::cout << p->getFirstName() << ": \n";
            std::cout << "How can I convince him to stop from jumping off? "
                      << "How can I say in the way to say to to him "
                      << "to convince in order to actually "
                      <<  "sympathize him?\n";
            dialogue.dialogueContinue();

            if (und->getLevel() >= und->MAX_LEVEL) {
              std::cout << "Because of my "
                        << text.bold(p->getStatLevelName(und))
                        << " Understanding, I am able to say this: ";
              dialogue.dialogueContinue();
              std::cout    << "'Fred, your Alex told me about you."
                           << " He said that you are the best guy in his life."
                           << " Even over me though. "
                           << "So atleast think about me, your parents,"
                           << " and your best friend Alex."
                           << " Don't mind those boozos."
                           << " We will protect you no matter what!\n";
              dialogue.dialogueContinue();

              std::cout << p->getFirstName() << ": \n";
              std::cout << "Fred fall down...\n";
              dialogue.dialogueContinue();
              std::cout << "To his knees, on the safeground and he cried. "
                        << "I walk to him to hug him "
                        << "for assurance that he is okay.";
              dialogue.dialogueContinue();
              saved = true;
            } else {
              std::cout << "Fred: \n";
              std::cout << "'Nobody cares about me. good. bye. '\n";
              dialogue.dialogueContinue();

              std::cout << text.bold(p->getFirstName()) << ":\n";
              std::cout << "'NOOOO!!!!'\n";
              dialogue.dialogueContinue();

              std::cout << "Fred Died, and I am not able to save him,"
                        << " because I can't get him to sympathize with me."
                        << " I... i...";
              dialogue.dialogueContinue();

              std::cout << "Because of my "
                        << p->getStatLevelName(chr)
                        << " Understanding, he died!\n";
              dialogue.dialogueContinue();
            }
          } else {
            std::cout << "Fred Died, and I wasn't able to save him,"
                      << " because I don't know "
                      << "what to say during this situation..."
                      << "As I have "
                      << text.bold(p->getStatLevelName(chr))
                      << " Charisma\n";
            dialogue.dialogueContinue();
          }
        } else {
          std::cout << "Fred Died, and I wasn't able to save him,"
                    << " because I wasn't able to think"
                    << " of an idea to unlock the door"
                    << "during the pressure... "
                    << "As I have "
                    << text.bold(p->getStatLevelName(kno))
                    << " Knowledge\n";
          dialogue.dialogueContinue();
        }
      } else {
        std::cout << "Fred Died, and I wasn't able to save him,"
                  << " because I didn't overcome the pressure of"
                  << " the situation..."
                  << "As I have "
                  << text.bold(p->getStatLevelName(gut))
                  << " Guts\n";
        dialogue.dialogueContinue();
      }
    } else {
      std::cout << "Fred Died, and I can't able to save him,"
                << " because I wasn't able to sly through the crowd..."
                << "As I have "
                << text.bold(p->getStatLevelName(pro))
                << " Proficiency\n";
      dialogue.dialogueContinue();
    }
  } else {
    std::cout << "Fred Died, and I can't save him,"
              << " because I am not fast enough,"
              << " and I have bad stamina... "
              << "As I have "
              << text.bold(p->getStatLevelName(ath))
              << " Athleticism\n";
    dialogue.dialogueContinue();
  }
  std::cout << "The police surrounded the building,"
            << " and the school officially closed, because of the incident.\n";
  dialogue.dialogueContinue();

  if (saved == true) {
    std::cout << "I felt achieved on saving my friend. "
              << "I feel like a perfect student. And that's enough."
              << "I went to him, "
              << "and comfort him as I assure him that he will be ok.\n";
    dialogue.dialogueContinue();

    std::cout << "~End~\n";
    dialogue.dialogueContinue();
  } else {
    std::cout << "Fred died, and everything went to disaster.\n";
    dialogue.dialogueContinue();

    std::cout << "I wish I can turn back time.\n";
    dialogue.dialogueContinue();

    std::cout << "I wish I can make the right choices...\n";
    dialogue.dialogueContinue();

    std::cout << "~Game Over~\n";
    dialogue.dialogueContinue();
    saveGame();
    system("clear");
    printMainMenu();
  }
}
bool GameStateManager::saveGame() {
  std::string response;
  bool correctInput = false;

  while (!correctInput) {
    std::cout << "Do you want to save? (Yes or No)\n";


    bool correctInput = false;

    while (getline(std::cin, response)) {
      response = StringMagician::stringToLower(response);
      if (response == "yes"
          || response == "yeah"
          || response == "y"
          || response == "yee") {
        gameData.saveGame(GameStateManager::eventManager);

        std::cout << "Game saved.\n";
        dialogue.dialogueContinue();
        return true;
        correctInput = true;
      } else if (response == "no"
                 || response == "nope"
                 || response == "n"
                 || response == "nah") {
        correctInput = true;
        return false;
      } else {
        std::cout << "I don't understand what "
                  << "your saying can you repeat that?\n";
      }
    }
  }
}

