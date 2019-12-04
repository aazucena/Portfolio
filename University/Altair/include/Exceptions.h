#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
* Exception for when operation on an event fails.
*/
class event_operation_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit event_operation_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when event name already exists.
*/
class event_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit event_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when location name already exists.
*/
class location_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit location_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when stat from player doesn't exist.
*/
class stat_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit stat_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when salary is less than 0.
*/
class salary_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit salary_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when the character exists.
*/
class confidante_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit confidante_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

class character_not_found_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit character_not_found_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};
#endif  // EXCEPTIONS_H_INCLUDED
