#ifndef ROUTINEDIALOGUEMANAGER_H_INCLUDED
#define ROUTINEDIALOGUEMANAGER_H_INCLUDED

#include "Player.h"
#include "Character.h"
#include <iostream>
#include <string>


class RoutineDialogueManager {
 public:
  RoutineDialogueManager() {}

  virtual ~RoutineDialogueManager() {}

  /**
  * Prints the start of day
  * @return true
  */
  bool printStartOfDay(int day);

  /**
  * Prints the Lunch time dialogue
  * @return true
  */
  bool printLunchRoutine(int day);

  /**
  * Prints the afternoon for a day
  * @return true
  */
  bool printAfternoonRoutine(int day);

  /**
  * Prints the after school dialogue
  * @return true
  */
  bool printAfterSchoolRoutine(int day);

  /**
  * Prints the end of the day
  * @return true
  */
  bool printEndOfDay(int day);
};

#endif // ROUTINEDIALOGUEMANAGER_H_INCLUDED
