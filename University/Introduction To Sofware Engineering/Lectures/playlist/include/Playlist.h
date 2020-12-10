#include "NumberGenerator.h"
#include <vector>
#include <string>

/**
* A song to be played.
*/
class Song {
public:
  Song(std::string n) : name(n) {}
  const std::string name;
};

/**
* A list of songs to play.
*/
class Playlist {
public:
  Playlist() : rng(new Sequential()){}
  ~Playlist(){}

  /**
  * Setter dependency injection.
  */
  void setNumberGenerator(NumberGenerator* g) {
    rng = g;
  }

  /**
  * Add an item to the list.
  */
  void add(const Song* s) {
    songs.push_back(s);
  }

  /**
  * Get an item.
  * (Uses the dependency object.)
  */
  const Song* getSong() const {
    unsigned int track = rng->getNum(songs.size());
    return songs[track];
  }

  /**
  * The greatest songs accordingToRollingStone magazine.
  *
  * From https://www.rollingstone.com/music/music-lists/
  * 500-greatest-songs-of-all-time-151127/john-lennon-imagine-38368
  */
  static Playlist* greatest() {

    Song* accordingToRollingStone[] = {
      new Song("Like a Rolling Stone"),
      new Song("(I Can't Get No) Satisfaction"),
      new Song("Imagine"),
      new Song("What's Going On"),
      new Song("Respect"),
      new Song("Good Vibrations"),
      new Song("Johnny B. Goode"),
      new Song("Hey Jude"),
      new Song("Smells Like Teen Spirit"),
      new Song("What'd I Say"),
    };

    Playlist* pl = new Playlist();
    for(const Song* s : accordingToRollingStone) {
      pl->add(s);
    }
    return pl;
  }

private:
  std::vector<const Song*> songs;
  NumberGenerator* rng;
};
