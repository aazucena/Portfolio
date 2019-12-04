/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Mode.h"
#include "Variant.h"
#include "ModeState.h"
#include "Mp3Mode.h"
#include "VideoMode.h"
#include "RadioMode.h"
#include <iostream>
#include <string>

void Mode::setMode(ModeType m, Variant::VariantType vtype) {
  if (m == MP3 && (vtype == Variant::V_A
                   || vtype == Variant::V_D)) {
    md_state = new Mp3Mode("MP3");
  } else if (m == VIDEO && (vtype == Variant::V_A
                            || vtype == Variant::V_D)) {
    md_state = new VideoMode("Video");
  } else if (m == RADIO && (vtype == Variant::V_A
                            || vtype == Variant::V_R)) {
    md_state = new RadioMode("Radio");
  } else {
    md_state = NULL;
  }
}


void Mode::onMode() {
  md_state->onMode();
}

Mode::ModeType Mode::getModeType() {
  if (md_state->getModeName() == "MP3") {
    return Mode::MP3;
  } else if (md_state->getModeName() == "Radio") {
    return Mode::RADIO;
  } else if (md_state->getModeName() == "Video") {
    return Mode::VIDEO;
  } else {
    throw "No such type";
  }
}




