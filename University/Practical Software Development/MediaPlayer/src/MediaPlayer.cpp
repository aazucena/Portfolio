/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "MediaPlayer.h"
#include "MediaPlayerFactory.h"
#include "Mode.h"
#include "Model.h"
#include "Variant.h"
#include <iostream>

MediaPlayer::MediaPlayer() {}

MediaPlayer::~MediaPlayer() {}

void MediaPlayer::run() {
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
  int c1;
  int c2;
  int c3;

  std::cout << "Choose your model: \n";
  std::cout << "1. Top \n";
  std::cout << "2. Middle \n";
  std::cout << "3. Bottom \n";
  std::cin >> c1;
  val1 = choices(c1);

  std::cout << "Choose your mode: \n";
  std::cout << "1. MP3 \n";
  std::cout << "2. VIDEO \n";
  std::cout << "3. RADIO \n";
  std::cin >> c2;
  val2 = choices(c2);

  std::cout << "Choose your variant: \n";
  std::cout << "1. VARIANT A \n";
  std::cout << "2. VARIANT R \n";
  std::cout << "3. VARIANT D \n";
  std::cin >> c3;
  val3 = choices(c3);

  MediaPlayerFactory *midi = new MediaPlayerFactory(c1, c2, c3);
  Model *model = midi->getModel();
  Mode *mode = midi->getMode();
  mode->onMode();
  model->initModel();
}
int MediaPlayer::choices(int choices) {
  switch (choices) {
  case 1:
    return 1;
    break;
  case 2:
    return 2;
    break;
  case 3:
    return 3;
    break;
  default:
    break;
  }
}

