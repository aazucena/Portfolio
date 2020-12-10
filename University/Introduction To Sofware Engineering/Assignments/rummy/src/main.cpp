#include "Deck.h"
#include "GoFishUI.h"
#include "GoFish.h"
#include "RummyUI.h"
#include "Rummy.h"

int main() {
    Deck* d = new Deck();
    d->createStandard();

    bool valid = false;
    char choice;
    GameUI* ui;
    Game* g;
    do {
      std::cout << "Choose the Game you want to play: \n"
                << "1. GoFish \n"
                << "2. Rummy" << std::endl;
      std::cout << "Select a choice: ";
      std::cin >> choice;

      switch (choice) {
        case '1':
          ui = new GoFishUI();
          g = new GoFish(ui, d);
          valid = true;
          break;
        case '2':
          ui = new RummyUI();
          g = new Rummy(ui, d);
          valid = true;
          break;
        default:
          std::cout << "Wrong INPUT!!!! TRY AGAIN!!!" << std::endl;
          break;
        }
  } while (valid != true);
    g->addPlayer(new Player("John"));
    g->addPlayer(new Player("Danielle"));
    g->addPlayer(new Player("Tara"));
    g->addPlayer(new Player("Erik"));
    g->addPlayer(new Player("Kira"));

    g->start();
}
