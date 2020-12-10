#ifndef INCLUDE_SHAPE2D_H_
#define INCLUDE_SHAPE2D_H_

#include "GeometricShape.h"

/**
    Interface for a two-dimensional shape.
*/
class Shape2D : public GeometricShape {
 public:
    /**
    *  @return The perimeter of the shape.
    *  @throws calculation_error if the perimeter cannot be correctly calculated.
    */
    virtual double perimeter() const = 0;
};
#endif  // INCLUDE_SHAPE2D_H_
