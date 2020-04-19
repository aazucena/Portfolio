#ifndef MODESTATE_H_INCLUDED
#define MODESTATE_H_INCLUDED
#include <iostream>
#include <string>

class ModeState {
 public:
  ModeState();
  ModeState(std::string md): mode_name{md} {}
  virtual ~ModeState() {}
  std::string getModeName();
  virtual void onMode() = 0;

 private:
  std::string mode_name;
};
#endif // MODESTATE_H_INCLUDED
