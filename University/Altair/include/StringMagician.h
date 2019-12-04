#ifndef STRINGMAGICIAN_H_INCLUDED
#define STRINGMAGICIAN_H_INCLUDED

#include <string>
#include <locale>

/**
* Manipulates strings
*/
class StringMagician {
 public:
  static std::string stringToLower(std::string s) {
    std::locale loc;
    std::string lowerString = "";

    for (int i = 0; i < s.size(); i++) {
      lowerString += tolower(s[i], loc);
    }

    return lowerString;
  }

  static std::string bold(std::string s) {
    s = "\e[1m" + s + "\e[0m";
    return s;
  }
};

#endif // STRINGMAGICIAN_H_INCLUDED
