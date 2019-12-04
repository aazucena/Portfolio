#include <vector>
#include <string>
#include <iostream>
#include "Choice.h"
#include "gtest/gtest.h"

TEST(TestChoice, choiceBuildAliveTest) {
  Choice c("I will eat", true);
  c.addResultSentence("I eat");

  EXPECT_TRUE(c.playChoice());
}

TEST(TestChoice, choiceBuildDeathTest) {
  Choice c("I will not eat", false);
  c.addResultSentence("I starve");

  EXPECT_FALSE(c.playChoice());
}
