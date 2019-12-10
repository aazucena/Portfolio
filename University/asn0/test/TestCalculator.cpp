/**
* Project Name : Calculator - Assignment 0
* Made By Aldrin Azucena
* Made on 09-19-2019
*/

#include "Calculator.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestCalculator, addTest) {
  Calculator c;
  EXPECT_NE(2.5, c.add(2, 0.5));
  EXPECT_EQ(3, c.add(1, 2));
  EXPECT_EQ(-1, c.add(1, -2));
  EXPECT_EQ(-3, c.add(-1, -2));
}

TEST(TestCalculator, subTest) {
  Calculator c;
  EXPECT_NE(-1.5, c.sub(0.5, 1));
  EXPECT_EQ(-1, c.sub(1, 2));
  EXPECT_EQ(1, c.sub(-1, -2));
  EXPECT_EQ(10, c.sub(6, -4));
}

TEST(TestCalculator, multTest) {
  Calculator c;
  EXPECT_EQ(2, c.mult(1, 2));
  EXPECT_NE(5, c.mult(2, 1.5));
  EXPECT_NE(5.5, c.mult(3, 0.5));
  EXPECT_EQ(-6, c.mult(6, -1));
  EXPECT_EQ(4, c.mult(-4, -1));
}

TEST(TestCalculator, divTest) {
  Calculator c;
  EXPECT_NE(0.5, c.div(1, 2));
  EXPECT_EQ(3, c.div(6, 2));
  EXPECT_EQ(-2, c.div(-12, 6));
  EXPECT_EQ(15, c.div(-45, -3));
  EXPECT_EQ(0, c.div(0, 1));
  EXPECT_THROW(c.div(1, 0), div_by_zero_error);
}


