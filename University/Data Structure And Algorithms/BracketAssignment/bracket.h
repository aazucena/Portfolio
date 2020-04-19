/**
* Assignment 2
* Made by Aldrin Azucena
* University Of Lethbridge
* Data Structures and Algorithms - CPSC3620
* SID: 01220471
* Created on February 2nd, 2020
*/
#ifndef BRACKET_H_INCLUDED
#define BRACKET_H_INCLUDED

class Bracket {
 public:

  /**
  * Constructor for Bracket Class
  */
  Bracket(std::string expr){
    express = expr;
  }

  virtual ~Bracket(){}

  /**
  * @returns true if the parenthesis are balanced
  */
  bool isBalanced(std::string ex);

  /**
  * @returns string of an expression
  */
  std::string getString(){
    return express;
  }

  /**
  * @returns true if expression has brackets
  */
  bool hasBrackets(std::string ex);

 private:
  std::string express="";
};

#endif // BRACKET_H_INCLUDED
