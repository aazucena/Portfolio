#include "Person.h"
#include "Player.h"
#include "Character.h"
#include "HelperPerson.h"
#include "CharacterManager.h"
#include "StringMagician.h"
#include <unistd.h> // for cout delays {usleep(milliseconds);}
#include <string>
#include <iostream>
#include <vector>

void HelperPerson::printHelp() {
  std::string dontCareInput;
  Player* p = Player::getInstance();
  Stat* kno = p->getStat("knowledge");
  Stat* gut = p->getStat("guts");
  Stat* und = p->getStat("understanding");
  Stat* chr = p->getStat("charisma");
  Stat* ath = p->getStat("athleticism");
  Stat* pro = p->getStat("proficiency");

  std::cout << p->getFirstName() << ": \n";
  std::cout << "I think Alex knows about this. "
       << "I should call him. So I picked up my phone, "
       << "trying to call him, and he instantly answers.\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << firstName << ": \n";
  std::cout << "'Hey "
       << p->getFirstName()
       << "! I am guessing you want some advice,"
       << " well here are couple of them I can give.'\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << StringMagician::bold("'You currently have") << " "
       << StringMagician::bold(p->getStatLevelName(ath)) << " "
       << StringMagician::bold("Athleticism\n");
  std::cout << StringMagician::bold("'Try to work on your Athleticism")
       << StringMagician::bold(" as there are 6 levels of it.");
  std::cout << StringMagician::bold("Working on it will make you stronger ")
       << StringMagician::bold("and maximize your stamina.");
  std::cout << StringMagician::bold("You can either buy protein food, ")
       << StringMagician::bold("go to workout, ")
       << StringMagician::bold("or do anything related to Athleticism.'\n");
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << StringMagician::bold("'You currently have")
       << StringMagician::bold(p->getStatLevelName(kno))
       << StringMagician::bold(" Knowledge\n");
  std::cout << StringMagician::bold("'Try to work on your Knowledge ")
       << StringMagician::bold("as there are 6 levels of it.");
  std::cout << StringMagician::bold("Working on it will make you smarter, ")
       << StringMagician::bold("able to think under pressure, ")
       << StringMagician::bold("and answer questions in a whim.");
  std::cout << StringMagician::bold("You can either get A+ in tests, ")
       << StringMagician::bold("read books, ")
       << StringMagician::bold("or do anything related to Knowledge.'\n");
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << StringMagician::bold("'You currently have")
       << StringMagician::bold(p->getStatLevelName(pro))
       << StringMagician::bold(" Proficiency\n");
  std::cout << StringMagician::bold("'Try to work on your Proficiency ")
       << StringMagician::bold("as there are 6 levels of it.");
  std::cout << StringMagician::bold("Working on it will make you skillful, ")
       << StringMagician::bold("more reactive & flexible, ")
       << StringMagician::bold("and maximize your precision in any skill.");
  std::cout << StringMagician::bold("You can either play video games, ")
       << StringMagician::bold("specialize on something, ")
       << StringMagician::bold("or do anything related to Proficiency.'\n");
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << StringMagician::bold("'You currently have")
       << StringMagician::bold(p->getStatLevelName(und))
       << StringMagician::bold(" Understanding\n");
  std::cout << StringMagician::bold("'Try to work on your Understanding ")
       << StringMagician::bold("as there are 6 levels of it.");
  std::cout << StringMagician::bold("Working on it will make you kinder, ")
       << StringMagician::bold("able to read between the lines, ")
       << StringMagician::bold("and maximize your diligence.'");
  std::cout << StringMagician::bold("You can either talk to friends, ")
       << StringMagician::bold("watch romantic movies, ")
       << StringMagician::bold("and do anything related to Understanding.'\n");
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << StringMagician::bold("'You currently have")
       << StringMagician::bold(p->getStatLevelName(chr))
       << StringMagician::bold(" Charisma\n");
  std::cout << StringMagician::bold("'Try to work on your Charisma ")
       << StringMagician::bold("'as there are 6 levels of it.");
  std::cout << StringMagician::bold("Working on it will make you articulate, ")
       << StringMagician::bold("gain ability to act, ")
       << StringMagician::bold("maximize your communication skills.");
  std::cout << StringMagician::bold("You can either impress people, ")
       << StringMagician::bold("work in call center, ")
       << StringMagician::bold("or do anything related to Charisma.'\n");
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << StringMagician::bold("'You currently have")
       << StringMagician::bold(p->getStatLevelName(gut))
       << StringMagician::bold(" Guts\n");
  std::cout << StringMagician::bold("'Try to work on your Guts ")
       << StringMagician::bold("as there are 6 levels of it.");
  std::cout << StringMagician::bold("Working on it will make you brave, ")
       << StringMagician::bold("able to express your opinions freely, ")
       << StringMagician::bold("and maximize your confidence.");
  std::cout << StringMagician::bold("You can either do daring things, ")
       << StringMagician::bold("watch scary movies, ")
       << StringMagician::bold("or do anything related to Guts.'\n");
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << "'Anything else?'\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << p->getFirstName() << ": \n";
  std::cout << "'Nope that's it. Thanks Alex!'\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << firstName <<": \n";
  std::cout << "'Happy to help "
       << p->getFirstName()
       << "! Just call me anytime,"
       << " and let me know if you need any advice.'\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << "~Call Ended~\n";
}

void HelperPerson::printAffectionStatus(CharacterManager* characterManager) {
  std::string dontCareInput;
  Player* p = Player::getInstance();

  std::cout << p->getFirstName() << ": \n";
  std::cout << "I think Alex could tell me about the people I know."
       <<" I should call him. So I picked up my phone, "
       << "trying to call him, and he instantly answers.\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << firstName <<": \n";
  std::cout << "'Hey "
       << p->getFirstName()
       << "! I am guessing you want know what your friends think about you."
       << " Well here are couple of them I can provide.'\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  CharacterManager* cm = CharacterManager::getInstance();
  std::vector<Character*> chars = cm->getList();

  for (size_t i = 0; i < chars.size(); i++) {
    Character* c = chars.at(i);
    std::cout <<"---------------------------------------------------------\n";
    std::cout <<" First Name: "<< c->getFirstName() << "\n";
    std::cout <<" Last Name: "<< c->getLastName() << "\n";
    std::cout <<" Gender: "<< c->getGenderString() << "\n";
    std::cout <<" Relationship Status: "<< c->affectionLevelName() << "\n";
  }
  std::cout <<"---------------------------------------------------------\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << "'Anything else?'\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << p->getFirstName() << ": \n";
  std::cout << "'Nope that's it. Thanks Alex!'\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << firstName <<": \n";
  std::cout << "'Happy to help "
       << p->getFirstName()
       << "! Just call me anytime,"
       << " and let me know if you need anything.'\n";
  usleep(800000);
  std::cout << "Press [Enter] to continue\n";
  getline(std::cin, dontCareInput);

  std::cout << "~Call Ended~\n";
}
