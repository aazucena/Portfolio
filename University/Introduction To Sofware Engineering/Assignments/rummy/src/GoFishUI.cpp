#include "GoFishUI.h"
#include <iostream>
#include <list>
#include <stack>
#include <vector>

unsigned int GoFishUI::requestCard(std::list<Card*>* hand) {
    std::cout << "Your hand:" << std::endl;
    unsigned int index = 0;
    for (std::list<Card*>::iterator i = hand->begin(); i != hand->end(); ++i) {
        Card::Rank r = (*i)->rank;
        std::cout << "\tChoice " << (++index) << ": "
          << Card::getRank(r) << std::endl;
    }

    unsigned int selection;
    do {
      std::cout << "Select a choice: ";

      std::cin >> selection;
      std::cin.ignore();
    } while ((selection - 1) <= hand->size());
    return selection-1;
}

void GoFishUI::playFailed() {
    std::cout << "Go Fish!" << std::endl;
}

void GoFishUI::playSucceeded() {
    std::cout << "The player had some of those cards!" << std::endl;
}
