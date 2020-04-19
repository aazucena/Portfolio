/**
*@author akalanka, <a.galappaththi@uleth.ca>
*@date 2019-09
*/

#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
* Exception for any errors related to Calculator.
*/
class div_by_zero_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit div_by_zero_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};



#endif // EXCEPTIONS_H_INCLUDED
