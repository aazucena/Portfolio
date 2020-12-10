#ifndef INCLUDE_EXCEPTIONS_H_
#define INCLUDE_EXCEPTIONS_H_

#include <stdexcept>

/**
* Exception for an invalid parameter passed to a constructor or method.
*/
class invalid_parameter_error: public std::runtime_error {
 public:
    /**
    * @param errMessage An error message.
    */
    explicit invalid_parameter_error(const char* errMessage) :
        std::runtime_error(errMessage) {
    }
};

/**
* Exception for when a calculation cannot be made or will return an invalid value (e.g. inf, NaN).
*/
class calculation_error: public std::runtime_error {
 public:
    /**
    * @param errMessage An error message.
    */
    explicit calculation_error(const char* errMessage) :
        std::runtime_error(errMessage) {
    }
};

#endif  // INCLUDE_EXCEPTIONS_H_
