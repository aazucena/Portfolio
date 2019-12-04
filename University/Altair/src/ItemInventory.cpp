#include "ItemInventory.h"
#include "Player.h"
#include "Event.h"
#include "Character.h"
#include "Date.h"
#include "Item.h"
#include "KeyLines.h"
#include "Gift.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

ItemInventory* ItemInventory::instance;

std::vector<Item*> ItemInventory::getItems() {
  return items;
}

void ItemInventory::addItem(Item* it) {
  if (std::find(getItems().begin(), getItems().end(), it) != getItems().end()) {
    std::sort(items.begin(), items.end());
    items.erase(unique(items.begin(), items.end()), items.end());
    items.push_back(it);
  } else {
    items.push_back(it);
  }
}

void ItemInventory::buyItem(double money, Item *it) {
  Player *p = Player::getInstance();
  std::string dontCareInput;
  if (money >= it->getItemValue()) {
    std::cout << p->getFirstName()
         << ": \n";
    std::cout << "I'll buy the"
         << it->getItemName()
         << ".\n";
    usleep(800000);
    std::cout << "Press [Enter] to continue\n";
    p->spendMoney(it->getItemValue()); // buys the item
    it->setOwner(true); // owns the item
    it->addQuantity(); // adding to inventory
    ItemInventory::addItem(it);
  } else {
    std::cout << "I don't have enough money to buy that.\n";
    usleep(800000);
    std::cout << "Press [Enter] to continue\n";
    getline(std::cin, dontCareInput);
  }
} // no selling

void ItemInventory::useItem(Item* it) { //also
  for (int i = 0; i < items.size(); i++) {
    if (std::find(getItems().begin(), getItems().end(), it)
        != getItems().end()) {
      items.erase(items.begin()+i);
      break;
    }
  }
}

