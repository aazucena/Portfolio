#include "Variant.h"
#include "MediaPlayer.h"
#include "gtest/gtest.h"

TEST(TestVariant, constructorTest) {
  Variant v("Test");
  EXPECT_EQ("Test", v.getVarName());
}
