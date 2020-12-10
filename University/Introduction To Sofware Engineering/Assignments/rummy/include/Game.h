#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include "Card.h"
#include "Deck.h"
#include "GameUI.h"
#include "Player.h"

class Game {
 public:
    Game(GameUI* interface, Deck* d) : deck(d), ui(interface) {}
    virtual ~Game() {}
    virtual void dealCards(std::vector<Player*> p) = 0;
    virtual void beforeCardPlayed(unsigned int playerNum,
                                  unsigned int numPlayers) = 0;
    virtual void afterCardPlayed(Player* currentPlayer,
                                 std::vector<Player*> players,
                                 Card* played) = 0;
    virtual bool turnOver() = 0;
    virtual void start() = 0;

    bool isOver() const;

    void addPlayer(Player* p);
    std::vector<Player*> getPlayers();

 protected:
    std::vector<Player*> players;
    Deck* deck;
    GameUI* ui;
};

#endif // GAME_H_INCLUDED
