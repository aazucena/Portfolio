#include <string>
#include "Date.h"
#include "gtest/gtest.h"

TEST(TestDate, constructorDateTest) {
  Date d("July", 3);

  EXPECT_EQ("July", d.getMonth());
  EXPECT_EQ(3, d.getDay());
}

