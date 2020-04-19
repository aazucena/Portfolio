/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Variant.h"
#include <iostream>
#include <string>


std::string Variant::getVarName() {
  return varName;
}

Variant* Variant::Generate(VariantType varType) {
  if (varType == V_A) {
    return new Variant("A");
  } else if (varType == V_D) {
    return new Variant("D");
  } else if (varType == V_R) {
    return new Variant("R");
  } else {
    return NULL;
  }
}
Variant::VariantType Variant::getVType() {
  if (getVarName() == "A") {
    return Variant::V_A;
  } else if (getVarName() == "R") {
    return Variant::V_R;
  } else if (getVarName() == "D") {
    return Variant::V_D;
  } else {
    throw "Error on initializing VariantType";
  }
}
