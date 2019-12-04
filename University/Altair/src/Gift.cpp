#include "Gift.h"
#include "ItemInventory.h"
#include "Item.h"
#include "Player.h"
#include "Event.h"
#include "Character.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <iostream>
#include <string>

Gift::Gift(GiftType type,
            std::string desc,
             int mod,
             double val,
              std::string it,
               int qt,
                bool owned)
: description(desc),
 affectionMod(mod),
  giftType(type),
   Item(val, it, qt, owned) {}

bool Gift::giveToCharacter(Character c) {
    std::string dontCareInput;
    if (Gift::getItemQuantity() <= 0) {
        return false;
    } else {
        if (Gift::getGiftType() == Food) {
            std::cout << c.getFirstName()
                 << ": \n";
            std::cout << "'Thanks, I really love this !'"
                 << "I'll savour "
                 << Gift::getItemName()
                 << " food!\n";
            usleep(800000);
            std::cout << "Press [Enter] to continue\n";
            getline(std::cin, dontCareInput);
            c.setAffection(c.getAffection()*Gift::getGiftAffMod());
            return true;
        } else if (Gift::getGiftType() == Clothes
                && c.getAffection() >= 30) {
            std::cout << c.getFirstName()
                 << ": \n";
            std::cout << "'Thanks, I really love this !'"
                 << "I'll cherish this "
                 << Gift::getItemName()
                 << " clothes brand!\n";
            usleep(800000);
            std::cout << "Press [Enter] to continue\n";
            getline(std::cin, dontCareInput);
            c.setAffection(c.getAffection()*Gift::getGiftAffMod());
            return true;
        } else if (Gift::getGiftType() == Plants
                && c.getAffection() >= 50) {
            std::cout << c.getFirstName()
                 << ": \n";
            std::cout << "'Aww, thanks. I love you!'";
            usleep(800000);
            std::cout << "Press [Enter] to continue\n";
            getline(std::cin, dontCareInput);
            c.setAffection(c.getAffection()*Gift::getGiftAffMod());
            return true;
        } else {
            std::cout << c.getFirstName()
                 << ": \n";
            std::cout << "'Oh. thanks...'";
            usleep(800000);
            std::cout << "Press [Enter] to continue\n";
            return false;
        }
    }
}

std::string Gift::getGiftDescription() {
    return description;
}

int Gift::getGiftAffMod() {
    return affectionMod;
}

void Gift::setGiftAffMod(int mod) {
    affectionMod = mod;
}

Gift::GiftType Gift::getGiftType() {
    return Gift::giftType;
}

void Gift::printItemInfo() {
    std::cout << Gift::getItemName()
    << " - "
    << Gift::getGiftType()
    << " - $"
    << Gift::getItemValue()
    << " - "
    << Gift::getItemQuantity()
    << " - "
    << Gift::getOwnership();
}
