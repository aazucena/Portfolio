#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <string>

class Date {
 public:
  /**
  * Constructor of Date.
  * @param m The month in Date.
  * @param d The day in Date.
  */
  Date();
  Date(std::string m, int d);// Set d to -1 if availableEveryday = true

  /**
  * Destructor of Date.
  */
  virtual ~Date();

  /**
  * @return the month in date
  */
  std::string getMonth();

  /**
  * @return the day in date
  */
  int getDay();


 private:
  /**
  * Month in Date.
  */
  std::string month;

  /**
  * Day in Date.
  */
  int day;
};
#endif // DATE_H_INCLUDED
