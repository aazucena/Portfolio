#include "Date.h"
#include "Event.h"
#include "Dialogue.h"
#include "Choice.h"
#include "StringMagician.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <iostream>
#include <string>

Event::Event(std::string ev): eventName{ev} {}
Event::Event(std::string ev, Date d, freeTimeType f):
    eventName{ev}, date{d}, ftt{f} {}

std::string Event::getEventName() {
  return Event::eventName;
}

Date Event::getDate() {
    return Event::date;
}

Event::freeTimeType Event::getWhenAvailable() {
    return Event::ftt;
}

bool Event::isAvailableEverydayLunch() {
    return Event::availableLunch;
}

bool Event::isAvailableEverydayAfterschool() {
    return Event::availableAfterschool;
}

void Event::setAvailableLunch(bool a) {
    Event::availableLunch = a;
}

void Event::setAvailableAfterschool(bool a) {
    Event::availableAfterschool = a;
}

void Event::addIntroSentence(std::string s) {
    Event::introSentences.push_back(s); // Sentence Building
}

void Event::addChoice(Choice c) {
    Event::choices.push_back(c);
}
std::string Event::getClass(int day) {
  if (day > 5) {
    day = (day % 5) + 1;
  }
  switch (day) {
  case 1:
    if (getWhenAvailable() == MORNING) {
      return "Math Class";
    }
    if (getWhenAvailable() == AFTERNOON) {
      return "Physics Class";
    }
    break;
  case 2:
    if (getWhenAvailable() == MORNING) {
      return "English Class";
    }
    if (getWhenAvailable() == AFTERNOON) {
      return "Social Class";
    }
    break;
  case 3:
    if (getWhenAvailable() == MORNING) {
      return "Chemistry Class";
    }
    if (getWhenAvailable() == AFTERNOON) {
      return "Biology Class";
    }
    break;
  case 4:
    if (getWhenAvailable() == MORNING) {
      return "Gym Class";
    }
    if (getWhenAvailable() == AFTERNOON) {
      return "Health Class";
    }
    break;
  case 5:
      return "Finals";
    break;
  default:
      return "No Class";
    break;
  }
}

bool Event::playEvent() {
    printIntro(); // Print introduction to the event
    Choice c = printChoicesAndGetResult(); // Get chosen option
    return c.playChoice();
}

void Event::printIntro() {
    std::string sentence;
    Dialogue d;

    for (size_t i = 0; i < Event::introSentences.size(); i++) {
        sentence = Event::introSentences.at(i);

        std::cout << sentence << std::endl;
        d.dialogueContinue();
    }
}

Choice Event::printChoicesAndGetResult() {
    std::string response;
    std::string choiceNameLower;
    Dialogue d;

    std::cout << "My choices are...\n";

    Choice c;

    // Print out choices
    for (size_t i = 0; i < Event::choices.size(); i++) {
        c = Event::choices.at(i);

        std::cout << c.getChoiceName() << std::endl;
    }

    // Compare results and return if found otherwise keep asking till valid
    bool correctInput = false;

    while (!correctInput) {
        // Get response from player
        getline(std::cin, response);

        // set response to lowercase
        response = StringMagician::stringToLower(response);

        for (size_t i = 0; i < Event::choices.size(); i++) {
            c = Event::choices.at(i);
            choiceNameLower = StringMagician::stringToLower(c.getChoiceName());

            if (choiceNameLower.find(response) != std::string::npos) {
                correctInput = true;
                return c;
            }
        }// Didn't find a match
        std::cout << "You wish you can do it, but you're human...\n";
        d.dialogueContinue();
    }
    return c;
}
