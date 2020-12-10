#include "Rummy.h"
#include "Exceptions.h"
#include <list>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

void Rummy::dealCards(std::vector<Player*> players) {
    unsigned int numCards;
    if (players.size() <= 2)
        numCards = 10;
    else if (players.size() > 2
        && players.size() <= 4)
        numCards = 7;
    else
        numCards = 6;

    unsigned int deckSize = deck->size();
    unsigned int neededCards = players.size() * numCards;

    if (deckSize >= neededCards) {
        unsigned int playerNum = 0;
        for (unsigned int i = 0; i < neededCards; i++) {
            Player* p = players.at(playerNum);
            p->addCard(deck->getCard());
            playerNum = (++playerNum) % players.size();
        }
    }
}

void Rummy::beforeCardPlayed(unsigned int playerNum,
                              unsigned int numPlayers) {
    // get the card from top of the deck, and place it on the discard pile
    discardPile.push(deck->getCard());
    if (deck->size() <= 0) {
      while (!discardPile.empty()) {
        deck->addCard(discardPile.top());
        discardPile.pop();
      }
      discardPile.push(deck->getCard());
    }
}

void Rummy::afterCardPlayed(Player* currentPlayer,
                             std::vector<Player*> players,
                             Card* played) {
    std::list<Card*>* hand = currentPlayer->getHand();
    std::list<Card*>::iterator card;
    // sort player's hand by suit with rank in ordere
    // ex: C1 C2 C3 S3 S5 S10 SJ D3 H3 H4 H5 HQ HK...
    hand->sort([] (const Card* lh, const Card* rh) {
      return std::make_pair(lh->suit, lh->rank)
      < std::make_pair(rh->suit, rh->rank);
    });

    // check if card can be layed off
    if (isLayoff(played)) {
      for (card = hand->begin(); card != hand->end(); ++card) {
        if ((*card)->rank == played->rank) {
            hand->erase(card);
            return;
        }
      }
    }
    // melding
    std::list<Card*> toRemove1, toRemove2;
    for (card = hand->begin(); card != hand->end(); ++card) {
        if ((*card)->rank == played->rank) {
            toRemove1.push_back(*card);
        }
    }

    for (card = hand->begin(); card != hand->end(); ++card) {
        // if current card isn't the selected card,
        // move to the next card from selection
        if (played->suit != (*card)->suit)
            continue;

        std::list<Card*>::iterator pv = card;

        // check the previous cards
        int index = 0;
        while ((*pv) != NULL) {
          //left card
          Card::Rank rPrev = played->prevRank(played->rank, index);

          if (std::make_pair(played->suit, rPrev)
          == std::make_pair((*pv)->suit, (*pv)->rank)) {
            toRemove2.push_back((*pv));
          }
          index++;
          std::advance(pv, -1);
        }
    }

    for (card = hand->begin(); card != hand->end(); ++card) {
        // if current card isn't the selected card,
        // move to the next card from selection
        if (played->suit != (*card)->suit)
            continue;

        std::list<Card*>::iterator nx = card;

        // check the next cards
        int index = 0;
        while ((*nx) != NULL) {
          //right card

          Card::Rank rNext = played->nextRank(played->rank, index);

          if (std::make_pair(played->suit, rNext)
          == std::make_pair((*nx)->suit, (*nx)->rank)) {
            toRemove2.push_back((*nx));
          }
          index++;
          std::advance(nx, 1);
        }
    }

    toRemove2.sort([] (const Card* lh, const Card* rh) {
      return std::make_pair(lh->suit, lh->rank)
      < std::make_pair(rh->suit, rh->rank);
    });

    toRemove2.unique();

    // Check if have a set of cards or a sequence of cards
    if (toRemove1.size()>= 3 && toRemove1.size() < 5) {
      ui->playSucceeded();
      set.push_back(&toRemove1);
    } else if (toRemove2.size() >= 3) {
      ui->playSucceeded();
      seq.push_back(&toRemove2);
    } else {
      ui->playFailed();
    }

    Card* topPile = discardPile.top();
    auto cCard = hand->begin();
    //choose a card to discard
    do {
      int index = ui->requestCard(hand);
      std::advance(cCard, index);
      index = 0;
    } while (topPile == (*cCard));
    discardPile.pop();
    discardPile.push(*cCard);
    hand->remove(*cCard);

    if (isOver()) {
      for (Player* losers : players) {
        if (losers->name == currentPlayer->name)
            continue;
        std::list<Card*>* tmp = losers->getHand();
        for (std::list<Card*>::iterator c = tmp->begin(); c != tmp->end(); ++c)
            currentPlayer->addPoints(getPoints(*c));
      }
    }
}

bool Rummy::isLayoff(Card* c) {
  if (set.empty() || seq.empty())
    return false;

  //layoff for set
  for (std::list<Card*>* st : set) {
    Card* tmp = st->front();
    if (tmp->rank == c->rank) {
      st->push_back(c);
      st->sort([] (const Card* lh, const Card* rh) {
        return std::make_pair(lh->suit, lh->rank)
        < std::make_pair(rh->suit, rh->rank);
      });
      return true;
    }
  }

  //layoff for seq
  for (std::list<Card*>* sq : seq) {
    Card* fr = sq->front();
    Card* bk = sq->back();
    Card::Rank rPrev = fr->prevRank(fr ->rank, 1);
    Card::Rank rNext = bk->prevRank(bk->rank, 1);
    if (std::make_pair(c->suit, c->rank)
      == std::make_pair(fr->suit, rPrev)) {
      sq->push_back(c);
      sq->sort([] (const Card* lh, const Card* rh) {
        return std::make_pair(lh->suit, lh->rank)
          < std::make_pair(rh->suit, rh->rank);
      });
      return true;
    } else if (std::make_pair(c->suit, c->rank)
      == std::make_pair(bk->suit, rNext)) {
      sq->push_back(c);
      sq->sort([] (const Card* lh, const Card* rh) {
        return std::make_pair(lh->suit, lh->rank)
          < std::make_pair(rh->suit, rh->rank);
      });
      return true;
    }
  }
  return false;
}

int Rummy::getPoints(Card* c) {
  switch (c->rank) {
    case Card::Rank::JACK:
    case Card::Rank::QUEEN:
    case Card::Rank::KING:
      return 10;
      break;
    default:
      return c->rank + 1;
  }
}

bool Rummy::turnOver() {
    return true;
}

void Rummy::start() {
    if (players.empty())
        throw game_init_error("No players for game");

    // Deal cards
    deck->shuffle();
    dealCards(players);

    unsigned int turn = 0;
    Card* c;
    Player* p = players.front();
    while (!isOver()) {
        p = players.at(turn);
        do {
            beforeCardPlayed(turn, players.size());
            // ask the player if they want to draw from the deck or the pile?
            ui->drawCardFrom(discardPile, deck, p->getHand());
            int index = ui->requestCard(p->getHand());
            c = p->getCard(index);
            afterCardPlayed(p, players, c);
            ui->listPatterns(set);
            ui->listPatterns(seq);
        } while (!turnOver());

        turn = ++turn % players.size();
    }
    ui->showScores(players);
}

std::ostream& operator<<(std::ostream& os, const Card* c) {
    os << c->getRank(c->rank) << ":" << c->getSuit(c->suit);
    return os;
}
