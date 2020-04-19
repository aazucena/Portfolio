#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "Person.h"
#include "Character.h"

TEST(TestPerson, constructorCharacterTest) {
  std::string fn = "Billy";
  std::string ln = "Hughson";
  char g = 'm';

  Character c(fn, ln, g);

  EXPECT_EQ("Billy", c.getFirstName());
  EXPECT_EQ("Hughson", c.getLastName());
  EXPECT_EQ('m', c.getGender());
}

TEST(TestCharacter, affectionUpTest) {
  Character c("Brian", "Cruz", 'm');

  unsigned int affection = c.getAffection();

  EXPECT_EQ(0, affection);

  c.affectionUp();

  affection = c.getAffection();

  EXPECT_EQ(1, affection);

  c.affectionUp();

  affection = c.getAffection();

  EXPECT_EQ(2, affection);
}
