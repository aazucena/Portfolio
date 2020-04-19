#include "Choice.h"
#include "Event.h"
#include "EventManager.h"
#include "EventMaker.h"
#include "StringMagician.h"
#include "Job.h"
#include "Club.h"
#include "Dialogue.h"
#include "Hangout.h"
#include "HelperPerson.h"
#include "ItemShop.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <string>
#include <iostream>
#include <vector>


EventManager::EventManager() {
  initializeEvents();
}

int EventManager::getCurrentDay() {
  return dayCounter;
}

void EventManager::setCurrentDay(int day) {
  dayCounter = day;
}

void EventManager::nextDay() {
  if (EventManager::dayCounter < 7) {
    std::cout << "Day "
              << EventManager::dayCounter
              << " to "
              << "Day "
              << EventManager::dayCounter+1
              << std::endl;
  }
  dayCounter++;
}

Event EventManager::getEvent(Event e) {
  for (size_t i = 0; i < EventManager::events.size(); i++) {
    Event eventFromList = EventManager::events.at(i);

    if (e.getEventName() == eventFromList.getEventName()) {
      return eventFromList;
    }
  }
  Event notFound;
  return notFound;
}

std::vector<Event> EventManager::getEvents() {
  return events;
}

void EventManager::addEvent(Event ev) {
  events.push_back(ev);
}

std::vector<Event> EventManager::getAvailableMorningEvents() {
  Event::freeTimeType freeType = Event::MORNING;
  std::vector<Event> availableEvents;
  Event e;
  Date d;

  for (size_t i = 0; i < EventManager::events.size(); i++) {
    e = EventManager::events.at(i);
    d = e.getDate();

    if (d.getDay() == EventManager::getCurrentDay()
        && e.getWhenAvailable() == freeType) {
      availableEvents.push_back(e);
    }
  }
  return availableEvents;
}

std::vector<Event> EventManager::getAvailableLunchEvents() {
  Event::freeTimeType freeType = Event::LUNCH;
  std::vector<Event> availableEvents;
  Event e;
  Date d;

  for (size_t i = 0; i < EventManager::events.size(); i++) {
    e = EventManager::events.at(i);
    d = e.getDate();

    if (d.getDay() == getCurrentDay() && e.getWhenAvailable() == freeType) {
      availableEvents.push_back(e);
    }
  }
  return availableEvents;
}

std::vector<Event> EventManager::getAvailableAfternoonEvents() {
  Event::freeTimeType freeType = Event::AFTERNOON;
  std::vector<Event> availableEvents;
  Event e;
  Date d;

  for (size_t i = 0; i < EventManager::events.size(); i++) {
    e = EventManager::events.at(i);
    d = e.getDate();

    if (d.getDay() == getCurrentDay() && e.getWhenAvailable() == freeType) {
      availableEvents.push_back(e);
    }
  }
  return availableEvents;
}

std::vector<Event> EventManager::getAvailableAfterschoolEvents() {
  Event::freeTimeType freeType = Event::AFTERSCHOOL;
  std::vector<Event> availableEvents;
  Event e;
  Date d;

  for (size_t i = 0; i < EventManager::events.size(); i++) {
    e = EventManager::events.at(i);
    d = e.getDate();

    if ((d.getDay() == getCurrentDay()
         && e.getWhenAvailable() == freeType)
        || e.isAvailableEverydayAfterschool()) {
      availableEvents.push_back(e);
    }
  }
  return availableEvents;
}

bool EventManager::printEventsAndGetChosenEvent(Event::freeTimeType f) {
  std::vector<Event> evs;
  std::string dontCareInput;
  std::string response;
  Dialogue speak;

  if (f == Event::freeTimeType::MORNING) {
    evs = getAvailableMorningEvents();
  }

  if (f == Event::freeTimeType::LUNCH) {
    evs = getAvailableLunchEvents();
  }

  if (f == Event::freeTimeType::AFTERNOON) {
    evs = getAvailableAfternoonEvents();
  }

  if (f == Event::freeTimeType::AFTERSCHOOL) {
    evs = getAvailableAfterschoolEvents();
  }

  Event e;
  std::cout << "Currently I can go to..."
            << std::endl;

  // Print out choices
  for (size_t i = 0; i < evs.size(); i++) {
    e = evs.at(i);
    std::cout << e.getEventName() << std::endl;
  }

  if (Event::freeTimeType::AFTERSCHOOL == f && dayCounter != 5) {
    std::cout << "Club"
              << std::endl;
    std::cout << "Hangout"
              << std::endl;
    if (dayCounter != 2) {
      std::cout << "Job" << std::endl;
    }
    if (dayCounter > 3) {
      std::cout << "Shop" << std::endl;
    }
  }
  std::string eventName;
  bool correctInput = false;

  // Compare results and return if found otherwise keep asking till valid
  while (!correctInput) {
    getline(std::cin, response);
    std::cin.ignore();
    Player* p = Player::getInstance();
    response = StringMagician::stringToLower(response);
    if (dayCounter != 2 && (response == "job"
                            || response == "go to job"
                            || response == "j")) {
      Job j(p->getJob());
      return j.playJob();
    } else if (response == "hangout"
               || response == "hangout with someone"
               || response == "h") {
      Hangout h;
      return h.playHangout();
    } else if (response == "club"
               || response == "go to club"
               || response == "c") {
      Club c(p->getClub());
      return c.playClub();
    } else if (dayCounter > 3 && (response == "club"
                                  || response == "go to club"
                                  || response == "c")) {
      ItemShop it;
      return it.displayShop();
    }

    for (size_t i = 0; i < evs.size(); i++) {
      e = evs.at(i);
      eventName = StringMagician::stringToLower(e.getEventName());

      if (eventName.find(response) != std::string::npos) {
        correctInput = true;
        return e.playEvent();
      }
    }
    // Didn't find a match
    std::cout << "You wish you can do it, but you're human...\n" << std::endl;
    speak.dialogueContinue();
  }
}

void EventManager::initializeEvents() {
  // Day 2 Events
  addEvent(eMaker.secondDayMorning());
  addEvent(eMaker.secondDayLunch());
  addEvent(eMaker.secondDayAfternoon());
  addEvent(eMaker.secondDayAfterSchool());

  // Day 3 Events
  addEvent(eMaker.thirdDayMorning());
  addEvent(eMaker.thirdDayLunch());
  addEvent(eMaker.thirdDayAfternoon());
  addEvent(eMaker.thirdDayAfterSchool());

  // Day 4 Events
  addEvent(eMaker.fourthDayMorning());
  addEvent(eMaker.fourthDayLunch());
  addEvent(eMaker.fourthDayAfternoon());
  addEvent(eMaker.fourthDayAfterSchool());

  // Day 5 Events
  addEvent(eMaker.fifthDayMorning());
  addEvent(eMaker.fifthDayLunch());
  addEvent(eMaker.fifthDayAfternoon());
  addEvent(eMaker.fifthDayAfterSchool());

  // Day 6 Events
  addEvent(eMaker.sixthDayMorning());
  addEvent(eMaker.sixthDayLunch());
  addEvent(eMaker.sixthDayAfternoon());
}


