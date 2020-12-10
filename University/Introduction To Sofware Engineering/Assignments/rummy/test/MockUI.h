#ifndef MOCKUI_H_INCLUDED
#define MOCKUI_H_INCLUDED

#include "GameUI.h"
#include <list>
#include <vector>
#include <stack>

class MockUI : public GameUI {
 public:
    MockUI() {}
    virtual ~MockUI() {}

    MOCK_METHOD1(requestCard, unsigned int(std::list<Card*>* hand));
    MOCK_METHOD0(playFailed, void());
    MOCK_METHOD0(playSucceeded, void());
    MOCK_METHOD3(drawCardFrom, void(const std::stack<Card*>&,
    Deck* d, std::list<Card*>* hand));
    MOCK_METHOD1(listPatterns, void(const std::vector<std::list<Card*>*>&));
    MOCK_METHOD2(choosePlayer, unsigned int(unsigned int playerNum,
      unsigned int numPlayers));
    MOCK_METHOD1(showScores, void(std::vector<Player*>));
};


#endif // MOCKUI_H_INCLUDED
