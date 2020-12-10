#include "GoFish.h"
#include <vector>

int main() {
  GoFish game;
  std::cout << "Welcome to the Card Game called GoFish!!" << std::endl;

  Deck d;
  d.buildDeck();
  std::random_device rd;
  std::uniform_int_distribution<int> dis(0, 12);
  for (int i = 0; i < dis(rd); i ++) d.shuffle();
  game.setDeck(d);

  std::vector<GoFishUI*> views;
  views.push_back(new ByUser());
  views.push_back(new ByNPC());

  for (int i = 0; i < 2; i++) game.addPlayers(new Player());

  for (int i = 0; i < views.size(); i++) {
    game.setUI(views[i]);
    game.setPlayerData(i);
    if (i == 0) game.pressCont();
    game.display(i);
    if (i == 0) game.showHand(i);
  }
  game.pressCont();
  game.play(views);

  std::cout << "End Game Score: " << std::endl;
  for (int i = 0; i < views.size(); i++) {
    game.setUI(views[i]);
    game.display(i);
    game.showHand(i);
  }
  game.pressCont();
  game.checkScore();
  std::cout << "Thanks for playing the game!!!" << std::endl;

  return 0;
}
