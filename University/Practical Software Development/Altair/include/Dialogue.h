#ifndef DIALOGUE_H_INCLUDED
#define DIALOGUE_H_INCLUDED
#include "Player.h"
#include "Character.h"
#include <iostream>
#include <string>
class Dialogue {
 public:
  Dialogue() {}

  ~Dialogue() {}
  void dialogueContinue();

  /**
  * Takes in a folder path + filename, prefixed with "src/dialogue",
  * and obtains the line inside the file.
  * @param file string of the path name + filename of a text file
  * @return string of all text in textfile
  */
  std::string printFromFile(std::string file);

  /**
  * Takes in a string and replaces a word inside it with another and bolds it
  * @param dialogue an entire string line
  * @param search string of the word inside a sentence to search for
  * @param replace string to replace the search string
  * @return string that had one word replaced with a bolded one
  */
  std::string highlightWord(std::string dialogue,
                            const std::string& search,
                            const std::string& replace);

  /**
  * The format to display to screen.
  * Takes in someone's name and whatever that person will say.
  * @param name string name of a person
  * @param dialogue string of what a person will say
  */
  void printDialogue(std::string name, std::string dialogue);

  /**
  * Dialogue to be printed to screen.
  * @param dialogue string to be printed to screen.
  */
  void printDialogue(std::string dialogue);

  /**
  * Gets a string formatted into what will be displayed onto screen.
  * @param name string name of a person
  * @param dialogue string of what a person will say
  * @return string formatted into what will be printed out
  */
  std::string getDialogue(std::string name, std::string dialogue);

  /**
  * Formats a string into something that will be displayable on screen.
  * @param dialogue the string to be formatted into displayable text
  * @return string formatted into displayable text
  */
  std::string getDialogue(std::string dialogue);
};

#endif // DIALOGUE_H_INCLUDED
