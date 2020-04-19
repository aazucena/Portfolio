/**
* Project Name : Calculator - Assignment 0
* Made By Aldrin Azucena
* Made on 09-19-2019
*/
#include "Exceptions.h"
#include "gtest/gtest.h"
#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED
class Calculator{
 private:
  int x;
  int y;
 public:
  Calculator();
  ~Calculator();
  int add(int x, int y);
  int sub(int x, int y);
  int mult(int x, int y);
  int div(int x, int y);
};


#endif // CALCULATOR_H_INCLUDED
