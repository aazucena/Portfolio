#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>
#include <vector>
#include "Person.h"
#include "Stat.h"
#include "Club.h"

class Player : public Person {
 public:
  virtual ~Player() {}

  /**
  *set the money they have
  *@param money
  */
  void setMoney(double money);

  /**
  *gets the amount of money
  *@return money
  */
  double getMoney();

  /**
  * Takes in the cost of something and calculates it with the player's money.
  * Aftwerward updates player's money by subtracting the cost.
  * @param cost double value of something
  * @return double determining the remainder of player's money
  */
  double spendMoney(double cost);

  /**
  * Returns a Player Stat specified by it's string name
  * @param stat String name of a stat
  * @return desired stat
  */
  Stat* getStat(std::string stat);

  /**
  * Sets a stat for the Player
  * @param s The stat to set on existing stats
  */
  void setStat(Stat* s);

  /**
  * Gets the string name of a stat
  * @param s Stat to extract the name from
  */
  std::string getStatLevelName(Stat* s);

  /**
  * Sets the name of the club the Player is in
  * @param cn string of a club name
  */
  void setClub(std::string cn);

  /**
  * Returns the club name that the Player is a part of
  * @return The club name
  */
  std::string getClub();

  /**
  * Sets the job of the Player
  * @param jn string of the job name
  */
  void setJob(std::string jn);

  /**
  * Gets the job name the player is in
  * @return string of the job
  */
  std::string getJob();

  /**
  * Gets the instance of the Player
  * @return The Player instance
  */
  static Player* getInstance() {
    if (instance == nullptr) {
      instance = new Player();
    }

    return instance;
  }

 private:
  std::vector<Stat*> stats;

  double money = 0;

  std::string cn = "Go-Home Club";

  std::string jn = "Home";

  Player(): Person{"Avery", "Doe", 'm'} {
    initializeStats();
  }

  Player(std::string fn, std::string ln, char g): Person{fn, ln, g} {
    initializeStats();
  }

  void initializeStats();

  static Player* instance;
  std::string statLevels[6][6] = {
    //1 - Athleticism
    {
      "Soft", "Average", "Well-Defined",
      "Strong", "Robustic", "Rock-Solid"
    },
    //2 - Charisma
    {
      "Awkward", "Eloquent", "Persuasive",
      "Touching", "Alluring", "Debonair"
    },
    //3 - Guts
    {
      "Milquetoast", "Reserved", "Bold",
      "Staunched", "Dauntless", "Lionhearted"
    },
    //4 - Understanding
    {
      "Inoffensive", "Considerate", "Empathetic",
      "Selfless", "Altruistic", "Saintly"
    },
    //5 - Knowledge
    {
      "Oblivious", "Learned", "Scholarly",
      "Encyclopedic", "Erudite", "Einstein"
    },
    //6 - Proficiency
    {
      "Inept", "Bumbling", "Decent",
      "Skilled", "Masterful", "Transcendent"
    }
  };
};

#endif // PLAYER_H_INCLUDED
