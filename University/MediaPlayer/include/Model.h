/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED
#include "Widget.h"
#include <iostream>
#include <string>
#include <vector>

class Model {
 public:
  enum ModelType {MDL_Top, MDL_Bottom, MDL_Middle};
  Model() {}
  Model(std::string mdl);

  virtual ~Model() {}

  std::vector<Widget*> getWidgets();

  std::string getModelName();

  void addWidget(Widget* w);

  virtual void printModel() = 0;
  virtual void initModel() = 0;
  static Model* Generate(ModelType mdltype);

 private:
  std::string mdlName;
  std::vector<Widget*> widgets;
  Widget *wid;
};
#endif // MODEL_H_INCLUDED
