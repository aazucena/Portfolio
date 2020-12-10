#ifndef RUMMYUI_H
#define RUMMYUI_H

#include "GameUI.h"
#include "Card.h"
#include "Deck.h"
#include <list>
#include <stack>
#include <vector>

class RummyUI : public GameUI {
 public:
    RummyUI() {}
    ~RummyUI() {}

    unsigned int requestCard(std::list<Card*>* hand);
    void playFailed();
    void playSucceeded();
    void drawCardFrom(const std::stack<Card*>& pile,
    Deck* d, std::list<Card*>* hand);
    void listPatterns(const std::vector<std::list<Card*>*>& patterns);
    bool isSet(std::list<Card*>* pattern);
};


#endif // RUMMYUI_H
