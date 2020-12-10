#include "Square.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestSquare, illegal) {
  EXPECT_THROW(new Square(0), invalid_parameter_error);
  EXPECT_THROW(new Square(-2), invalid_parameter_error);
  EXPECT_THROW(new Square(-150), invalid_parameter_error);
}

TEST(TestSquare, area) {
  GeometricShape* shape = new Square(2);
  EXPECT_NEAR(4, shape->area(), 0.0001);
  delete shape;

  shape = new Square(10);
  EXPECT_NEAR(100, shape->area(), 0.0001);
  delete shape;
}

TEST(TestSquare, perimeter) {
  Shape2D* shape = new Square(2);
  EXPECT_DOUBLE_EQ(8, shape->perimeter());
  shape = new Square(10);
  EXPECT_DOUBLE_EQ(40, shape->perimeter());
}
