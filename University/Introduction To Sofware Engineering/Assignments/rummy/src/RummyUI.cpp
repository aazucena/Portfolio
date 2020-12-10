#include "RummyUI.h"
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <string>
#include <utility>

unsigned int RummyUI::requestCard(std::list<Card*>* hand) {
    hand->sort([] (const Card* lh, const Card* rh) {
      return std::make_pair(lh->suit, lh->rank)
      < std::make_pair(rh->suit, rh->rank);
    });
    std::cout << "Your hand:" << std::endl;
    unsigned int index = 0;
    for (std::list<Card*>::iterator i = hand->begin(); i != hand->end(); ++i) {
        std::cout << "\tChoice " << (++index) << ": "
          << (*i)->getRank((*i)->rank) + ":" + (*i)->getSuit((*i)->suit)
          << std::endl;
    }

    unsigned int selection;
    std::cout << "You Choosed: ";

    std::cin >> selection;
    std::cin.ignore();
    return selection-1;
}

void RummyUI::drawCardFrom(const std::stack<Card*>& pile,
Deck* d, std::list<Card*>* hand) {
  char choice;
  bool chosen = false;
  std::string pileStatus = "";
  do {
    if (pile.empty()) {
      pileStatus = "N/A";
    } else {
      Card* tmp = pile.top();
      pileStatus = tmp->getRank(tmp->rank) + ":" + tmp->getSuit(tmp->suit);
    }

    //show the discard Pile
    std::cout << "Currently on the Discard Pile: " << pileStatus << std::endl;

    // ask if the player wants to draw from deck or discard pile
    std::cout << "Do you want to draw the card from: \n"
              << "1. Deck \n"
              << "2. Discard Pile \n";

    std::cout << "Select a choice: ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
      case '1':
        std::cout << "You have drawn the card from the deck!"
        << std::endl;
        hand->push_back(d->getCard());
        chosen = true;
        break;
      case '2':
        std::cout << "You have drawn the card from the Discard Pile!"
        << std::endl;
        hand->push_back(pile.top());
        chosen = true;
        break;
      default:
        std::cout << "Wrong INPUT!!!! TRY AGAIN!!!" << std::endl;
    }
  } while (chosen != true);
}

void RummyUI::playFailed() {
  std::cout << "Choose a card to discard: " << std::endl;
}

void RummyUI::playSucceeded() {
  std::cout << "Successfully Meld/Layoff to a Sequence/Set Pattern"
  << std::endl;
}

void RummyUI::listPatterns(const std::vector<std::list<Card*>*>& patterns) {
  if (patterns.empty()) {
    std::cout << "No Patterns currently..." << std::endl;
    return;
  }
  std::list<Card*>* pattern;
  std::vector<std::list<Card*>*>::const_iterator tmp = patterns.begin();

  if (isSet(*tmp))
    std::cout << "_Current Set Pattern_" << std::endl;
  else
    std::cout << "_Current Sequence Pattern_" << std::endl;

  unsigned int index = 0;
  for (std::vector<std::list<Card*>*>::const_iterator i = patterns.begin();
    i != patterns.end(); ++i) {
    pattern = *i;
    std::cout << "Pattern #" << (++index) << ": ";
    for (std::list<Card*>::iterator card = pattern->begin();
    card != pattern->end(); ++card) {
      Card::Rank r = (*card)->rank;
      Card::Suit s = (*card)->suit;
      std::cout << Card::getSuit(s) << " - " << Card::getRank(r) << " ";
    }
    std::cout << std::endl;
  }
}

bool RummyUI::isSet(std::list<Card*>* pattern) {
  std::list<Card*>::iterator card = pattern->begin(), next = pattern->begin();
  std::advance(next, 1);
  if ((*card)->rank == (*next)->rank)
    return true;
  return false;
}
