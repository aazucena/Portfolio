/*
* CPSC 2720 Spring 2019
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*/
#ifndef INCLUDE_GEOMETRICSHAPE_H_
#define INCLUDE_GEOMETRICSHAPE_H_

/**
    Interface for a generic geometric shape.
*/

class GeometricShape {
 public:
    /**
     *  @return The area of the shape.
     *  @throws calculation_error if the area cannot be correctly calculated.
     */
    virtual double area() const = 0;
};
#endif  // INCLUDE_GEOMETRICSHAPE_H_
