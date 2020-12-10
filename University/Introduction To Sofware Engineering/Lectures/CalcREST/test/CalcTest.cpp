#include "Calculator.h"
#include "gtest/gtest.h"


TEST(TestCalculator, add) {
    Calculator c;
    EXPECT_EQ(2, c.add(1, 1));
    EXPECT_EQ(200, c.add(100, 100));
}

TEST(TestCalculator, subtract) {
    Calculator c;
    EXPECT_EQ(1, c.subtract(2, 1));
    EXPECT_EQ(-1, c.subtract(0, 1));
}

TEST(TestCalculator, multiply) {
    Calculator c;
    EXPECT_EQ(2, c.multiply(2, 1));
    EXPECT_EQ(-1, c.multiply(-1, 1));
}

TEST(TestCalculator, divide) {
    Calculator c;
    EXPECT_EQ(2, c.divide(2, 1));
    EXPECT_EQ(-1, c.divide(1, -1));
}

TEST(TestCalculator, divideByZero) {
    Calculator c;
    EXPECT_THROW(c.divide(2, 0), div_by_zero_error);
}
