#include "Square.h"
#include "Exceptions.h"
#include <cmath>

Square::Square(double s) {
  if (s <= 0)
    throw invalid_parameter_error("Side must be a positive number.");
  side = s;
}

double Square::area() const {
  return pow(side, 2);
}

double Square::perimeter() const {
  return side * 4;
}
