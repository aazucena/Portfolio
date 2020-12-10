#include <cstdlib>
#include <ctime>

/*
* A number generator
*/
class NumberGenerator {
public:
  /**
  * Generate a number in the range [0, max]
  * @param max The maximum value of the range.
  */
  virtual unsigned int getNum(unsigned int max) = 0;
};

/*
* A number generator that produces the series [0, max)
*/
class Sequential : public NumberGenerator {
public:
  Sequential() : count(0) { }
  unsigned int getNum(unsigned int max) {
    if(count == max)
      count = 0;
    return count++;
  }

private:
  unsigned int count;
};


/*
* A number generator that produces a random sequence of numbers.
*/
class Random : public NumberGenerator {
public:
  Random() {
    std::srand(std::time(nullptr));
  }
  unsigned int getNum(unsigned int max) {
    return std::rand() % max;
  }
};
