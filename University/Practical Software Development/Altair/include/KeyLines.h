#ifndef KEYLINES_H_INCLUDED
#define KEYLINES_H_INCLUDED
#include "Player.h"
#include "Event.h"
#include "Item.h"
#include <string>

class KeyLines {
 public:
  KeyLines() {}

  /**
  * Constructor of Event.
  * @param ev Name of the Event ("Unknown").
  * @param d Date of the event.
  * @param f Showing what time in the day the Event is available. Either LUNCH or AFTERNOON
  * @param available bool value saying an event is available everyday
  */
  KeyLines(std::string name, std::string contents);

  /**
  * Destructor of Item.
  */
  virtual ~KeyLines() {}

  /**
  * Gets the the KeyLine sentence
  * @return strng of the KeyLine
  */
  std::string getKeyLines();

  /**
  * Gets the the KeyLine title
  * @return strng of the KeyLine title
  */
  std::string getKeyTitle();

  /**
  * Checks if a string contains a KeyWord
  * @param con The string to compare if it contains a KeyWord
  * @return bool determining if sentence contains KeyWord
  */
  bool containsKeyWord(std::string con);

  /**
  * Prints the special line to console.
  */
  void printKeyLine();

 private:
  /**
  * Name of The Event.
  */
  std::string textLine = "Hello World";
  /**
  * Name of The Event.
  */
  std::string textName = "Unknown";
};

#endif // KEYLINES_H_INCLUDED
