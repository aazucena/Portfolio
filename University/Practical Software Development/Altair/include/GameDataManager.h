#ifndef GAMEDATAMANAGER_H_INCLUDED
#define GAMEDATAMANAGER_H_INCLUDED

#include <iostream>
#include <string>
#include "FileManager.h"
#include "Player.h"
#include "Character.h"
#include "CharacterManager.h"

class GameDataManager {
 public:
  GameDataManager() {}
  virtual ~GameDataManager() {}

  /**
  * Collect all data to be persisted and sends it to FileWriter to write to external file
  * @param em To save the day of the game
  */
  void saveGame(EventManager em);

  /**
  * Re-initializes the game from the save files
  * @return bool whether the game loads correctly
  */
  bool loadGame();

  /**
  * Re-initializes the day the Player saved at
  */
  EventManager loadEventManager();

  /**
  * Initializes the Character data at startup
  * @return bool True if save file found. False if not found.
  */
  bool initializeCharacters();

  /**
  * Prints out and sets up a new player
  * @return bool value if Player setup was successful
  */
  bool setupPlayer();

 private:
  FileManager fileManager;
};
#endif // GAMEDATAMANAGER_H_INCLUDED
