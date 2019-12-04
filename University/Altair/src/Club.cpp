#include "Player.h"
#include "Club.h"
#include "StringMagician.h"
#include "Dialogue.h"
#include "Choice.h"
#include "Event.h"
#include "EventManager.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <iostream>
#include <string>

std::string Club::getClubName() {
  return Club::clubName;
}

bool Club::playClub() {
  Player* p = Player::getInstance();
  Dialogue d;
  std::string dontCareInput;

  if (p->getClub() == "Go-Home Club") {
    std::cout << "I don't have a club so I'll just go home."
              << std::endl;
    d.dialogueContinue();
    return true;
  }

  std::cout << "You go to "
            << p->getClub()
            << std::endl;
  d.dialogueContinue();

  std::cout << "I should work on... "
            << std::endl;
  d.dialogueContinue();

  std::cout << "Athleticism\n"
            << "Charisma\n"
            << "Guts\n"
            << "Understanding\n"
            << "Knowledge\n"
            << "Proficiency\n";

  std::string response;
  bool correctInput = false;

  Stat* s;

  std::string statNames[6];
  statNames[0] = "athleticism";
  statNames[1] = "charisma";
  statNames[2] = "guts";
  statNames[3] = "understanding";
  statNames[4] = "knowledge";
  statNames[5] = "proficiency";

  while (!correctInput) {
    getline(std::cin, response);
    std::cin.ignore(1000, '\n');
    response = StringMagician::stringToLower(response);

    for (int i = 0; i < 6; i++) {
      s = p->getStat(statNames[i]);

      if (s->getStatName().find(response) != std::string::npos) {
        std::cout << "At " << p->getClub()
                  << ", I work on my "
                  << s->getStatName() <<"."
                  << std::endl;
        d.dialogueContinue();

        std::cout << "I feel stronger in "
                  << s->getStatName()
                  << "."
                  << std::endl;
        d.dialogueContinue();

        s->levelUp();

        return true;
      }
    }
    std::cout << "I don't know how I can improve that..."
              << std::endl;
  }
  return true;
}
