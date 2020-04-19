#include <string>
#include "StringMagician.h"
#include "gtest/gtest.h"

TEST(TestStringMagician, stringToLowerTest) {
  std::string upperString = "HYPER STRING";

  std::string lowerString = StringMagician::stringToLower(upperString);

  EXPECT_EQ("hyper string", lowerString);
}
