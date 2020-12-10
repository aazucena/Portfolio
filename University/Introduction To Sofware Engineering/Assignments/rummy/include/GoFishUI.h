#ifndef GOFISHUI_H
#define GOFISHUI_H

#include "GameUI.h"
#include "Card.h"
#include <list>
#include <stack>
#include <vector>

class GoFishUI : public GameUI {
 public:
    GoFishUI() {}
    ~GoFishUI() {}

    unsigned int requestCard(std::list<Card*>* hand);
    void playFailed();
    void playSucceeded();
    void drawCardFrom(const std::stack<Card*>& pile,
    Deck* d, std::list<Card*>* hand) {}
    void listPatterns(const std::vector<std::list<Card*>*>& patterns) {}
};

#endif // GOFISHUI_H
