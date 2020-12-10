#ifndef INCLUDE_OCTAGON_H_
#define INCLUDE_OCTAGON_H_

#include <Shape2D.h>

/**
* Represents a regular octagon.<br>
* See https://en.wikipedia.org/wiki/Octagon
*/
class Octagon : public Shape2D {
 public:
    /**
    * @param s the length of one side.
    * @throws invalid_parameter_error if size is <= 0
    */
    explicit Octagon(double s);
    virtual ~Octagon() {}
    double area() const;
    double perimeter() const;

    /**
    * @return side of the Octagon
    */
    double getSide() const;

 private:
    double side;
};

#endif  // INCLUDE_OCTAGON_H_
