#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Choice.h"

class Event {
 public:
  enum freeTimeType {MORNING, LUNCH, AFTERNOON, AFTERSCHOOL};

  Event() {}

  Event(std::string ev);

  /**
  * Constructor of Event.
  * @param ev Name of the Event ("Unknown").
  * @param d Date of the event.
  * @param f Showing what time in the day the Event is available. Either LUNCH or AFTERNOON
  */
  Event(std::string ev, Date d, freeTimeType f);

  /**
  * Destructor of Event.
  */
  virtual ~Event() {}

  /**
  * @return The name of the event.
  */
  std::string getEventName();

  /**
  * Get the Date of the event
  * @return A Date object that represents the date in the game
  */
  Date getDate();

  /**
  * Gets the enum depicting where in the day The event will be available
  * @return freeTimeType of when the event will appear
  */
  freeTimeType getWhenAvailable();

  /**
  * Gets the bool value checking if the Event will be available every day at lunch
  * @return bool checking if the Event will be available every day at lunch
  */
  bool isAvailableEverydayLunch();

  /**
  * Gets the bool value checking if the Event will be available every day after school
  * @return bool checking if the Event will be available every day after school
  */
  bool isAvailableEverydayAfterschool();

  /**
  * Sets the bool value depicting if the Event will be available every day at lunch
  * @param a bool value depicting if the Event will be available every day at lunch
  */
  void setAvailableLunch(bool a);

  /**
  * Sets the bool value depicting if the Event will be available every day at after school
  * @param a bool value depicting if the Event will be available every day after school
  */
  void setAvailableAfterschool(bool a);

  /**
  * Adds a sentence to the introduction to an Event
  * @param s String to add to the introduction sentence of an Event
  */
  void addIntroSentence(std::string s);

  /**
  * Prints out an introduction to the event and displays choices the player can choose
  * @return bool value depicting whether the Player lives or not
  */
  bool playEvent();

  /**
  * Adds a choice to the event.
  * @param c The Choice to add
  */
  void addChoice(Choice c);

  /**
  * Prints out the intro sentence to the Player
  */
  void printIntro();

  /**
  * Prints out all the choices and returns the Choice the Player picked
  * @return Choice the Player picked
  */
  Choice printChoicesAndGetResult();

  /**
  * Gets a class name based on a day
  * @param day int value of what day it is from initial
  * @return string of a class on a day
  */
  std::string getClass(int day);

 private:
  std::string eventName;

  Date date;

  bool availableLunch = false;
  bool availableAfterschool = false;
  freeTimeType ftt;

  std::vector<std::string> introSentences;
  std::vector<Choice> choices;
};
#endif // EVENT_H_INCLUDED

