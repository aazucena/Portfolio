#include "Octagon.h"
#include "Exceptions.h"
#include <cmath>

Octagon::Octagon(double s) {
  if (s <= 0)
    throw invalid_parameter_error("Side must be a positive number.");
  side = s;
}

double Octagon::area() const {
  return 2 * (1 + sqrt(2)) * pow(side, 2);
}

double Octagon::perimeter() const {
  return side * 8;
}
