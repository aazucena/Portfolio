#ifndef GOFISH_H
#define GOFISH_H

#include <Game.h>
#include <list>
#include <vector>

class GoFish : public Game {
 public:
    GoFish(GameUI* interface, Deck* d) : Game(interface, d) {}
    virtual ~GoFish() {}

    void dealCards(std::vector<Player*> p);
    void beforeCardPlayed(unsigned int playerNum, unsigned int numPlayers);
    void afterCardPlayed(Player* currentPlayer, std::vector<Player*> players,
                         Card* played);
    bool turnOver();
    void start();
    bool hasSet(std::list<Card*>* hand);


 protected:
    unsigned int playerAsked = -1;

 private:
    const unsigned int NUM_CARDS_SMALL = 7;
    const unsigned int NUM_CARDS_LARGE = 5;
};

#endif // GOFISH_H
