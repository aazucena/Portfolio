#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "./exceptions.h"

/**
* Provides simple arithmetic functions.
*/

class Calculator {
 public:
    /**
    * Find the sum of two numbers
    * @param a First number.
    * @param b Second number.
    * @return Sum of a and b
    */
    double add(double a, double b);

    /**
     * Find the difference between two numbers
     * @param a First number.
     * @param b Second number.
     * @return Sum of a and b
     */
    double subtract(double a, double b);

    /**
     * Find the product of two numbers
     * @param a First number.
     * @param b Second number.
     * @return Sum of a and b
     */
    double multiply(double a, double b);

    /**
     * Find the dividend of two numbers
     * @param a First number.
     * @param b Second number.
     * @return Sum of a and b
     * @throw div_by_zero_error If b == 0
     */
    double divide(double a, double b);
};

#endif // CALCULATOR_H
