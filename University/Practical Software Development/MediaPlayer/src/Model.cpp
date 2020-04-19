/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Model.h"
#include "Top.h"
#include "Bottom.h"
#include "Middle.h"
#include "Widget.h"
#include <iostream>
#include <string>
#include <vector>
Model::Model(std::string mdl): mdlName {mdl} {}

std::string Model::getModelName() {
  return mdlName;
}

std::vector<Widget*> Model::getWidgets() {
  return widgets;
}
void Model::addWidget(Widget* w) {
  widgets.push_back(w);
}
Model* Model::Generate(Model::ModelType mdlType) {
  if (mdlType == MDL_Bottom) {
    return new Bottom("Bottom");
  } else if (mdlType == MDL_Middle) {
    return new Middle("Middle");
  } else if (mdlType == MDL_Top) {
    return new Top("Top");
  } else {
    return NULL;
  }
}
