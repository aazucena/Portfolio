#include <string>
#include <vector>
#include "Person.h"
#include "Stat.h"
#include "Player.h"
#include "gtest/gtest.h"

TEST(TestPlayer, getStatTest) {
  Player* p = Player::getInstance();

  Stat* s = p->getStat("guts");

  EXPECT_EQ("guts", s->getStatName());
}

TEST(TestPlayer, playerDefaultTest) {
  Player* p = Player::getInstance();

  EXPECT_EQ("Avery", p->getFirstName());
  EXPECT_EQ("Doe", p->getLastName());
  EXPECT_EQ('m', p->getGender());
}
