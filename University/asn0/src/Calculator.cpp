/**
* Project Name : Calculator - Assignment 0
* Made By Aldrin Azucena
* Made on 09-19-2019
*/
#include "Calculator.h"
#include "Exceptions.h"
#include "gtest/gtest.h"
  Calculator::Calculator(){};
  Calculator::~Calculator(){};
  int Calculator::add (int x, int y){return x+y;};
  int Calculator::sub (int x, int y){return x-y;};
  int Calculator::mult (int x, int y){return x*y;};
  int Calculator::div (int x, int y)
  {
    if (y == 0){throw div_by_zero_error("No. You can't divide by 0. Error...");}
    else{return static_cast<double>(x)/y;}
  };
