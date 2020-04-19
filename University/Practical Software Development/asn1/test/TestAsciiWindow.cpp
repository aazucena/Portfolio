/*
* CPSC 2720 Fall 2019
* Aldrin Azucena <a.azucena@uleth.ca>
*/
#include "Image.h"
#include "Textbox.h"
#include "Coordinate.h"
#include "AsciiWindow.h"
#include <string>
#include <fstream>
#include <vector>
#include "gtest/gtest.h"
TEST(TestAsciiWindow, constructor_test) {
  for (int x : {
         10, 10, 200, 15, 2, 10, 10, 5
       }) {
    for (int y : {
           5, 9, 20, 102, 25, 11, 10, 5
         }) {
      EXPECT_NO_THROW({AsciiWindow aw(x, y);});
    }
  }
  for (int x : {
         -10, 0, 1025
       }) {
    for (int y : {
           -10, 0, 1025
         }) {
      EXPECT_ANY_THROW({AsciiWindow aw(x, y);});
    }
  }
}
TEST(TestAsciiWindow, width_test) {
  for (int w : {
         10, 2, 25, 1024
       }) {
    AsciiWindow aw(w, 10);
    EXPECT_EQ(w, aw.getWidth());
  }
  for (int w : {
         15, 3, 5, 1004
       }) {
    AsciiWindow aw(10, 10);
    aw.resize(w, 2);
    EXPECT_EQ(w, aw.getWidth());
  }
}
TEST(TestAsciiWindow, height_test) {
  for (int h : {
         10, 2, 25, 1024
       }) {
    AsciiWindow aw(10, h);
    EXPECT_EQ(h, aw.getHeight());
  }
  for (int h : {
         100, 12, 215, 124
       }) {
    AsciiWindow aw(10, 10);
    aw.resize(2, h);
    EXPECT_EQ(h, aw.getHeight());
  }
}
TEST(TestAsciiWindow, error_test) {
  for (int w : {
         -10, 0, 1025
       }) {
    for (int h : {
           -10, 0, 1025
         }) {
      EXPECT_THROW({AsciiWindow aw(w, h);}, illegal_size_error);
    }
  }
  AsciiWindow aw(10, 10);
  EXPECT_ANY_THROW({AsciiWindow aw(0, 5);});
  EXPECT_ANY_THROW({AsciiWindow aw(5, 0);});
  EXPECT_ANY_THROW({AsciiWindow aw(1025, 5);});
  EXPECT_ANY_THROW({AsciiWindow aw(5, 1025);});
  EXPECT_THROW(aw.resize(2000, 2000), illegal_size_error);
  EXPECT_THROW(aw.resize(0, 0), illegal_size_error);
  EXPECT_THROW(aw.resize(0, 5), illegal_size_error);
  EXPECT_THROW(aw.resize(5, 0), illegal_size_error);
  EXPECT_THROW(aw.resize(1025, 0), illegal_size_error);
  EXPECT_THROW(aw.resize(0, 1025), illegal_size_error);
}
TEST(TestWindow, widget_test) {
  AsciiWindow aw(100, 100);
  Coordinate c(10, 10);
  Coordinate d(60, 30);
  Coordinate e(50, 51);
  Coordinate f(10, 45);
  Coordinate er(20, 200);
  Image img(c, 10, 10);
  Textbox txt(d, 10, 10);
  Image pic(e, 10, 10);
  Textbox box(f, 10, 10);
  Textbox err(er, 180, 310);
  EXPECT_EQ(100, aw.getWidth());
  EXPECT_EQ(100, aw.getHeight());
  EXPECT_NO_THROW({aw.addWidget(&img);});
  EXPECT_NO_THROW({aw.addWidget(&txt);});
  EXPECT_NO_THROW({aw.addWidget(&pic);});
  EXPECT_NO_THROW({aw.addWidget(&box);});
  EXPECT_THROW({aw.addWidget(&err);}, widget_operation_failed_error);
  EXPECT_NO_THROW({aw.removeWidget(&img);});
  EXPECT_NO_THROW({aw.removeWidget(&txt);});
  EXPECT_NO_THROW({aw.removeWidget(&pic);});
  EXPECT_NO_THROW({aw.removeWidget(&box);});
  EXPECT_THROW({aw.removeWidget(&err);}, widget_operation_failed_error);
}
TEST(TestAsciiWindow, empty_draw_test) {
  AsciiWindow aw(10, 10);
  std::ofstream refFile;
  aw.draw(std::cout);
  refFile.open("asciiWindow_empty.txt", std::ofstream::out);
  aw.draw(refFile);
  refFile.close();
}

TEST(TestAsciiWindow, widget_vector_test) {
  AsciiWindow aw(20, 20);
  std::vector<Widget*> wids;
  Coordinate c(5, 5);
  Coordinate d(1, 1);
  Coordinate e(4, 2);
  Image img(c, 4, 4);
  Textbox txt(d, 1, 8);
  txt.setText("Textbox");
  txt.setText("Boxtext");
  aw.addWidget(&img);
  aw.addWidget(&txt);
  for (auto v : aw.getWidgets()) {
    wids.push_back(v);
  }
  EXPECT_EQ(2, wids.size());
  for (auto v : wids) {
    std::cout << v << std::endl;
  }
}
TEST(TestAsciiWindow, widget_draw_test) {
  AsciiWindow aw(10, 10);
  Coordinate c(5, 5);
  Coordinate d(1, 1);
  Image img(c, 4, 4);
  //Textbox txt(d, 8, 1); - outputs TTTTTT in test-bug
  Textbox txt(d, 1, 8);
  txt.setText("Textbox");
  aw.addWidget(&img);
  aw.addWidget(&txt);
  std::ofstream refFile;
  refFile.open("asciiWindow_widgets.txt", std::ofstream::out);
  aw.draw(std::cout);
  aw.draw(refFile);
  refFile.close();
}
TEST(TestAsciiWindow, error_draw_test) {
  AsciiWindow aw(10, 10);
  Coordinate c(9, 8);
  Image img(c, 2, 1);
  EXPECT_THROW({aw.addWidget(&img);}, widget_operation_failed_error);
}
