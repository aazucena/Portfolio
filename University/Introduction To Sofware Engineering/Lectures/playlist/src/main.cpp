#include "Playlist.h"
#include <iostream>

void list(Playlist* pl) {
  for(int i = 0; i < 10; i++) {
    const Song* s = pl->getSong();
    std::cout << s->name << std::endl;
  }
}

int main(int argc, char const *argv[]) {
  Playlist* pl = Playlist::greatest();

  std::cout << " ===== Default Ordering =====" << std::endl;
  list(pl);

  std::cout << std::endl << " ===== Random Order =====" << std::endl;
  //pl->setNumberGenerator(new Random());
  list(pl);

  return 0;
}
