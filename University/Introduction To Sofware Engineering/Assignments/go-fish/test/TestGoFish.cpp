#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GoFish.h"

using ::testing::Return;
using ::testing::_;

class ByStub : public GoFishUI {
 public:
    ByStub() {}
    ~ByStub() {}

    void printDeck(Player* p) {
        for (Card* c : p->playerHand())
            std::cout  << "["<< c->getRank() << "|" << c->getSuit() << "] ";
        std::cout << std::endl;
    }
    void printDeckSize(Player* p) {
        std::cout << "StubDeck Size: " << p->playerHand().size()
                  << std::endl;
    }
    void printPlayers(Player* p) {
        std::cout << p->getName() << std::endl;
        std::cout << "StubScore: " << p->getScore() << std::endl;
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
                          << input << std::endl;
            }
        }
        return false;
    }
    std::string getPlayerData(int i) {
        return "Stub#" + std::to_string(i);
    }

 private:
};

class MockGoFishUI : public GoFishUI {
 public:
    explicit MockGoFishUI() {}
    virtual ~MockGoFishUI() {}

    MOCK_METHOD1(printDeck, void(Player*));
    MOCK_METHOD1(printDeckSize, void(Player*));
    MOCK_METHOD1(printPlayers, void(Player*));
    MOCK_METHOD2(dealingCards, bool(Player*, Player*));
    MOCK_METHOD1(getPlayerData, std::string(int));

 private:
};

TEST(GoFishMockTest, stubTest) {
    GoFish game;
    Deck d;
    d.buildDeck();
    game.setDeck(d);

    std::vector<GoFishUI*> views;
    views.push_back(new ByStub());

    Player* p = new Player();
    game.addPlayers(p);

    for (int i = 0; i < views.size(); i++) {
      game.setUI(views[i]);
      game.setPlayerData(i);
      game.display(i);
      game.showHand(i);
    }
}

TEST(GoFishMockTest, mockTest) {
    MockGoFishUI nv;

    EXPECT_CALL(nv, getPlayerData(::testing::_))
      .Times(1)
      .WillRepeatedly(Return(""));

    GoFish game;
    Deck d;
    d.buildDeck();
    game.setDeck(d);
    std::vector<GoFishUI*> views;
    views.push_back(&nv);

    Player* p = new Player();
    game.addPlayers(p);

    EXPECT_CALL(nv, printDeck(_));
    EXPECT_CALL(nv, printDeckSize(_));
    EXPECT_CALL(nv, printPlayers(_));

    for (int i = 0; i < views.size(); i++) {
      game.setUI(views[i]);
      game.setPlayerData(i);
      game.display(i);
      game.showHand(i);
    }
}
