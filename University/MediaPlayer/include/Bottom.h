/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef BOTTOM_H_INCLUDED
#define BOTTOM_H_INCLUDED
#include "Model.h"
#include <vector>
#include <string>

class Bottom : public Model {
 public:
  Bottom() {}
  Bottom(std::string bmdl): Model{bmdl} {}

  virtual ~Bottom() {}

  void printModel();

  void initModel();
 private:
};
#endif // BOTTOM_H_INCLUDED
