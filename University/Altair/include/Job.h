#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED
#include <iostream>
#include <string>
#include "Character.h"
#include "Event.h"
#include "Date.h"
class Job: public Event {
 public:
  Job() {}

  Job(std::string jn): jobName(jn) {}

  virtual ~Job() {}

  /**
  * @return salary from the Job.
  */
  double getSalary();

  /**
  * Goes through a sequence of printout statements that will be shown to the Player
  * @return true as the Player shoudn't die here
  */
  bool playJob();

  /**
  * Returns the name of the current job the Player is in.
  * @return string of the job the Player is in
  */
  std::string getJobName();

 private:
  /**
  * Salary from the Job.
  */
  double salary = 15.5;
  std::string jobName;
};
#endif // JOB_H_INCLUDED
