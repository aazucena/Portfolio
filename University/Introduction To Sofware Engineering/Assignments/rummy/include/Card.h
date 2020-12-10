#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
#include <string>

class Card {
 public:
    enum Suit {CLUB, DIAMOND, SPADE, HEART};
    enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX,
      SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

    Card(Suit s, Rank r):suit(s), rank(r) {}
    static std::string getRank(Card::Rank r);
    static std::string getSuit(Card::Suit s);
    static Rank nextRank(Rank r, int pos);
    static Rank prevRank(Rank r, int pos);

    const Suit suit;
    const Rank rank;

    friend std::ostream& operator<<(std::ostream& os, const Card& c);
};

#endif // CARD_H_INCLUDED
