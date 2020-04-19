/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Textbox.h"
#include <string>
#include "gtest/gtest.h"
TEST(TestTextbox, constructor_test) {
  Coordinate c(10, 10);
  for (int x : {
         10, 5, 2000, -10, -2
       }) {
    for (int y : {
           10, 5, 2000, -10, -3
         }) {
      EXPECT_NO_THROW({Textbox txt(c, x, y);});
    }
  }
}
TEST(TestTextbox, width_test) {
  Coordinate c(2, 1);
  for (int x : {
         10, 5, 2000, -10, -2
       }) {
    Textbox txt(c, x, 10);
    EXPECT_EQ(x, txt.getWidth());
  }
  Textbox txt(c, 50, 21);
  EXPECT_EQ(50, txt.getWidth());
}
TEST(TestTextbox, height_test) {
  Coordinate c(2, 1);
  for (int y : {
         10, 5, 2000, -10, -2
       }) {
    Textbox txt(c, 10, y);
    EXPECT_EQ(y, txt.getHeight());
  }
  Textbox txt(c, 50, 21);
  EXPECT_EQ(21, txt.getHeight());
}
TEST(TestTextbox, coord_test) {
  Coordinate c(2, 1);
  for (int x : {
         10, 5, 2000, -10, -2
       }) {
    for (int y : {
           10, 5, 2000, -10, -2
         }) {
      Textbox txt(c, x, y);
      EXPECT_EQ(c, txt.getLocation());
    }
  }
}
TEST(TestTextbox, errorVar_test) {
  Coordinate c(0, 0);
  EXPECT_ANY_THROW({Textbox txt(c, 5, 0);});
  EXPECT_ANY_THROW({Textbox txt(c, 0, 5);});
  EXPECT_ANY_THROW({Textbox txt(c, 0, 0);});
}
TEST(TestTextbox, getAt_test) {
  Coordinate c(5,  1);
  Textbox txt(c,  10,  10);
  txt.setText("SeeThisTestSeeThisTest");
  EXPECT_EQ('h', txt.getAt(c));
}
TEST(TestTextbox, outOfBounds_test) {
  Coordinate c(10, 10);
  Textbox txt(c, 2, 3);
  EXPECT_THROW(txt.setText("SeeThisTestSeeThisTest"), widget_error);
}
TEST(TestTextbox, bool_test) {
  Coordinate a(10, 10);
  Coordinate b(30, 20);
  Textbox txt(a, 8, 2);
  EXPECT_TRUE(txt.locatedAt(a));
  EXPECT_EQ(true, txt.locatedAt(a));
  EXPECT_FALSE(txt.locatedAt(b));
  EXPECT_EQ(false, txt.locatedAt(b));
}
TEST(TestTextbox, setText_test) {
  Coordinate c(1,  1);
  Textbox txt(c,  2,  2);
  EXPECT_NO_THROW(txt.setText("Trap"));
}
