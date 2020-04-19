#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED
#include <string>

class Stat {
 public:
  unsigned int MAX_LEVEL = 60;
  Stat() {}

  Stat(std::string stat);

  virtual ~Stat() {}

  /**
  * level's up stat
  */
  unsigned int levelUp();

  /**
  *sets the level
  *@param level
  *@return new level
  */
  void setLevel(unsigned int lvl);

  /**
  *sets the name of the stat
  *@param stat
  */
  void setStatName(std::string stat);

  /**
  *gets the level of stat
  *@return level
  */
  unsigned int getLevel();

  /**
  *gets the stat name
  *@return stat name
  */
  std::string getStatName();

 private:
  unsigned int level = 1;

  std::string statName;
};

#endif // STAT_H_INCLUDED
