#include "Item.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <iostream>
#include <string>
#include <vector>

Item::Item(double value, std::string it, int qt, bool owned) {
  setItemValue(value);
  setItemName(it);
  setItemQuantity(qt);
  setOwner(owned);
}

double Item::getItemValue() {
  return itemValue;
}

int Item::getItemQuantity() {
  return itemQuantity;
}

std::string Item::getItemName() {
  return itemName;
}

std::string Item::getOwnership() {
  if (isOwned() == true) {
    return "Owned";
  } else {
    return "Not Owned";
  }
}

void Item::setItemName(std::string it) {
  itemName = it;
}

void Item::setItemValue(double cost) {
  itemValue = cost;
}

void Item::setItemQuantity(int cap) {
  itemQuantity = cap;
}

void Item::setOwner(bool own) {
  bought = own;
}
void Item::addQuantity() {
  std::string dontCareInput;
  if (Item::getItemQuantity() > Item::MAX_QUANTITY) {
    std::cout << "{Can't hold more than 30 of them!!}\n";
    usleep(800000);
    std::cout << "Press [Enter] to continue\n";
    getline(std::cin, dontCareInput);
  } else {
    std::cout << "{+1 "
         << Item::getItemName()
         << "}\n";
    usleep(800000);
    std::cout << "Press [Enter] to continue\n";
    getline(std::cin, dontCareInput);
    Item::setItemQuantity(Item::itemQuantity++);
  }
}

bool Item::isOwned() {
  if (bought == true) {
    return true;
  } else {
    return false;
  }
}
