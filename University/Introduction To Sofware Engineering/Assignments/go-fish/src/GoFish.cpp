#include "GoFish.h"
#include <map>
#include <string>
#include <vector>
#include <ctime>
#include <random>

void GoFish::play(std::vector<GoFishUI*> views) {
  int i = 0;
  while (true) {
    std::cout << "Total Cards in Deck: "
    << doc.deckOfCards().size() << std::endl;
    setUI(views[i]);
    deal(i);
    if (i == 0) showHand(i);
    tally(i);
    std::cout << std::endl;
    pressCont();
    doc.shuffle();
    i = (i + 1) % views.size();
    if (players[i]->playerHand().empty()
    && doc.deckOfCards().empty()) break;
  }
}
void GoFish::setUI(GoFishUI* interface) { ui = interface; }
void GoFish::setDeck(Deck d) { doc = d; }
void GoFish::setPlayerData(int i) {
  std::vector<Card*> d = doc.deckOfCards();
  players[i]->grabCards(d);
  d.erase(d.begin(), d.begin() + 7);
  doc.deckState(d);
  players[i]->changeName(ui->getPlayerData(i));
}
void GoFish::addPlayers(Player* p) { players.push_back(p); }
void GoFish::showHand(int i) { ui->printDeck(players[i]); }
void GoFish::display(int i) {
  ui->printPlayers(players[i]);
  ui->printDeckSize(players[i]);
}
void GoFish::deal(int i) {
  int psize = (i + 1) % players.size();
  if (!ui->dealingCards(players[i], players[psize])
  && !doc.deckOfCards().empty()) {
    std::vector<Card*> d = doc.deckOfCards();
    players[i]->addCard(d[0]);
    d.erase(d.begin(), d.begin() + 1);
    doc.deckState(d);
  }
}
void GoFish::tally(int i) {
  std::map<std::string, int> dp;
  for (Card* c : players[i]->playerHand()) ++dp[c->getRank()];
  for (auto d : dp) {
    if (d.second == 4) {
      players[i]->addScore(1);
      players[i]->bookCard(d.first);
    }
  }
}
void GoFish::checkScore() {
  std::vector<Player*> tmp = players;
  tmp.erase(std::unique(tmp.begin(), tmp.end(), [](Player* lhs, Player* rhs) {
    return lhs->getScore() == rhs->getScore();
  }), tmp.end());
  if (tmp.size() == 1) {
    std::cout << "It's a draw!!!" << std::endl;
  } else {
    Player* winner = *max_element(players.begin(), players.end(),
    [](Player* lhs, Player* rhs) {
      return lhs->getScore() < rhs->getScore();
    });
    std::cout << "The winner is: " << winner->getName()
    << "!!! Congrats!!" << std::endl;
  }
}

void GoFish::pressCont() {
    std::cout << "Press any key to continue...";
    std::cin.ignore();
    std::cin.get();
    std::cout << std::endl;
}
