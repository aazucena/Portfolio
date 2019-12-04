/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef TOP_H_INCLUDED
#define TOP_H_INCLUDED
#include "Model.h"
#include <string>

class Top : public Model  {
 public:
  Top() {}
  Top(std::string tmdl): Model{tmdl} {}

  virtual ~Top() {}

  void printModel();

  void initModel();

 private:
};
#endif // TOP_H_INCLUDED
