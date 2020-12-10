#ifndef INCLUDE_GOFISH_H_
#define INCLUDE_GOFISH_H_
#include "Deck.h"
#include "Player.h"
#include "GoFishUI.h"
#include <vector>

class GoFish {
 public:
    GoFish() {}
    ~GoFish() {
      players.clear();
    }

    /**
    * Sets up the new game
    **/
    void play(std::vector<GoFishUI*> views);
    void setUI(GoFishUI* interface);
    void setDeck(Deck d);
    void setPlayerData(int i);
    void addPlayers(Player *p);
    void display(int i);
    void showHand(int i);
    void deal(int i);
    void tally(int i);
    void checkScore();
    /**
    * Unecessary "Press any key to continue" function
    **/
    void pressCont();

 private:
    Deck doc;
    std::vector<Player*> players;
    GoFishUI* ui;
};

#endif // INCLUDE_GOFISH_H_
