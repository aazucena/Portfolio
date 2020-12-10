#include "Deck.h"
#include "gtest/gtest.h"

TEST(TestDeck, shuffleTest) {
  Deck d1, d2;
  d1.buildDeck();
  d2.buildDeck();
  d2.shuffle();
  bool result = false;
  for (int i = 0; i < d1.deckOfCards().size(); i++)
    if (d1.deckOfCards()[i] == d2.deckOfCards()[i])
      result = true;
  EXPECT_FALSE(result);
}
