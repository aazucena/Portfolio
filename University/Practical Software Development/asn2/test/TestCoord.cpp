/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Coordinate.h"
#include <sstream>
#include <string>
#include "gtest/gtest.h"
TEST(TestCoord, constructor_test) {
  for (int x : {
         10, 10, 200, -15, 2, -10, 10, 0, -5
       }) {
    for (int y : {
           5, -9, 20, 102, 25, -11, 10, 0, 5
         }) {
      EXPECT_NO_THROW({Coordinate c(x, y);});
    }
  }
  Coordinate c;
  Coordinate d(0, 0);
  EXPECT_TRUE(d == c);
  std::stringstream out;
  out << c;
  EXPECT_EQ("[0,0]", out.str());
}
TEST(TestCoord, bool_test) {
  Coordinate c(3, 3);
  Coordinate d(2, 3);
  Coordinate e(3, 3);
  EXPECT_TRUE(e == c);
  EXPECT_TRUE(c != d);
  EXPECT_FALSE(c == d);
  EXPECT_FALSE(e != c);
}
TEST(TestCoord, notEqual_Test) {
  Coordinate a(10, 3);
  Coordinate b(2, 10);
  Coordinate c(10, 3);
  EXPECT_TRUE(a != b);
  EXPECT_TRUE(c != b);
  EXPECT_FALSE(a != c);
}
TEST(TestCoord, stringStream_test) {
  Coordinate c(3, 3);
  std::stringstream out;
  out << c;
  EXPECT_EQ("[3,3]", out.str());
}
