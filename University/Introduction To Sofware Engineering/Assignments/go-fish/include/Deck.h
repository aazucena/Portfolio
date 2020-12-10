#ifndef INCLUDE_DECK_H_
#define INCLUDE_DECK_H_
#include "Card.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Deck {
 public:
    Deck() { }
    ~Deck() {
      cards.clear();
    }

    void buildDeck();
    void shuffle();
    void deckState(std::vector<Card*> c) { cards = c; }
    std::vector<Card*> deckOfCards() { return cards; }

 private:
    std::vector<Card*> cards;
    std::vector<std::string> ranks =
    {"A", "2", "3", "4",
    "5", "6", "7", "8", "9",
    "10", "J", "Q", "K"};
    std::vector<std::string> suits =
    {"CLUB", "SPADE",
    "HEART", "DIAMOND"};
};

#endif // INCLUDE_CARDS_H_
