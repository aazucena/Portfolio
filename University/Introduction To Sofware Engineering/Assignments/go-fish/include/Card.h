#ifndef INCLUDE_CARD_H_
#define INCLUDE_CARD_H_
#include <string>

class Card {
 public:
    Card(std::string r, std::string s) : rank(r), suit(s) {}
    virtual ~Card() {}

    std::string getRank() { return rank; }
    std::string getSuit() { return suit; }

 private:
    std::string rank, suit;
};

#endif // INCLUDE_CARD_H_
