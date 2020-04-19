#include "Character.h"
#include "CharacterManager.h"
#include "Player.h"
#include "Dialogue.h"
#include "Hangout.h"
#include "StringMagician.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <iostream>
#include <string>
#include <vector>

bool Hangout::playHangout() {
    Dialogue d;

    std::cout << "I picked up my phone, and looked into my phone contacts. "
    << "I should hang out with...\n";
    d.dialogueContinue();

    CharacterManager* cm = CharacterManager::getInstance();
    std::vector<Character*> chars = cm->getList();

    for (size_t i = 0; i < chars.size(); i++) {
        Character* c = chars.at(i);

        std::cout << c->getFirstName()
        << " "
        << c->getLastName() << ".\n";
    }

    std::string response;
    bool correctInput = false;
    Player* p = Player::getInstance();

    while (!correctInput) {
        getline(std::cin, response);
        std::cin.ignore();
        response = StringMagician::stringToLower(response);
        for (size_t i = 0; i < chars.size(); i++) {
            Character* c = chars.at(i);
            std::string cName = c->getFirstName()+" "+c->getLastName();
            cName = StringMagician::stringToLower(cName);

            if (cName.find(response) != std::string::npos) {
                std::cout << "I hangout with "
                << c->getFirstName() << ".\n";
                d.dialogueContinue();

                std::cout << "We had a fun time.";
                d.dialogueContinue();

                std::cout << "I spent $5 during my time with "
                << c->getFirstName() << ".\n";
                d.dialogueContinue();

                p->spendMoney(5.00);
                std::cout << "{Currently have $"
                << p->getMoney()
                << "}\n";
                d.dialogueContinue();

                c->affectionUp();

                std::cout << "{I feel my bond with "
                << c->getFirstName()
                << " has increased}\n";
                d.dialogueContinue();

                correctInput = true;
            }
        }
    }

    return true;
}
