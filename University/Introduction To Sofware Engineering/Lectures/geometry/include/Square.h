#ifndef INCLUDE_SQUARE_H_
#define INCLUDE_SQUARE_H_

#include <Shape2D.h>

/**
* Represents a regular square.<br>
* See https://en.wikipedia.org/wiki/Octagon
*/
class Square : public Shape2D {
 public:
    /**
    * @param s the length of one side.
    * @throws invalid_parameter_error if size is <= 0
    */
    explicit Square(double s);
    virtual ~Square() {}
    double area() const;
    double perimeter() const;

    /**
    * @return side of the Square
    */
    double getSide() const;

 private:
    double side;
};

#endif  // INCLUDE_SQUARE_H_
