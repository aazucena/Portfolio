#include "Job.h"
#include "Player.h"
#include "Dialogue.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <iostream>
#include <string>
#include <iomanip>

double Job::getSalary() {
  return Job::salary;
}
std::string Job::getJobName() {
  return Job::jobName;
}

bool Job::playJob() {
  Dialogue d;
  Player* p = Player::getInstance();

  if (p->getJob() == "Home") {
    std::cout << "I don't have a job, so I'll go home."
              << std::endl;
    d.dialogueContinue();
    return true;
  }
  std::cout << "I went to my job for"
  << p->getJob()
  << " and had a rough time...";
  d.dialogueContinue();

  std::cout << std::setprecision(2)
       << std::fixed
       << "I got $"
       << getSalary()
       << " as my pay and then head home";
  d.dialogueContinue();

  double currentMoney = p->getMoney();
  p->setMoney(currentMoney + getSalary());

  return true;
}

