#ifndef RUMMY_H
#define RUMMY_H

#include <Game.h>
#include <vector>
#include <stack>
#include <list>

class Rummy : public Game {
 public:
    Rummy(GameUI* interface, Deck* d) : Game(interface, d) {}
    virtual ~Rummy() {
      while (!discardPile.empty()) {
        delete discardPile.top();
        discardPile.pop();
      }

      for (std::list<Card*>* st : set)
        for (Card* c : (*st))
          delete c;

      for (std::list<Card*>* st : seq)
        for (Card* c : (*st))
          delete c;
    }

    void dealCards(std::vector<Player*> p);
    void beforeCardPlayed(unsigned int playerNum, unsigned int numPlayers);
    void afterCardPlayed(Player* currentPlayer, std::vector<Player*> players,
                             Card* played);
    bool turnOver();
    void start();
    bool isLayoff(Card* c);
    int getPoints(Card* c);

 private:
      std::vector<std::list<Card*>*> set, seq;
      std::stack<Card*> discardPile;
};

#endif // RUMMY_H
