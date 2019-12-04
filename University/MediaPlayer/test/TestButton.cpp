#include "Button.h"
#include "MediaPlayer.h"
#include "gtest/gtest.h"

TEST(TestButton, constructorTest) {
  Button b1("Test");
  EXPECT_EQ("Test", b1.getName());
}
