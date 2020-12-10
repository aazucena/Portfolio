#include "Player.h"
#include <utility>
#include <string>
#include <vector>

void Player::addScore(int s) {
  if (s < 0) return;
  score += s;
}
void Player::addCard(Card* c) {
  hand.push_back(c);
  sortHand();
}
void Player::grabCards(std::vector<Card*> d) {
    std::move(d.begin(), d.begin() + 7, std::back_inserter(hand));
    sortHand();
}
bool Player::hasCards() {
  if (hand.size() <= 0) return false;
  return true;
}
bool Player::holds(std::string cRank) {
  for (Card* cd : hand)
    if (cd->getRank() == cRank)
      return true;
  return false;
}
Card* Player::giveCard(std::string card) {
  for (Card* cd : hand) {
    if (cd->getRank() == card) {
      hand.erase(std::remove(hand.begin(),
      hand.end(), cd), hand.end());
      return cd;
    }
  }
}
void Player::dealCard() {
  sortHand();
  std::vector<Card*> tmp = hand;
  tmp.erase(std::unique(tmp.begin(), tmp.end(), [](Card* lhs, Card* rhs) {
    return lhs->getRank() == rhs->getRank();
  }), tmp.end());
  for (Card* c : tmp)
    std::cout << "["<< c->getRank() << "] ";
  std::cout << std::endl;
}
void Player::bookCard(std::string card) {
  hand.erase(std::remove_if(hand.begin(), hand.end(),
  [card](Card* lhs) {
    return lhs->getRank() == card;
  }), hand.end());
  std::cout << getName() << " has a book of "
  << card << " cards!!" << std::endl;
}
std::vector<Card*>& Player::playerHand() {
  sortHand();
  return hand;
}
