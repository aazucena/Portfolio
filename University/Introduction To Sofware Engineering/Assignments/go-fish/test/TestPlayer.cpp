#include "Player.h"
#include "Deck.h"
#include "gtest/gtest.h"

TEST(TestPlayer, testConstructor) {
  Player p;
  p.changeName("test1");
  EXPECT_EQ("test1", p.getName());

  p.changeName("test2");
  EXPECT_EQ("test2", p.getName());
}

TEST(TestPlayer, testScore) {
  Player p;
  p.changeName("test3");
  p.addScore(0);
  EXPECT_EQ(0, p.getScore());

  p.addScore(2);
  EXPECT_EQ(2, p.getScore());

  p.addScore(5);
  EXPECT_EQ(7, p.getScore());
}

TEST(TestPlayer, testHand) {
  Player p;
  Player o;
  p.changeName("TestDealer");
  o.changeName("TestDealee");
  Deck d;
  d.buildDeck();
  p.grabCards(d.deckOfCards());
  o.grabCards(d.deckOfCards());
  EXPECT_TRUE(p.holds("A"));
  EXPECT_FALSE(p.holds("jhflkas"));

  p.addCard(new Card("test", "test"));
  EXPECT_TRUE(p.holds("test"));

  for (Card* c : p.playerHand()) EXPECT_TRUE(p.holds(c->getRank()));

  o.addCard(p.giveCard("test"));
  EXPECT_TRUE(o.holds("test"));

  EXPECT_TRUE(p.hasCards());
}
TEST(TestPlayer, testPlayerActions) {
  Player p;
  p.changeName("TestDealer");
  Deck d;
  d.buildDeck();
  p.grabCards(d.deckOfCards());

  EXPECT_NO_THROW({ p.dealCard(); });
}
