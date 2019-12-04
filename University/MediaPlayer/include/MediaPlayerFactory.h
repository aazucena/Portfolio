/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef MEDIAPLAYERFACTORY_H_INCLUDED
#define MEDIAPLAYERFACTORY_H_INCLUDED
#include "Mode.h"
#include "Model.h"
#include "Variant.h"
#include <iostream>

class MediaPlayerFactory {
 public:
  MediaPlayerFactory(int c1, int c2, int c3);
  virtual ~MediaPlayerFactory();
  Mode *getMode();
  Variant *getVariant();
  Model *getModel();

 private:
  Mode *mode;
  Variant *vset;
  Model *mdl;
};
#endif // MEDIAPLAYERFACTORY_H_INCLUDED
