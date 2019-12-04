#ifndef GAMESTATEMANAGER_H_INCLUDED
#define GAMESTATEMANAGER_H_INCLUDED

#include <string>
#include <iostream>
#include <locale>
#include "Player.h"
#include "Character.h"
#include "CharacterManager.h"
#include "GameDataManager.h"
#include "Event.h"
#include "EventManager.h"
#include "RoutineDialogueManager.h"
#include "Dialogue.h"

class GameStateManager {
 public:
  GameStateManager() {}
  virtual ~GameStateManager() {}

  /**
  * Loads up the Player and Characters as well as the day last saved.
  * @return bool if loading was successful or not
  */
  bool loadGame();

  /**
  * Prints out actions and events for a day
  * @return bool value depicting if the Player will die or not
  */
  bool playDay();

  /**
  * Prints out the tutorial for the game
  */
  void printTutorial();

  /**
  * Prints out the end for the game
  */
  void printEnd();

  /**
  * Prints out the main menu for the game
  * @return bool checking if Player wants to leave or fails initialization of the game
  */
  bool printMainMenu();

  /**
  * Prints out and goes through the introduction for the game
  * @return bool if Player succeeds going through introduction
  */
  bool newGame();

  /**
  * Prints out and asks if Player wants to save the game
  * @return bool if Player wants to save or not
  */
  bool saveGame();

  /**
  * Sets the EventManager in other words sets the current day for the game
  * @param em EventManager to set
  */
  void setEventManager(EventManager em);

  /**
  * Re-initializes EventManager so long as save file exists
  * @return EventManager
  */
  EventManager getEventManager();


 private:
  RoutineDialogueManager dialogueManager;
  CharacterManager characterManager;
  GameDataManager gameData;
  EventManager eventManager;
  Dialogue dialogue;
};
#endif // GAMESTATEMANAGER_H_INCLUDED
