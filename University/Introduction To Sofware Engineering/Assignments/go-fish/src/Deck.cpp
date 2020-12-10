#include "Deck.h"

void Deck::buildDeck() {
    cards.reserve(52);
    for (int i = 0; i < suits.size(); i++) {
      for (int j = 0; j < ranks.size(); j++) {
        Card* c = new Card(ranks[j], suits[i]);
        cards.push_back(c);
      }
    }
}
void Deck::shuffle() {
    std::random_shuffle(cards.begin(), cards.end());
}
