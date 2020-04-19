#ifndef MP3_H_INCLUDED
#define MP3_H_INCLUDED
#include "ModeState.h"
#include <string>

class Mp3Mode : public ModeState {
 public:
  Mp3Mode(std::string m_name): ModeState{m_name} {}
  void onMode();

 private:
  ModeState *md_state;
};
#endif // MP3_H_INCLUDED
