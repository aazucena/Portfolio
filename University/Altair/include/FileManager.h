#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string>
#include "Character.h"
#include "EventManager.h"
#include "CharacterManager.h"
#include "Player.h"
#include "Stat.h"

class FileManager {
 public:
  FileManager() {}
  virtual ~FileManager() {}

  /**
  * saves the game
  * @return true if game saves
  */
  bool writeSaveFile(EventManager ev);

  /**
  * loads the character save
  * @return the character save
  */
  bool readCharacterSave();

  /**
  * loads the character save
  * @return the character save
  */
  bool readItemSave();

  /**
  * loads the players save
  */
  bool readPlayerSave();

  /**
  * reads the starting character file
  * @return the initial character file
  */
  bool readInitCharacterFile();

  /**
  * reads the event file
  */
  bool readEventSave();

  /**
  * reads the event file
  */
  EventManager getEventFile();

  /**
  * This method changes a string from a save file into a format that will be usable for the program
  * @return val string value that is reformatted
  */
  std::string formatReadFile(std::string val);

  /**
  * This method changes a string into a format that will be readable for loading
  * @return val string value that is reformatted
  */
  std::string formatSaveFile(std::string val);
};

#endif // FILEMANAGER_H_INCLUDED
