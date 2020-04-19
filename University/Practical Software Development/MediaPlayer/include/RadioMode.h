#ifndef RADIO_H_INCLUDED
#define RADIO_H_INCLUDED
#include "ModeState.h"
#include <string>

class RadioMode : public ModeState {
 public:
  RadioMode(std::string rname): ModeState{rname} {}
  void onMode();

 private:
  ModeState *md_state;
};

#endif // RADIO_H_INCLUDED
