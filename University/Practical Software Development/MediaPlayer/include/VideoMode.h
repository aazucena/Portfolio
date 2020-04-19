#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED
#include "ModeState.h"
#include <string>

class VideoMode : public ModeState {
 public:
  VideoMode(std::string vname): ModeState{vname} {}
  void onMode();

 private:
  ModeState *md_state;
};
#endif // VIDEO_H_INCLUDED
