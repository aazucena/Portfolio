/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef MIDDLE_H_INCLUDED
#define MIDDLE_H_INCLUDED
#include "Model.h"
#include <string>

class Middle : public Model {
 public:
  Middle() {}
  Middle(std::string mmdl): Model{mmdl} {}

  virtual ~Middle() {}
  void printModel();

  void initModel();

 private:
};
#endif // MIDDLE_H_INCLUDED
