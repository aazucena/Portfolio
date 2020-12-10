#include "gtest/gtest.h"

#include "MockDeck.h"
#include "MockUI.h"

#include "Card.h"
#include "Game.h"
#include "Rummy.h"

using ::testing::Return;
using ::testing::_;
using ::testing::Expectation;

class RummyTest : public ::testing::Test {
 protected:
  virtual ~RummyTest() {
    delete aceClub;
    delete aceDia;
    delete aceHeart;
    delete aceSpade;

    delete kingClub;
    delete kingDia;
    delete kingHeart;
    delete kingSpade;

    delete twoClub;
    delete twoDia;
    delete twoHeart;
    delete twoSpade;

    delete queenClub;
    delete queenDia;
    delete queenHeart;
    delete queenSpade;

    delete threeClub;
    delete threeDia;
    delete threeHeart;
    delete threeSpade;

    delete fourClub;
    delete fourDia;
    delete fourHeart;
    delete fourSpade;

    delete jackClub;
    delete jackHeart;
    delete jackSpade;
  }

  Card* aceClub = new Card(Card::CLUB, Card::ACE);
  Card* aceSpade = new Card(Card::SPADE, Card::ACE);
  Card* aceDia = new Card(Card::DIAMOND, Card::ACE);
  Card* aceHeart = new Card(Card::HEART, Card::ACE);

  Card* kingClub = new Card(Card::CLUB, Card::KING);
  Card* kingSpade = new Card(Card::SPADE, Card::KING);
  Card* kingDia = new Card(Card::DIAMOND, Card::KING);
  Card* kingHeart = new Card(Card::HEART, Card::KING);

  Card* twoClub = new Card(Card::CLUB, Card::TWO);
  Card* twoSpade = new Card(Card::SPADE, Card::TWO);
  Card* twoDia = new Card(Card::DIAMOND, Card::TWO);
  Card* twoHeart = new Card(Card::HEART, Card::TWO);

  Card* queenClub = new Card(Card::CLUB, Card::QUEEN);
  Card* queenSpade = new Card(Card::SPADE, Card::QUEEN);
  Card* queenDia = new Card(Card::DIAMOND, Card::QUEEN);
  Card* queenHeart = new Card(Card::CLUB, Card::QUEEN);

  Card* threeClub = new Card(Card::CLUB, Card::THREE);
  Card* threeSpade = new Card(Card::SPADE, Card::THREE);
  Card* threeDia = new Card(Card::DIAMOND, Card::THREE);
  Card* threeHeart = new Card(Card::HEART, Card::THREE);

  Card* fourClub = new Card(Card::CLUB, Card::FOUR);
  Card* fourSpade = new Card(Card::SPADE, Card::FOUR);
  Card* fourDia = new Card(Card::DIAMOND, Card::FOUR);
  Card* fourHeart = new Card(Card::HEART, Card::FOUR);

  Card* jackClub = new Card(Card::CLUB, Card::JACK);
  Card* jackSpade = new Card(Card::SPADE, Card::JACK);
  Card* jackHeart = new Card(Card::HEART, Card::JACK);
};

TEST_F(RummyTest, CardDealSmall) {
    MockDeck d;

    EXPECT_CALL(d, getCard())
    .Times(20)
    .WillRepeatedly(Return(aceClub));

    EXPECT_CALL(d, size())
    .Times(1)
    .WillOnce(Return(20));

    MockUI ui;

    Game* game = new Rummy(&ui, &d);

    Player* player1 = new Player("John");
    Player* player2 = new Player("Danielle");
    game->addPlayer(player1);
    game->addPlayer(player2);

    game->dealCards(game->getPlayers());

    for (Player* p : game->getPlayers())
        EXPECT_EQ(10, p->getHand()->size());

    delete game;
    delete player1;
    delete player2;
}

TEST_F(RummyTest, CardDealMedium) {
    MockDeck d;
    EXPECT_CALL(d, getCard())
    .Times(28)
    .WillRepeatedly(Return(aceHeart));

    EXPECT_CALL(d, size())
    .Times(1)
    .WillOnce(Return(28));

    MockUI ui;

    Game* game = new Rummy(&ui, &d);

    Player* player1 = new Player("John");
    Player* player2 = new Player("Danielle");
    Player* player3 = new Player("Tara");
    Player* player4 = new Player("Erik");
    game->addPlayer(player1);
    game->addPlayer(player2);
    game->addPlayer(player3);
    game->addPlayer(player4);

    game->dealCards(game->getPlayers());

    for (Player* p : game->getPlayers())
        EXPECT_EQ(7, p->getHand()->size());

    delete game;
    delete player1;
    delete player2;
    delete player3;
    delete player4;
}

TEST_F(RummyTest, CardDealLarge) {
    MockDeck d;
    EXPECT_CALL(d, getCard())
    .Times(36)
    .WillRepeatedly(Return(aceSpade));

    EXPECT_CALL(d, size())
    .Times(1)
    .WillOnce(Return(36));

    MockUI ui;

    Game* game = new Rummy(&ui, &d);

    Player* player1 = new Player("John");
    Player* player2 = new Player("Danielle");
    Player* player3 = new Player("Tara");
    Player* player4 = new Player("Erik");
    Player* player5 = new Player("Bobby");
    Player* player6 = new Player("Jane");
    game->addPlayer(player1);
    game->addPlayer(player2);
    game->addPlayer(player3);
    game->addPlayer(player4);
    game->addPlayer(player5);
    game->addPlayer(player6);

    game->dealCards(game->getPlayers());

    for (Player* p : game->getPlayers())
        EXPECT_EQ(6, p->getHand()->size());

    delete game;
    delete player1;
    delete player2;
    delete player3;
    delete player4;
    delete player5;
    delete player6;
}

TEST_F(RummyTest, DrawSet) {
    MockDeck d;

    EXPECT_CALL(d, getCard())
    .Times(0)
    .After(EXPECT_CALL(d, shuffle()));
    /*
    // Hands
    .WillOnce(Return(aceClub))
    .WillOnce(Return(kingClub))
    .WillOnce(Return(aceSpade))
    .WillOnce(Return(kingSpade))
    .WillOnce(Return(aceDia))
    .WillOnce(Return(kingDia))

    .WillOnce(Return(twoClub))
    .WillOnce(Return(queenClub))
    .WillOnce(Return(twoSpade))
    .WillOnce(Return(queenSpade))
    .WillOnce(Return(twoDia))
    .WillOnce(Return(queenDia))

    .WillOnce(Return(threeClub))
    .WillOnce(Return(jackClub))

    // Deck
    .WillOnce(Return(aceHeart))
    .WillOnce(Return(kingHeart))
    .WillOnce(Return(twoHeart))
    .WillOnce(Return(queenHeart))
    .WillOnce(Return(threeHeart))
    .WillOnce(Return(jackHeart))
    .WillOnce(Return(fourHeart))
    .WillOnce(Return(threeDia))
    .WillOnce(Return(jackSpade))
    .WillOnce(Return(threeSpade))
    */

    EXPECT_CALL(d, size())
    .Times(1)
    .WillOnce(Return(10));

    MockUI ui;

    EXPECT_CALL(ui, requestCard(_))
    .Times(0);

    EXPECT_CALL(ui, drawCardFrom(_, _, _))
    .Times(0);

    EXPECT_CALL(ui, showScores(_))
    .Times(1);

    EXPECT_CALL(ui, playFailed())
    .Times(0);

    Game* game = new Rummy(&ui, &d);

    Player* player1 = new Player("John");
    Player* player2 = new Player("Kira");

    game->addPlayer(player1);
    game->addPlayer(player2);
    game->start();

    EXPECT_EQ(0, player1->getScore());

    delete game;
    delete player1;
    delete player2;
}

TEST_F(RummyTest, AfterCardPlayedSet) {
    MockDeck d;

    EXPECT_CALL(d, getCard())
    .Times(0)
    .After(EXPECT_CALL(d, shuffle()));
    /*
    // Hands
    .WillOnce(Return(aceClub))
    .WillOnce(Return(kingClub))
    .WillOnce(Return(aceDia))
    .WillOnce(Return(kingDia))
    .WillOnce(Return(aceHeart))
    .WillOnce(Return(kingHeart))

    .WillOnce(Return(twoClub))
    .WillOnce(Return(queenClub))
    .WillOnce(Return(twoHeart))
    .WillOnce(Return(queenHeart))
    .WillOnce(Return(twoSpade))
    .WillOnce(Return(queenSpade))

    .WillOnce(Return(kingSpade))
    .WillOnce(Return(aceSpade))

    // Deck
    .WillOnce(Return(twoDia));*/

    EXPECT_CALL(d, size())
    .Times(1)
    .WillOnce(Return(15));

    MockUI ui;

    EXPECT_CALL(ui, playFailed())
    .Times(0);

    EXPECT_CALL(ui, playSucceeded())
    .Times(0);

    EXPECT_CALL(ui, drawCardFrom(_, _, _))
    .Times(0);

    EXPECT_CALL(ui, requestCard(_))
    .Times(0);

    EXPECT_CALL(ui, showScores(_))
    .Times(1);


    Game* game = new Rummy(&ui, &d);

    Player* player1 = new Player("John");
    Player* player2 = new Player("Kira");

    game->addPlayer(player1);
    game->addPlayer(player2);
    game->start();

    EXPECT_EQ(0, player1->getScore());

    delete game;
    delete player1;
    delete player2;
}
