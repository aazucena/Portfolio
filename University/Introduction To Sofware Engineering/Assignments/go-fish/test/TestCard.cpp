#include "Card.h"
#include "gtest/gtest.h"

TEST(TestCard, constructorTest) {
  Card c("test1", "test2");
  EXPECT_EQ("test1", c.getRank());
  EXPECT_EQ("test2", c.getSuit());
}
