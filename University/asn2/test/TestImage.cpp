/*
*CPSC 2720 Fall 2019
*Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Image.h"
#include <string>
#include "gtest/gtest.h"
TEST(TestImage, constructor_test) {
  Coordinate c(10, 10);
  for (int x : {
         10, 5, 2000, -10, -2
       }) {
    for (int y : {
           10, 5, 2000, -10, -3
         }) {
      EXPECT_NO_THROW({Image img(c, x, y);});
    }
  }
}
TEST(TestImage, width_test) {
  Coordinate c(2, 1);
  for (int x : {
         10, 5, 2000, -10, -2
       }) {
    Image img(c, x, 10);
    EXPECT_EQ(x, img.getWidth());
  }
  Image img(c, 5, 19);
  EXPECT_EQ(5, img.getWidth());
}
TEST(TestImage, height_test) {
  Coordinate c(2, 1);
  for (int y : {
         10, 5, 2000, -10, -2
       }) {
    Image img(c, 10, y);
    EXPECT_EQ(y, img.getHeight());
  }
  Image img(c, 5, 19);
  EXPECT_EQ(19, img.getHeight());
}
TEST(TestImage, coord_test) {
  Coordinate c(2, 1);
  for (int x : {
         10, 5, 2000, -10, -2
       }) {
    for (int y : {
           10, 5, 2000, -10, -2
         }) {
      Image img(c, x, y);
      EXPECT_EQ(c, img.getLocation());
    }
  }
}
TEST(TestImage, errorVar_test) {
  Coordinate c(0, 0);
  EXPECT_ANY_THROW({Image img(c, 5, 0);});
  EXPECT_ANY_THROW({Image img(c, 0, 5);});
  EXPECT_ANY_THROW({Image img(c, 0, 0);});
}
TEST(TestImage, getAt_test) {
  Coordinate c(5, 1);
  Image img(c, 10, 10);
  EXPECT_EQ('I', img.getAt(c));
}
TEST(TestImage, bool_test) {
  Coordinate e(33, 25);
  Coordinate f(9, 11);
  Image img(e, 90, 5);
  EXPECT_TRUE(img.locatedAt(e));
  EXPECT_EQ(true, img.locatedAt(e));
  EXPECT_FALSE(img.locatedAt(f));
  EXPECT_EQ(false, img.locatedAt(f));
}
