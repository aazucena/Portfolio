#include <vector>
#include <string>
#include "Character.h"
#include "Exceptions.h"
#include "CharacterManager.h"
#include "gtest/gtest.h"

TEST(TestCharacterManager, characterManagerListTest) {
  CharacterManager* cm = CharacterManager::getInstance();

  Character* c = new Character("Billy", "Hughson", 'm');
  Character* c1 = new Character("Briana", "Cruz", 'f');
  Character* c2 = new Character("Aldrin", "Azucena", 'm');

  cm->addCharacter(c);
  cm->addCharacter(c1);
  cm->addCharacter(c2);

  std::vector<Character*> chars = cm->getList();

  EXPECT_EQ(3, chars.size());
}
