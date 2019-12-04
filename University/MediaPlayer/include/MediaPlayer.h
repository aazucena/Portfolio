/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#ifndef MEDIAPLAYER_H_INCLUDED
#define MEDIAPLAYER_H_INCLUDED
#include <iostream>

class MediaPlayer {
 public:
  MediaPlayer();
  virtual ~MediaPlayer();
  void run();
  int choices(int choices);
};
#endif // MEDIAPLAYER_H_INCLUDED
