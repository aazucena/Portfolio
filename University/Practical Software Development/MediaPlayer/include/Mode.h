/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef MODE_H_INCLUDED
#define MODE_H_INCLUDED
#include <iostream>
#include <string>
#include "ModeState.h"
#include "Variant.h"

class Mode {
 public:
  enum ModeType {MP3, VIDEO, RADIO};
  Mode();
  virtual ~Mode() {}
  void setMode(ModeType m, Variant::VariantType vtype);
  ModeType getModeType();
  void onMode();

 private:
  ModeState *md_state;
  Variant *v;
};
#endif // MODE_H_INCLUDED
