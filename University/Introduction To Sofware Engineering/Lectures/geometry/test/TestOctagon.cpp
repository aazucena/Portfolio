#include "Octagon.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

TEST(TestOctagon, illegal) {
  EXPECT_THROW(new Octagon(0), invalid_parameter_error);
  EXPECT_THROW(new Octagon(-1), invalid_parameter_error);
  EXPECT_THROW(new Octagon(-127), invalid_parameter_error);
}

TEST(TestOctagon, area) {
  GeometricShape* shape = new Octagon(2);
  EXPECT_NEAR(19.3137, shape->area(), 0.0001);
  delete shape;

  shape = new Octagon(10);
  EXPECT_NEAR(482.8427, shape->area(), 0.0001);
  delete shape;
}

TEST(TestOctagon, perimeter) {
  Shape2D* shape = new Octagon(2);
  EXPECT_DOUBLE_EQ(16, shape->perimeter());
  shape = new Octagon(10);
  EXPECT_DOUBLE_EQ(80, shape->perimeter());
}
