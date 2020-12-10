#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_
#include "Card.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Player {
 public:
    Player() {}
    ~Player() {
      hand.clear();
    }

    void addCard(Card* c);
    void grabCards(std::vector<Card*> d);
    bool holds(std::string cRank);
    bool hasCards();
    Card* giveCard(std::string card);
    void dealCard();
    void bookCard(std::string card);

    std::vector<Card*>& playerHand();
    void addScore(int s);
    void changeName(std::string nm) { name = nm; }
    std::string getName() { return name; }
    int getScore() { return score; }

 private:
    std::vector<Card*> hand;
    int score = 0;
    std::string name = "";
    void sortHand() {
      std::sort(hand.begin(), hand.end(), [](Card* lhs, Card* rhs) {
        return lhs->getRank() < rhs->getRank();
      });
    }
};

#endif // INCLUDE_PLAYER_H_
