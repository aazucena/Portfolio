/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "MediaPlayerFactory.h"
#include "MediaPlayer.h"
#include "Mode.h"
#include "Mp3Mode.h"
#include "VideoMode.h"
#include "RadioMode.h"
#include "Model.h"
#include "Variant.h"
#include <iostream>

MediaPlayerFactory::MediaPlayerFactory(int c1, int c2, int c3) {
  Model::ModelType model;
  Mode::ModeType mtype;
  Variant::VariantType vtype;
  switch (c1) {
  case 1:
    model = Model::MDL_Top;
    break;
  case 2:
    model = Model::MDL_Middle;
    break;
  case 3:
    model = Model::MDL_Bottom;
    break;
  default:
    throw "Error on Model";
    break;
  }
  switch (c2) {
  case 1:
    mtype = Mode::MP3;
    break;
  case 2:
    mtype = Mode::VIDEO;
    break;
  case 3:
    mtype = Mode::RADIO;
    break;
  default:
    throw "Error on Model";
    break;
  }
  switch (c3) {
  case 1:
    vtype = Variant::V_A;
    break;
  case 2:
    vtype = Variant::V_R;
    break;
  case 3:
    vtype = Variant::V_D;
    break;
  default:
    throw "Error on Model";
    break;
  }

  mdl = Model::Generate(model);
  vset = Variant::Generate(vtype);
  mode->setMode(mtype, vtype);
}

MediaPlayerFactory::~MediaPlayerFactory() {
  if (vset) {
    delete[] vset;
    vset = NULL;
  }
  if (mdl) {
    delete[] mdl;
    mdl = NULL;
  }
  if (mode) {
    delete[] mode;
    mode = NULL;
  }
}
Model *MediaPlayerFactory::getModel() {
  return mdl;
}

Variant *MediaPlayerFactory::getVariant() {
  return vset;
}

Mode *MediaPlayerFactory::getMode() {
  return mode;
}


