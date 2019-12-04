#ifndef EVENTMANAGER_H_INCLUDED
#define EVENTMANAGER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Event.h"
#include "EventMaker.h"

class EventManager {
 public:
  /**
  * Constructor of Event Manager.
  */
  EventManager();

  /**
  * Destructor of Event Manager.
  */
  virtual ~EventManager() {}

  /**
  * gets the event from the vector based on it's name
  * @param e The specified Event
  * @return Desired event by name
  */
  Event getEvent(Event e);

  /**
  * @return The events in the Event Manager.
  */
  std::vector<Event> getEvents();

  /**
  * Get events available on that day for lunch
  * @return vector of Events by day at lunchtime
  */
  std::vector<Event> getAvailableLunchEvents();

  /**
  * Get events available on that day after school
  * @return vector of Events by day after school
  */
  std::vector<Event> getAvailableAfterschoolEvents();

  /**
  * Get events available on that day for the morning
  * @return vector of Events by day in the morning
  */
  std::vector<Event> getAvailableMorningEvents();

  /**
  * Get events available on that day for the afternoon
  * @return vector of Events by day in the afternoon
  */
  std::vector<Event> getAvailableAfternoonEvents();

  /**
  * Prints available events and has player choose one
  * @return chosen event
  */
  bool printEventsAndGetChosenEvent(Event::freeTimeType f);

  /**
  * Add an Event the Player can choose
  * @param ev the event to add
  * @exception event_operation_failed_error Thrown if \a evis a duplicate of existing event
  */
  void addEvent(Event ev);

  /**
  * Increment day counter by 1.
  * Day counter starts at 1.
  */
  void nextDay();

  /**
  * Gets current for the game
  * @return The current day
  */
  int getCurrentDay();

  /**
  * Sets the day for the game
  * @param day The day the game will be set to
  */
  void setCurrentDay(int day);

 private:
  std::vector<Event> events;

  void initializeEvents();

  int dayCounter = 1; // Set to 1 for now

  EventMaker eMaker;
};

#endif // EVENTMANAGER_H_INCLUDED
