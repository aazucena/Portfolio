#include <string>
#include <iostream>
#include <vector>
#include "ItemShop.h"
#include "Player.h"
#include "Character.h"
#include "CharacterManager.h"
#include "Dialogue.h"
#include "StringMagician.h"

bool ItemShop::displayShop() {
  Player* p = Player::getInstance();
  Dialogue d;
  std::string choice;
  double value;
  char charResponse;
  bool correctInput = false;

  std::cout << "Eager Clerk:" << std::endl
            << "Welcome to MonkeyMart! "
            << "How may we help you today?" << std::endl;
  d.dialogueContinue();

  std::cout << p->getFirstName() << ":" << std::endl
            << "I would like to buy..." << std::endl;

  printChoices();

  // Checks for what item the player wants to buy
  while (!correctInput) {
    std::cin >> charResponse;
    switch (charResponse) {
    case '1':
      choice = "necklace";
      value = 100;
      d.dialogueContinue();
      correctInput = true;
      break;
    case '2':
      choice = "hat";
      value = 15;
      d.dialogueContinue();
      correctInput = true;
      break;
    case '3':
      choice = "bracelet";
      value = 30;
      d.dialogueContinue();
      correctInput = true;
      break;
    case '4':
      choice = "cake";
      value = 10;
      d.dialogueContinue();
      correctInput = true;
      break;
    case '5':
      choice = "bag of brownies";
      value = 8;
      d.dialogueContinue();
      correctInput = true;
      break;
    case '6':
      choice = "bouquet of flowers";
      value = 5;
      d.dialogueContinue();
      correctInput = true;
      break;
    case '7':
      choice = "venus flytrap";
      value = 6;
      d.dialogueContinue();
      correctInput = true;
      break;
    default:
      std::cout
          << "I don't think I can buy that here..."
          << std::endl;
      break;
    }
  }

  // Check if player has enough money
  if (p->getMoney() <= 0 || p->getMoney() < value) {
    std::cout
        << "I don't have enough money..."
        << std::endl;
    d.dialogueContinue();
    return true;
  } else {
    p->spendMoney(value);
    std::cout << "I bought a "
              << choice << std::endl;
    d.dialogueContinue();
  }

  correctInput = false;

  std::cout
      << "With my newly bought item I should..."
      << std::endl;

  std::cout
      << "[1] Keep it for myself" << std::endl
      << "[2] Give it to someone as a gift" << std::endl;

  // Checks for what the player wants to do with newly bought "item"
  while (!correctInput) {
    //
    std::cin >> charResponse;
    switch (charResponse) {
    case '1':
      choice = "keep";
      std::cout
          << "I'm not sure that's possible..."
          << std::endl;
      correctInput = true;
      break;
    case '2':
      choice = "gift";
      correctInput = true;
      break;
    default:
      std::cout
          << "I'm not sure that's possible..."
          << std::endl;
    }
  }

  if (choice == "keep") {
    std::cout
        << "Alright I will keep it."
        << std::endl;
    d.dialogueContinue();
    return true;
  }

  std::cout
      << "I should give it to..."
      << std::endl;

  // If player wants to gift
  Character* c = ItemShop::printCharacters();

  std::cout << "I give my purchase to "
            << c->getFirstName() << " "
            << c->getLastName() << std::endl;

  std::cout << "I feel our bond has increased" << std::endl;

  unsigned int addedAff = c->getAffection() + value;
  c->setAffection(addedAff);

  return true;
}

void ItemShop::printChoices() {
  //
  std::cout
      << "[1] Necklace $100" << std::endl
      << "[2] Funky Hat $15" << std::endl
      << "[3] Bracelet $30" << std::endl
      << "[4] Cake $10" << std::endl
      << "[5] Bag of Brownies $8" << std::endl
      << "[6] Bouquet of Flowers $5" << std::endl
      << "[7] Venus Flytrap $6" << std::endl;
}

// Prints characters and gets result
Character* ItemShop::printCharacters() {
  CharacterManager* cm = CharacterManager::getInstance();
  Character* c;
  bool correctInput = false;
  std::string response;
  std::vector<Character*> charList = cm->getList();

  for (size_t i = 0; i < charList.size(); i++) {
    c = charList.at(i);
    std::cout << c->getFirstName()
              << " " << c->getLastName()
              << std::endl;
  }

  while (!correctInput) {
    getline(std::cin, response);
    std::cin.ignore();
    response = StringMagician::stringToLower(response);
    for (size_t i = 0; i < charList.size(); i++) {
      c = charList.at(i);
      std::string cName = c->getFirstName()+" "+c->getLastName();
      cName = StringMagician::stringToLower(cName);

      if (cName.find(response) != std::string::npos) {
        correctInput = true;
        return c;
      }
    }

    std::cout << "I don't know who that is...";
  }
}
