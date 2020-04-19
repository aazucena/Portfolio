#ifndef EVENTMAKER_H_INCLUDED
#define EVENTMAKER_H_INCLUDED

#include <string>
#include <iostream>
#include "Dialogue.h"
#include "StringMagician.h"
#include "Event.h"
#include "Choice.h"

/**
* This class' function is to create static events for EventManager.
* Methods are based on specific days.
*/
class EventMaker {
 public:
  EventMaker() {}

  virtual ~EventMaker() {}

  Event secondDayMorning();
  Event secondDayLunch();
  Event secondDayAfternoon();
  Event secondDayAfterSchool();

  Event thirdDayMorning();
  Event thirdDayLunch();
  Event thirdDayAfternoon();
  Event thirdDayAfterSchool();

  Event fourthDayMorning();
  Event fourthDayLunch();
  Event fourthDayAfternoon();
  Event fourthDayAfterSchool();

  Event fifthDayMorning();
  Event fifthDayLunch();
  Event fifthDayAfternoon();
  Event fifthDayAfterSchool();

  Event sixthDayMorning();
  Event sixthDayLunch();
  Event sixthDayAfternoon();
};

#endif // EVENTMAKER_H_INCLUDED
