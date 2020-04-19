#include "RoutineDialogueManager.h"
#include "Player.h"
#include "Choice.h"
#include "KeyLines.h"
#include "Dialogue.h"
#include "DialogueManager.h"
#include "Character.h"
#include "CharacterManager.h"
#include "StringMagician.h"
#include <unistd.h> // for std::cout delays {usleep(milliseconds);}
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//getting stats from player
Player *p = Player::getInstance();
Stat* kno = p->getStat("knowledge");
Stat* gut = p->getStat("guts");
Stat* und = p->getStat("understanding");
Stat* chr = p->getStat("charisma");
Stat* ath = p->getStat("athleticism");
Stat* pro = p->getStat("proficiency");
StringMagician text;
DialogueManager dm;
Dialogue d;
KeyLines *kl;
Person fr("Alex", "Caruso", 'm');
char choices;
bool correct = false;// for minor choices

bool RoutineDialogueManager::printStartOfDay(int day) {
  std::string fn = p->getFirstName();
  std::string ln = p->getLastName();
  std::string stLevelName;
  std::string flName;
  std::cout << text.bold("MORNING\n") << std::endl;
  std::cout << "*Day "<< day << "*\n";
  std::stringstream buffer;
  switch (day) {
  case 1:
    std::cout << "|------------Beginning--------------|\n\n";
    usleep(800000);

    std::cout << "Ma: \n";
    std::cout << "'" << fn << "! " << fn
              << "!! Wake up, or else you will be"
              << " late for your first day of Orientation.'\n";
    d.dialogueContinue();
    do {
      std::cout << fn << ": \n";
      std::cout << "What should I do...\n\n";
      std::cout << "[1] Wake up\n";
      std::cout << "[2] Tell Ma to go away "
                << text.bold("(Requires Dauntless Guts)\n");
      std::cout << "[3] Sleep in\n";
      if (std::cin >> choices) {
        switch (choices) {
        case '1':
          std::cout << "'Oh crap! I am late!"
                    << " I need to prepare everything!'\n";
          correct = true;
          d.dialogueContinue();
          break;
        case '2':
          stLevelName = p->getStatLevelName(gut);
          if (gut->getLevel() >= 50) {
            std::cout << "'Go away Ma! I don’t care about school, and-'\n";
            d.dialogueContinue();
            std::cout << "Ma: \n";
            std::cout << "'Just wake up, "
                      << "or else I will cancel your phone plan..'\n";
            d.dialogueContinue();
            std::cout << fn << ": \n";
            std::cout << "Then I wake up instantly.\n";
            correct = true;
            d.dialogueContinue();
          } else {
            std::cout << "'I am really scared to talk back to Ma, "
                      << "because I have " <<
                      text.bold(stLevelName) << " Guts...'\n\n";
          }
          break;
        case '3':
          std::cout << "Nah I can go for another 10 minutes and - \n";
          d.dialogueContinue();
          std::cout << "Ma: \n";
          std::cout << "Just wake up, "
                    << "or else I will cancel your phone plan..\n";
          d.dialogueContinue();
          std::cout << fn << ": \n";
          std::cout << "Then I wake up instantly.\n";
          correct = true;
          d.dialogueContinue();
          break;
        default:
          std::cout << "Wrong Value, Try Again..\n";
          d.dialogueContinue();
          correct = false;
          break;
        }
      }
    } while (!correct);

    flName = d.printFromFile("day1/morn/start1.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start2.txt");
    d.printDialogue(flName);
    d.dialogueContinue();

    std::cout << "Driving on the way to my new school,"
              << " all of a sudden I realized that"
              << " I had forgotten to bring my wallet if I have "
              << text.bold("Decent Proficiency,")
              << " I would be able to do it.\n";
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start3.txt");
    d.printDialogue(flName);
    d.dialogueContinue();

    std::cout << "Ma: \n";
    std::cout << "Yeah sure, but I will give you"
              << " 30 dollars every week to buy yourself,"
              << " taking the bus to downtown or maybe"
              << " what you said with hanging out with my friends."
              << fn
              << " , remember to spend wisely. Ok?\n";
    d.dialogueContinue();

    std::cout << fn << ": \n";
    std::cout << "'Yes Ma.'\n";
    d.dialogueContinue();

    p->setMoney(30.00);
    std::cout << "~Acquired $"
              << p->getMoney() << " from Ma~\n";
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start4.txt");
    d.printDialogue(flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start5.txt");
    d.printDialogue(flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start6.txt");
    d.printDialogue(flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start7.txt");
    d.printDialogue(flName);
    d.dialogueContinue();

    correct = false; // resets bool value
    do {
      std::cout << "[1] Near the platform\n";
      std::cout << "[2] Middle of the seats\n";
      std::cout << "[3] Next to the gym door\n";
      if (std::cin >> choices) {
        switch (choices) {
        case '1':
          flName = d.printFromFile("day1/morn/start8-11.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          flName = d.printFromFile("day1/morn/start8-12.txt");
          d.printDialogue("Quirky Principle", flName);
          d.dialogueContinue();

          std::cout << "\n"<< fn << ": \n";
          flName = d.printFromFile("day1/morn/start8-13.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          kno->levelUp();
          std::cout << "{Knowledge +1}\n";
          d.dialogueContinue();
          // denies key values
          kl = new KeyLines("1561314.1651.5", "1561314.1651.5");
          correct = true;
          break;
        case '2':
          flName = d.printFromFile("day1/morn/start8-21.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          flName = d.printFromFile("day1/morn/start8-22.txt");
          flName = d.highlightWord(flName, "$char",
                                    "English Teacher");
          d.printDialogue("Cocky Male Student", flName);
          d.dialogueContinue();

          flName = d.printFromFile("day1/morn/start8-23.txt");
          flName = d.highlightWord(flName, "$emp",
                                    "Hermit");
          d.printDialogue("Gossipy Male Student", flName);
          d.dialogueContinue();

          flName = d.printFromFile("day1/morn/start8-24.txt");
          d.printDialogue("Gossipy Female Student", flName);
          d.dialogueContinue();

          std::cout << "Gossipy Male Student: \n";
          std::cout << "'This is such a beta thing for him to do."
                    << " He should learn his lesson "
                    << "and he better f*** off bro.'\n";
          d.dialogueContinue();

          flName = d.printFromFile("day1/morn/start8-25.txt");
          d.printDialogue(fn, flName);
          d.dialogueContinue();

          und->levelUp();
          std::cout << "{Understanding +1}\n";
          d.dialogueContinue();

          //Code here the acquirement of dialogue line
          kl = new KeyLines("Hermit Rumor",
                            "sexual assault with host's girl");
          std::cout << "{I'll remember about that "
                    << kl->getKeyTitle() << "}\n";
          dm.addLine(kl);
          d.dialogueContinue();
          correct = true;
          break;
        case '3':
          flName = d.printFromFile("day1/morn/start8-31.txt");
          d.printDialogue(flName);
          correct = true;
          d.dialogueContinue();
          kl = new KeyLines("1561314.1651.5",
                            "1561314.1651.5");
          break;
        default:
          std::cout << "Wrong Value, Try Again..\n";
          d.dialogueContinue();
          correct = false;
          break;
        }
      }
    } while (!correct);
    flName = d.printFromFile("day1/morn/start9.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start10.txt");
    d.printDialogue("Charismatic Student", flName);
    d.dialogueContinue();

    correct = false; // resets bool value
    do {
      std::cout << fn << ": \n";
      std::cout << "Alex extends his arm offering to shake my hand."
                << " What should I do...\n";
      std::cout << "[1] Act normal & shake hands\n";
      std::cout << "[2] Lying about yourself & be pompous "
                << text.bold("(Requires Persuasive Charisma)\n");
      std::cout << "[3] Ignore and Leave The Gym\n";
      if (std::cin >> choices) {
        switch (choices) {
        case '1':
          std::cout << "I proceed to shake Alex's hand\n";
          d.dialogueContinue();

          std::cout << "'Hey, my name is "<< fn << " "<< ln
                    << ", and I am actually new here. "
                    << "I am in Grade 12 from the small town London Falls,"
                    << " I just recently moved here just yesterday.'\n";
          d.dialogueContinue();

          std::cout << "Alex: \n";
          std::cout << "'Wow, I never heard of the"
                    << " town London Falls before.'\n";
          d.dialogueContinue();

          std::cout << fn << ": \n";
          std::cout << "'It’s a two and a half drive to Calgary"
                    << " from the West of Alberta.'\n";
          d.dialogueContinue();
          correct = true;
          break;
        case '2':
          stLevelName = p->getStatLevelName(chr);
          if (chr->getLevel() >= 30) {
            std::cout << "'Well, I came from a rich"
                      << " family where I live at. "
                      << "And I have the highest grade of"
                      << " all in my small town. As I, "
                      << fn << " " << ln
                      << ", am the main character!”'\n";
            d.dialogueContinue();

            std::cout << "Alex: \n";
            std::cout << "'Okay? Well nice to me you. "
                      << "Nice to know that you are an interesting one. "
                      << "But a good one. "
                      << "There are more characters here in school"
                      << " that are more messed up.'\n";
            d.dialogueContinue();

            std::cout << fn<< ": \n";
            std::cout << "Oh crap I didn’t mean to say"
                      << " it that way to brag."
                      << " I mean to be cool, not cringe."
                      << " I really want to die inside.\n";
            correct = true;
            d.dialogueContinue();
          } else {
            std::cout << "'I am really am awkward"
                      << " to talk like that,"
                      << " because I have "
                      << text.bold(stLevelName)
                      << " Charisma...'\n\n";
            d.dialogueContinue();
          }
          break;
        case '3':
          std::cout << "Let me take my leave...\n";
          d.dialogueContinue();

          std::cout << "Alex: \n";
          std::cout << "'Hey! I am talking to you there!"
                    << " With the blue NASA shirt!'\n";
          d.dialogueContinue();

          std::cout << fn<< ": \n";
          std::cout << "I turned around awkwardly,"
                    << " and I felt abit of butterflies in my stomach."
                    << std::endl;
          d.dialogueContinue();

          std::cout << "'Me?! Um... I’m "
                    << fn << " "
                    << ln << ". I’m in grade 12.'\n";
          d.dialogueContinue();

          std::cout << "Alex: \n";
          std::cout << "'Which town did you come from,"
                    << " because I can tell you are not from here.'\n";
          d.dialogueContinue();

          std::cout << fn<< ": \n";
          std::cout << "'London Fall. Sorry if I am acting this way,"
                    << " because I am surprise you talked to me.'\n";
          d.dialogueContinue();

          std::cout << "Alex: \n";
          std::cout << "'No problem,"
                    << " it happens to a lot of new students here.'\n";
          d.dialogueContinue();
          correct = true;
          break;
        default:
          std::cout << "Wrong Value, Try Again...\n";
          d.dialogueContinue();
          correct = false;
          break;
        }
      }
    } while (!correct);
    flName = d.printFromFile("day1/morn/start11.txt");
    d.printDialogue("Alex", flName);
    d.dialogueContinue();

    std::cout << fn<< ": \n";
    std::cout << "'Yeah, I’ll go with you. Just why not.'\n";
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start12.txt");
    d.printDialogue(flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start13.txt");
    d.printDialogue("Alex", flName);
    d.dialogueContinue();

    std::cout << fn<< ": \n";
    std::cout << "'I am in all of the sciences"
              << " including Physics, Chemistry, and Biology.'"
              << std::endl;
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start14.txt");
    d.printDialogue("Alex", flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start15.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/morn/start16.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();
    return true;
    break;
  default:
    std::cout << "It's early morning."
              << " I have my breakfast and head to school.\n";
    d.dialogueContinue();
    return true;
    break;
  }
}

bool RoutineDialogueManager::printLunchRoutine(int day) {
  std::string fn = p->getFirstName();
  std::string ln = p->getLastName();
  std::string flName;
  std::cout << text.bold("LUNCH\n") << std::endl;
  std::stringstream buffer;
  switch (day) {
  case 1:
    flName = d.printFromFile("day1/lun/lunch1.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();

    correct = false; // resets bool value
    do {
      std::cout << fn << ": \n";
      std::cout << "I start lining up for food,"
                << " as me and Alex are lucky to line up really early. "
                << "So I get choose my food first,"
                << " but there so much packaged food for"
                << " different variety of food. "
                << "So have to pick one of them,"
                << " as I can’t just grab all of them. "
                << "Looking at the stacked food,"
                << " there are some that piqued my interests,"
                << " so let me grab:\n\n";
      std::cout << "[1] Roasted Pigeon & John Dory"
                << " with Cornish Cod\n";
      std::cout << "[2] Vegan Coleslaw Burger"
                << " with Sweet Potato Casserole\n";
      std::cout << "[3] Gluten-free Avocado Alfredo"
                << " with Gluten-Free Tomato Parmesan Soup\n";
      if (std::cin >> choices) {
        switch (choices) {
        case '1':
          std::cout << "\nAh this food."
                    << " This packaged food apparently "
                    << "came from Gordon Ramsay. So I’ll take this,"
                    << " because the food looks"
                    << " so mouth-savoury.\n";
          d.dialogueContinue();
          correct = true;
          break;
        case '2':
          std::cout << "\nAh this food."
                    << " I have never tried vegan food "
                    << "since most of them looked dry. "
                    << "But looking at this one makes me so hungry."
                    << " Let me grab that, just to try something new.\n";
          d.dialogueContinue();
          correct = true;
          break;
        case '3':
          std::cout << "\nAh this food."
                    << " I have a feeling that"
                    << " I need to eat something healthy,"
                    << " and it would be good for my body. "
                    << "Looking at this food is a blessing in"
                    << " disguise as it also"
                    << " makes me want to eat it.\n";
          d.dialogueContinue();
          correct = true;
          break;
        default:
          std::cout << "Wrong Value, Try Again..\n";
          d.dialogueContinue();
          correct = false;
          break;
        }
      }
    } while (!correct);
    std::cout << "\nI grabbed my food I chose,"
              << " and I walk straight where Alex already"
              << " sit and picked his food.\n";
    d.dialogueContinue();

    flName = d.printFromFile("day1/lun/lunch2.txt");
    d.printDialogue("Alex", flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/lun/lunch3.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/lun/lunch4.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();
    return true;
    break;
  default:
    std::cout << "It's lunchtime.\n";
    d.dialogueContinue();
    return true;
    break;
  }
}

bool RoutineDialogueManager::printAfternoonRoutine(int day) {
  std::string fn = p->getFirstName();
  std::string ln = p->getLastName();
  std::cout << text.bold("AFTERNOON\n") << std::endl;
  std::string flName;
  std::stringstream buffer;
  CharacterManager* cm = CharacterManager::getInstance();
  switch (day) {
  case 1: {
    flName = d.printFromFile("day1/aft/aft1.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/aft/aft2.txt");
    d.printDialogue("Alex", flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/aft/aft3.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();

    flName = text.bold(d.printFromFile("day1/aft/instructions.txt"));
    d.printDialogue("Instructions", flName);
    d.dialogueContinue();

    std::string response;
    Character* clubfr;
    correct = false; // resets bool value
    do {
      std::cout << fn << ": \n";
      std::cout << "Here are what clubs I am interested in:\n";
      std::cout << "[1] Student Council\n";
      std::cout << "[2] Mixed Soccer Team\n";
      std::cout << "[3] Mixed-Martial Arts Fighting Club\n";
      std::cout << "[4] Chess Club\n";
      std::cout << "[5] Cooking Club\n";
      std::cout << "[6] Orchestra\n";
      std::cout << "[7] Environmental Awareness Club\n";
      std::cout << "[8] Go-Home Club\n";
      if (std::cin >> choices) {
        switch (choices) {
        case '1':
          flName = d.printFromFile("day1/aft/aftChoice1.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          std::cout << "Are you sure you want to pick this one? (Yes or No)\n";
          usleep(800000);
          std::cin >> response;
          std::cin.ignore(1000, '\n');

          response = StringMagician::stringToLower(response);

          if (response == "yes"
              || response == "yeah"
              || response == "sure"
              || response == "y") {
            flName = d.printFromFile("day1/aft/aftChoice1Yes.txt");
            d.printDialogue(flName);
            d.dialogueContinue();
            p->setClub("Student Council");
            if (p->getGender() == 'f') {
              clubfr = new Character("Taylor", "Stentson", 'm');
            } else {
              clubfr = new Character("Taylor", "Stentson", 'f');
            }
            correct = true;
          } else if (response == "no"
                     || response == "nope"
                     || response == "never"
                     || response == "n") {
            correct = false;
          } else {
            std::cout << "I don't understand what you're"
                      << " saying can you repeat that?\n";
          }
          break;
        case '2':
          flName = d.printFromFile("day1/aft/aftChoice2.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          std::cout << "Are you sure you want to pick this one? (Yes or No)\n";
          usleep(800000);
          std::cin >> response;
          std::cin.ignore(1000, '\n');

          response = StringMagician::stringToLower(response);

          if (response == "yes"
              || response == "yeah"
              || response == "sure"
              || response == "y") {
            flName = d.printFromFile("day1/aft/aftChoice2Yes.txt");
            d.printDialogue(flName);
            d.dialogueContinue();
            p->setClub("Mixed Soccer Club");
            if (p->getGender() == 'f') {
              clubfr = new Character("Jordan", "Irene", 'm');
            } else {
              clubfr = new Character("Jordan", "Irene", 'f');
            }
            correct = true;
          } else if (response == "no"
                     || response == "nope"
                     || response == "never"
                     || response == "n") {
            correct = false;
          } else {
            std::cout << "I don't understand what you're"
                      << " saying can you repeat that?\n";
          }
          break;
        case '3':
          flName = d.printFromFile("day1/aft/aftChoice3.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          std::cout << "\nAre you sure you want"
                    << " to pick this one? (Yes or No)\n";
          usleep(800000);
          std::cin >> response;
          std::cin.ignore(1000, '\n');

          response = StringMagician::stringToLower(response);

          if (response == "yes"
              || response == "yeah"
              || response == "sure"
              || response == "y") {
            flName = d.printFromFile("day1/aft/aftChoice3Yes.txt");
            d.printDialogue(flName);
            d.dialogueContinue();
            p->setClub("MMA Fighting Club");
            if (p->getGender() == 'f') {
              clubfr = new Character("Riley", "Hayami", 'm');
            } else {
              clubfr = new Character("Riley", "Hayami", 'f');
            }
            correct = true;
          } else if (response == "no"
                     || response == "nope"
                     || response == "never"
                     || response == "n") {
            correct = false;
          } else {
            std::cout << "I don't understand what you're"
                      << " saying can you repeat that?\n";
          }
          break;
        case '4':
          flName = d.printFromFile("day1/aft/aftChoice4.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          std::cout << "\nAre you sure you want"
                    << " to pick this one? (Yes or No)\n";
          usleep(800000);
          std::cin >> response;
          std::cin.ignore(1000, '\n');

          response = StringMagician::stringToLower(response);

          if (response == "yes"
              || response == "yeah"
              || response == "sure"
              || response == "y") {
            flName = d.printFromFile("day1/aft/aftChoice4Yes.txt");
            d.printDialogue(flName);
            d.dialogueContinue();
            p->setClub("Chess Club");
            if (p->getGender() == 'f') {
              clubfr = new Character("Lei", "Jianlian", 'm');
            } else {
              clubfr = new Character("Lei", "Jianlian", 'f');
            }
            correct = true;
          } else if (response == "no"
                     || response == "nope"
                     || response == "never"
                     || response == "n") {
            correct = false;
          } else {
            std::cout << "I don't understand what you're"
                      << " saying can you repeat that?\n";
          }
          break;
        case '5':
          flName = d.printFromFile("day1/aft/aftChoice5.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          std::cout << "\nAre you sure you want"
                    << " to pick this one? (Yes or No)\n";
          usleep(800000);
          std::cin >> response;
          std::cin.ignore(1000, '\n');

          response
            = StringMagician::stringToLower(response);

          if (response == "yes"
              || response == "yeah"
              || response == "sure"
              || response == "y") {
            flName = d.printFromFile("day1/aft/aftChoice5Yes.txt");
            d.printDialogue(flName);
            d.dialogueContinue();
            p->setClub("Cooking Club");
            if (p->getGender() == 'f') {
              clubfr = new Character("Blaine", "Aziz", 'm');
            } else {
              clubfr = new Character("Blaine", "Aziz", 'f');
            }
            correct = true;
          } else if (response == "no"
                     || response == "nope"
                     || response == "never"
                     || response == "n") {
            correct = false;
          } else {
            std::cout << "I don't understand what"
                      << " you're saying can you repeat that?\n";
          }
          break;
        case '6':
          flName = d.printFromFile("day1/aft/aftChoice6.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          std::cout << "Are you sure you want to pick this one? (Yes or No)\n";
          usleep(800000);
          std::cin >> response;
          std::cin.ignore(1000, '\n');

          response = StringMagician::stringToLower(response);

          if (response == "yes"
              || response == "yeah"
              || response == "sure"
              || response == "y") {
            flName = d.printFromFile("day1/aft/aftChoice6Yes.txt");
            d.printDialogue(flName);
            d.dialogueContinue();
            if (p->getGender() == 'f') {
              clubfr = new Character("Jaime", "Santiago", 'm');
            } else {
              clubfr = new Character("Jaime", "Santiago", 'f');
            }
            correct = true;
          } else if (response == "no"
                     || response == "nope"
                     || response == "never"
                     || response == "n") {
            correct = false;
          } else {
            std::cout << "I don't understand what"
                      << " you're saying can you repeat that?\n";
          }
          break;
        case '7':
          flName = d.printFromFile("day1/aft/aftChoice7.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          std::cout << "\nAre you sure you want"
                    << " to pick this one? (Yes or No)\n";
          usleep(800000);
          std::cin >> response;
          std::cin.ignore(1000, '\n');

          response = StringMagician::stringToLower(response);

          if (response == "yes"
              || response == "yeah"
              || response == "sure"
              || response == "y") {
            flName = d.printFromFile("day1/aft/aftChoice7Yes.txt");
            d.printDialogue(flName);
            d.dialogueContinue();

            p->setClub("Enviromental Awareness Club");
            if (p->getGender() == 'f') {
              clubfr = new Character("Adrian", "Golubović", 'm');
            } else {
              clubfr = new Character("Adrian", "Golubović", 'f');
            }
            correct = true;
          } else if (response == "no"
                     || response == "nope"
                     || response == "never"
                     || response == "n") {
            correct = false;
          } else {
            std::cout << "I don't understand what you're"
                << " saying can you repeat that?\n";
          }
          break;
        case '8':
          flName = d.printFromFile("day1/aft/aftChoice8.txt");
          d.printDialogue(flName);
          d.dialogueContinue();

          std::cout << "\nAre you sure you want"
                    << " to pick this one? (Yes or No)\n";
          usleep(800000);
          std::cin >> response;
          std::cin.ignore(1000, '\n');

          response = StringMagician::stringToLower(response);

          if (response == "yes"
              || response == "yeah"
              || response == "sure"
              || response == "y") {
            flName = d.printFromFile("day1/aft/aftChoice8Yes.txt");
            d.printDialogue(flName);
            d.dialogueContinue();
            p->setClub("Go-Home Club");
            if (p->getGender() == 'f') {
              clubfr = new Character("Kyrie ", "Low ", 'm');
            } else {
              clubfr = new Character("Kyrie ", "Low ", 'f');
            }
            correct = true;
          } else if (response == "no"
                     || response == "nope"
                     || response == "never"
                     || response == "n") {
            correct = false;
          } else {
            std::cout << "I don't understand what"
                      << " you're saying can you repeat that?\n";
          }
          break;
        default:
          std::cout << "Wrong Value, Try Again..\n";
          d.dialogueContinue();
          correct = false;
          break;
        }
      }
    } while (!correct);

    clubfr->setClub(p->getClub());
    cm->addCharacter(clubfr);

    flName = d.printFromFile("day1/aft/aft4.txt");
    d.printDialogue("Alex", flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/aft/aft5.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/aft/aft6.txt");
    d.printDialogue(flName);
    d.dialogueContinue();

    std::cout << "Timid Student: \n";
    std::cout << "'Sorry! Sorry… Won’t do that again.'\n";
    d.dialogueContinue();

    flName = d.printFromFile("day1/aft/aft7.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/aft/aft8.txt");
    flName = d.highlightWord(flName, "$char", "Fred");
    d.printDialogue("Alex", flName);
    d.dialogueContinue();

    buffer << flName;

    //if user heard obtain line
    //KeyLines("Hermit Rumor", "sexual assault with host's girl");
    if (kl->containsKeyWord(buffer.str())) {
      std::cout << fn<< ": \n";
      std::cout << "Oh yeah I remembered about the "
                << kl->getKeyTitle() << ", and the " <<
                kl->getKeyLines() << "!\n";
      d.dialogueContinue();

      flName = d.printFromFile("day1/aft/aft9If.txt");
      d.printDialogue(flName);
      d.dialogueContinue();

      std::cout << "Alex: \n";
      std::cout << "'Wow… That’s deep.'\n";
      d.dialogueContinue();

      flName = d.printFromFile("day1/aft/aft9If2.txt");
      d.printDialogue(fn, flName);
      d.dialogueContinue();

      und->levelUp();
      std::cout << "{Understanding +1}\n";
      d.dialogueContinue();

      chr->levelUp();
      std::cout << "{Charisma +1}\n";
      d.dialogueContinue();

    } else {
      flName = d.printFromFile("day1/aft/aft9Else.txt");
      d.printDialogue(fn, flName);
      d.dialogueContinue();
    }

    flName = d.printFromFile("day1/aft/aft10.txt");
    d.printDialogue("Alex", flName);
    d.dialogueContinue();

    flName = d.printFromFile("day1/aft/aft11.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();
    return true;
    break;
  }
  default:
    std::cout << "The school bell rang"
              << " as the Lunch time ends.\n";
    d.dialogueContinue();
    return true;
    break;
  }
}

bool RoutineDialogueManager::printAfterSchoolRoutine(int day) {
  CharacterManager *cm = CharacterManager::getInstance();
  std::string fn = p->getFirstName();
  std::string ln = p->getLastName();
  std::string response;
  std::string flName;
  std::cout << text.bold("AFTERSCHOOL\n") << std::endl;
  std::stringstream buffer;
  switch (day) {
  case 1: {
    std::cout << fn<< ": \n";
    std::cout << "Anyways, we continued walking outside,"
              << " and I am stopped by Alex to ask about something.\n";
    d.dialogueContinue();

    std::cout << "Alex: \n";
    std::cout << "'"
              << fn
              << ", do you have time to hangout with me sometime? "
              << "Because I thought it would be"
              << " more fun to do that"
              << " since we met just now'\n";
    d.dialogueContinue();

    flName = d.printFromFile("day1/afsc/instructions.txt");
    d.printDialogue("Instructions", flName);
    d.dialogueContinue();


    std::cout << fn<< ": \n";
    std::cout << "So what should I say? (Yes or No)\n";
    usleep(800000);
    getline(std::cin, response);
    response = StringMagician::stringToLower(response);

    bool correctInput = false;
    do {
      if (response == "yes" || response == "yeah" || response == "sure"
          || response == "y") {
        std::cout << fn << ": \n";
        std::cout << "'Sure, where we are going?'\n";
        d.dialogueContinue();

        flName = d.printFromFile("day1/afsc/afterSchool1Yes1.txt");
        d.printDialogue("Alex", flName);
        d.dialogueContinue();

        std::cout << fn<< ": \n";
        std::cout << "'Yeah I have 30 bucks"
                  << " in my pocket.'\n";
        d.dialogueContinue();

        std::cout << "Alex: \n";
        std::cout << "'Alright,"
                  << " let’s go to the public bus,"
                  << " before we miss it.'\n";
        d.dialogueContinue();

        flName = d.printFromFile("day1/afsc/afterSchool1Yes2.txt");
        d.printDialogue(fn, flName);
        d.dialogueContinue();
        p->setMoney(p->spendMoney(2.00));

        std::cout << "{Currently have $"
                  << p->getMoney() << "}\n";
        d.dialogueContinue();

        flName = d.printFromFile("day1/afsc/afterSchool1Yes3.txt");
        d.printDialogue(fn, flName);
        d.dialogueContinue();

        correct = false; // resets bool value
        do {
          std::cout << "Let me see what should I buy:\n";
          std::cout << "[1] Protein Chicken Burger Meal"
                    << " - $8.00\n";
          std::cout << "[2] Green Salad Meal"
                    << " - $10.00\n";
          std::cout << "[3] Egg Potato Wrap Meal"
                    << " - $9.00\n";
          std::cout << "[4] Nothing"
                    << " - $0.00\n";
          if (std::cin >> choices) {
            switch (choices) {
            case '1':
              std::cout << "\nI bought the burger"
                        << " which should be good for my muscles.\n";
              d.dialogueContinue();

              ath->levelUp();
              std::cout << "{Athleticism +1}\n";
              d.dialogueContinue();

              p->setMoney(p->spendMoney(8.00));

              std::cout << "{Currently have " << p->getMoney() << "}\n";
              d.dialogueContinue();

              correct = true;
              break;
            case '2':
              std::cout << "\nI bought the salad"
                        << " which should be good for my brain.\n";
              d.dialogueContinue();

              kno->levelUp();
              std::cout << "{Knowledge +1}\n";
              d.dialogueContinue();

              p->setMoney(p->spendMoney(10.00));

              std::cout << "{Currently have " << p->getMoney() << "}\n";
              d.dialogueContinue();

              correct = true;
              break;
            case '3':
              std::cout << "\nI bought the wrap"
                        << " which should be good for my reflexes.\n";
              d.dialogueContinue();

              ath->levelUp();
              std::cout << "{Athleticism +1}\n";
              d.dialogueContinue();

              p->setMoney(p->spendMoney(9.00));

              std::cout << "{Currently have " << p->getMoney() << "}\n";
              d.dialogueContinue();

              correct = true;
              break;
            case '4':
              std::cout << "\nI will buy nothing...\n";
              d.dialogueContinue();
              correct = true;
              break;
            default:
              std::cout << "Wrong Value, Try Again..\n";
              d.dialogueContinue();
              correct = false;
              break;
            }
          }
        } while (!correct);

        std::cout << "\nI walked to the empty table"
                  << " as I found the seat to eat some food with Alex. "
                  << "We make some jokes on what happened"
                  << " in the school orientation, "
                  << "and have fun talking to each other. "
                  << "I have a feeling that Alex is really"
                  << " enjoy around as my friend."
                  << " I feel like we have an unbreakable bond."<<
                  std::endl;
        d.dialogueContinue();

        std::cout << "{You and "
                  << cm->getCharacter(fr)->getFirstName()
                  << " became "
                  << cm->getCharacter(fr)->affectionLevelName()
                  << "}\n";
        d.dialogueContinue();

        std::cout << "After we are done eating,"
                  << " the sky is dark as it is our time to go home.\n";
        d.dialogueContinue();

        flName = d.printFromFile("day1/afsc/afterSchool1Yes4.txt");
        d.printDialogue("Alex", flName);
        d.dialogueContinue();

        flName = d.printFromFile("day1/afsc/afterSchool1Yes5.txt");
        d.printDialogue(fn, flName);
        d.dialogueContinue();

        correctInput = true;
      } else if (response == "no"
                 || response == "nope"
                 || response == "never"
                 || response == "n") {
        std::cout << fn << ": \n";
        std::cout << "'Sorry I can’t,"
                  << " I have something to do at home."
                  << " But next time, we can hangout.'\n";
        d.dialogueContinue();
        correctInput = true;
      } else {
        std::cout << "I don't understand"
                  << " what your saying can"
                  << " you repeat that?\n";
      }
    } while (!correctInput);
    std::cout << "Alex: \n";
    std::cout << "'Nice to meet you though."
              << " I am very happy for you"
              << " be my friend. "
              << "Whatever happens,"
              << " just ask me for anything."
              << " I will try to do my"
              << " best to help you, "
              << "since we are "
              << text.bold("Genuine Friends")
              << ". We should do something"
              << " like this again!'\n";
    d.dialogueContinue();

    std::cout << "'Alright see you"
              << " tomorrow’s English class!'\n";
    d.dialogueContinue();

    std::cout << fn << ": \n";
    std::cout << "'See ya!'\n";
    d.dialogueContinue();

    flName = d.printFromFile("day1/afsc/afterSchool2.txt");
    d.printDialogue(flName);
    d.dialogueContinue();
    return true;
    break;
  }
  case 6: {
    std::cout << fn<< ": \n";
    std::cout << "Somebody in my class is"
              << " on the top of the roof as I see"
              << " from the classroom window. It’s "
              << text.bold("FRED")
              << "?! Oh my god, why? I can’t"
              << " just monologue myself like this,"
              << " because he’s ready to"
              << " drop off to the school grounds,"
              << " and… I don’t know what to do?\n";
    d.dialogueContinue();

    std::cout << "Should I… I… i.. *gasp* \n";
    d.dialogueContinue();

    std::cout << "Alright Fred I don’t"
              << " want you to die on me,"
              << " I am going to do my very"
              << " best on myself to help you,"
              << " because we’ve talked to"
              << " each other, I helped"
              << " you get away from your"
              << " bullies,"
              << " and I’ll help you every way"
              << " I can with my "
              << text.bold("Charisma")
              << ", "
              << text.bold("Knowledge")
              << ", "
              << text.bold("Athletics")
              << ", "
              << text.bold("Proficiency")
              << ", "
              << text.bold("Understanding")
              << ", and "
              << text.bold("Courage")
              << " to stop this from happening!\n";
    d.dialogueContinue();
    break;
  }
  default: {
    std::cout << "School is now over."
              << " I prepare my things and"
              << " get ready to"
              << " leave the classroom.\n";
    d.dialogueContinue();
    return true;
    break;
  }
  }
}

bool RoutineDialogueManager::printEndOfDay(int day) {
  std::string fn = p->getFirstName();
  std::string ln = p->getLastName();
  std::cout << text.bold("EVENING\n") << std::endl;
  std::string flName;
  std::stringstream buffer;
  switch (day) {
  case 1:
    flName = d.printFromFile("day1/eve/end1.txt");
    d.printDialogue(fn, flName);
    d.dialogueContinue();

    std::cout << "Pa: \n";
    std::cout << fn; // Continued
    flName = d.printFromFile("day1/eve/end2.txt");
    d.printDialogue(flName);
    d.dialogueContinue();

    std::cout << fn<< ": \n";
    std::cout << "'Ok. Yes Pa.'\n";
    d.dialogueContinue();
    flName = d.printFromFile("day1/eve/end3.txt");
    d.printDialogue(flName);
    d.dialogueContinue();
    return true;
    break;
  default:
    std::cout << "I've had a good day, "
              << "and I am going to sleep at home\n";
    d.dialogueContinue();
    return true;
    break;
  }
}

