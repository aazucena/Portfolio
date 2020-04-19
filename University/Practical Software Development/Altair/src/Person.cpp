#include <string>
#include "Person.h"

Person::Person(std::string fn, std::string ln, char g):
  firstName{fn},
  lastName{ln},
  gender{g} {}

void Person::setFirstName(std::string fn) {
  firstName = fn;
}

void Person::setLastName(std::string ln) {
  lastName = ln;
}

void Person::setGender(char g) {
  gender = g;
}

std::string Person::getFirstName() {
  return firstName;
}

std::string Person::getLastName() {
  return lastName;
}

char Person::getGender() {
  return gender;
}

std::string Person::getGenderString() {
  if (gender == 'm' || gender == 'M') {
    return "Male";
  } else {
    return "Female";
  }
}
