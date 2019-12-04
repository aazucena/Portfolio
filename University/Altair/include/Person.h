#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>

class Person {
 public:
  Person() {}
  Person(std::string fn, std::string ln, char g);

  virtual ~Person() {}

  /**
  *Sets first name of a Person
  *@param fn, first Name of a Person
  */
  void setFirstName(std::string fn);

  /**
  *sets the last name of a Person
  *@param ln, last name of a Person
  */
  void setLastName(std::string ln);

  /**
  *sets the gender of a Person
  *@param gender, gender of a Person
  */
  void setGender(char g);

  /**
  *gets the first name of a Person
  *@return the first name
  */
  std::string getFirstName();

  /**
  *gets the last name of a Person
  *@return the last name
  */
  std::string getLastName();

  /**
  *gets the gender of the Person
  *@return the gender
  */
  char getGender();

  /**
  *outputs male or female depending on gender
  *@return string representation of gender
  */
  std::string getGenderString();

 private:
  std::string firstName;

  std::string lastName;

  char gender;
};

#endif // PERSON_H_INCLUDED
