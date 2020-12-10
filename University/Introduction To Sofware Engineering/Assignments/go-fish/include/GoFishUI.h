#ifndef INCLUDE_GOFISHUI_H_
#define INCLUDE_GOFISHUI_H_
#include "GoFish.h"
#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <ctime>

class GoFishUI {
 public:
    GoFishUI() {}
    ~GoFishUI() {}

    virtual void printDeck(Player* p) = 0;
    virtual void printPlayers(Player* p) = 0;
    virtual void printDeckSize(Player* p) = 0;
    virtual bool dealingCards(Player* p, Player* opp) = 0;
    virtual std::string getPlayerData(int i) = 0;

 private:
};


class ByUser : public GoFishUI {
 public:
    ByUser() {}
    ~ByUser() {}

    void printDeck(Player* p) {
      for (Card* c : p->playerHand()) {
        std::cout << "[" << c->getRank() << "|"
        << c->getSuit() << "] ";
      }
      std::cout << std::endl;
    }
    void printPlayers(Player* p) {
      std::cout << p->getName() << std::endl;
      std::cout << "Score: " << p->getScore() << std::endl;
    }
    void printDeckSize(Player* p) {
      std::cout << "Deck Size: "
      << p->playerHand().size() << std::endl;
    }
    bool dealingCards(Player* p, Player* opp) {
      std::string input;
      if (!p->hasCards()) return false;
      bool streak = true;
      while (streak) {
        p->dealCard();
        std::cout << p->getName()
        << ", What rank do you want to ask for? ";
        std::cin >> input;
        std::cout << p->getName() << ": Do you have a "
        << input << "? " << std::endl;
        if (p->holds(input)) {
          if (opp->holds(input)) {
            std::cout << opp->getName() << " has a "
            << input << std::endl << std::endl;
            p->addCard(opp->giveCard(input));
          } else {
            std::cout << opp->getName() << ": 'GoFish' "
            << std::endl;
            streak = false;
          }
        } else {
           std::cout << p->getName() << " doesn't have "
           << input << std::endl << std::endl << std::endl;
        }
      }
      return false;
    }
    std::string getPlayerData(int i) {
      std::string n = "";
      std::cout << "Enter your name: ";
      std::cin >> n;
      return n;
    }

 private:
};

class ByNPC : public GoFishUI {
 public:
    ByNPC() {}
    ~ByNPC() {}

    void printDeck(Player* p) {
      for (Card* c : p->playerHand())
        std::cout  << "["<< c->getRank() << "|" << c->getSuit() << "] ";
      std::cout << std::endl;
    }
    void printDeckSize(Player* p) {
      std::cout << "Deck Size: " << p->playerHand().size()
      << std::endl;
    }
    void printPlayers(Player* p) {
      std::cout << p->getName() << std::endl;
      std::cout << "Score: " << p->getScore() << std::endl;
    }
    bool dealingCards(Player* p, Player* opp) {
      std::string input;
      if (!p->hasCards()) return false;
      bool streak = true;
      while (streak) {
        input = returnAIVal(p);
        std::cout << p->getName() << ": Do you have a "
        << input << "? " << std::endl;
        if (p->holds(input)) {
          if (opp->holds(input)) {
            std::cout << opp->getName() << " has a "
            << input << std::endl << std::endl;
            p->addCard(opp->giveCard(input));
          } else {
            std::cout << opp->getName() << ": 'GoFish' "
            << std::endl;
            streak = false;
          }
        } else {
          std::cout << p->getName() << " doesn't have "
          << input << std::endl;
        }
      }
      return false;
    }
    std::string getPlayerData(int i) {
      return "CPU" + std::to_string(i);
    }

 private:
  std::string returnAIVal(Player* p) {
    std::random_device rd;
    std::uniform_int_distribution<int> dis(0, (p->playerHand().size() - 1));
    std::vector<Card*> tmp = p->playerHand();
    return tmp[dis(rd)]->getRank();
  }
};

#endif // GOFISHUI_H_
