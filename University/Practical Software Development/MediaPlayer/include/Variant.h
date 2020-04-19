/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef VARIANT_H_INCLUDED
#define VARIANT_H_INCLUDED
#include <iostream>
#include <string>

class Variant {
 public:
  enum VariantType {V_A, V_R, V_D};
  Variant() {}
  Variant(std::string var): varName{var} {}
  virtual ~Variant() {}
  std::string getVarName();
  VariantType getVType();

  static Variant* Generate(VariantType varType);

 private:
  std::string varName;
};
#endif // VARIANT_H_INCLUDED
