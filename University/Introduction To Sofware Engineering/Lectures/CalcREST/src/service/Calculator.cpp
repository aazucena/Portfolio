#include "Calculator.h"

double Calculator::add(double x, double y) {
    return x + y;
}

double Calculator::subtract(double x, double y) {
    return x - y;
}

double Calculator::multiply(double x, double y) {
    return x * y;
}

double Calculator::divide(double x, double y) {
    if (y == 0)
        throw div_by_zero_error("Can't divide by zero!");

    return x/y;
}
