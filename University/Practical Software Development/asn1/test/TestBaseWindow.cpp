/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "BaseWindow.h"
#include <string>
#include "gtest/gtest.h"
TEST(TestBaseWindow, constructor_test) {
  for (int x : {
         10, 10, 200, 15, 2, 10, 10, 5
       }) {
    for (int y : {
           5, 9, 20, 102, 25, 11, 10, 5
         }) {
      EXPECT_NO_THROW({BaseWindow bw(x, y);});
    }
  }
  for (int x : {
         -10, 0, 1025
       }) {
    for (int y : {
           -10, 0, 1025
         }) {
      EXPECT_ANY_THROW({BaseWindow bw(x, y);});
    }
  }
}
TEST(TestBaseWindow, width_test) {
  BaseWindow df;
  EXPECT_EQ(10, df.getWidth());
  for (int w : {
         10, 2, 25, 1024
       }) {
    BaseWindow bw(w, 10);
    EXPECT_EQ(w, bw.getWidth());
  }
  for (int w : {
         120, 21, 5, 104
       }) {
    BaseWindow bw(10, 10);
    bw.resize(w, 2);
    EXPECT_EQ(w, bw.getWidth());
  }
}
TEST(TestBaseWindow, height_test) {
  BaseWindow df;
  EXPECT_EQ(10, df.getHeight());
  for (int h : {
         10, 2, 25, 1024
       }) {
    BaseWindow bw(10, h);
    EXPECT_EQ(h, bw.getHeight());
  }
  for (int h : {
         10, 2, 25, 1024
       }) {
    BaseWindow bw(10, 10);
    bw.resize(2, h);
    EXPECT_EQ(h, bw.getHeight());
  }
}
TEST(TestBaseWindow, error_test) {
  for (int w : {
         -10, 0, 1025
       }) {
    for (int h : {
           -10, 0, 1025
         }) {
      EXPECT_ANY_THROW({BaseWindow bw(w, h);});
    }
  }
  BaseWindow bw(10, 10);
  EXPECT_ANY_THROW({BaseWindow bw(0, 5);});
  EXPECT_ANY_THROW({BaseWindow bw(5, 0);});
  EXPECT_ANY_THROW({BaseWindow bw(1025, 5);});
  EXPECT_ANY_THROW({BaseWindow bw(5, 1025);});
  EXPECT_ANY_THROW({bw.resize(0, 0);});
  EXPECT_ANY_THROW({bw.resize(2000, 2000);});
  EXPECT_ANY_THROW({bw.resize(0, 5);});
  EXPECT_ANY_THROW({bw.resize(5, 0);});
  EXPECT_ANY_THROW({bw.resize(5, 1025);});
  EXPECT_ANY_THROW({bw.resize(1025, 5);});
}
TEST(TestBaseWindow, draw_test) {
  BaseWindow bw(10, 10);
  std::cout << "This is the base window" << std::endl;
  EXPECT_NO_THROW({bw.draw(std::cout);});
}

