#include <string>
#include <iostream>
#include "Dialogue.h"
#include "StringMagician.h"
#include "Event.h"
#include "Choice.h"
#include "Dialogue.h"
#include "EventMaker.h"

Event EventMaker::secondDayMorning() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  //Event for second morning
  Date date("Week 1", 2);
  Event e("English", date,
          Event::freeTimeType::MORNING);
  dialogue = d.printFromFile("day2/user/morn/morn.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Ignore", true);
  Choice c2("Listen", true);


  dialogue = d.printFromFile("day2/user/morn/morn1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day2/user/morn/morn2-1.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day2/eng/eng1.txt");
  dialogue = d.highlightWord(dialogue, "$ans"
                             , "All The Boys");
  c2.addResultSentence(d.getDialogue("Mr. Clause", dialogue));

  dialogue = d.printFromFile("day2/eng/eng2.txt");
  c2.addResultSentence(d.getDialogue(dialogue));


  dialogue = d.printFromFile("day2/user/morn/morn2-2.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  e.addChoice(c1);
  e.addChoice(c2);

  return e;
}

Event EventMaker::secondDayLunch() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  // Event 2 Lunch
  Date date("Week 1", 2);
  Event e("Cafeteria", date, Event::freeTimeType::LUNCH);
  dialogue = d.printFromFile("day2/user/lun/lun.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Sit Alone", true);
  Choice c2("Go with Alex", true);
  Choice c3("Leave Cafeteria", true);

  dialogue = d.printFromFile("day2/user/lun/lun1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day2/user/lun/lun2.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day2/user/lun/lun3.txt");
  c3.addResultSentence(d.getDialogue(dialogue));

  c1.setAffectStat(true);
  c1.setStatToAffect("guts");

  e.addChoice(c1);
  e.addChoice(c2);
  e.addChoice(c3);

  return e;
}

Event EventMaker::secondDayAfternoon() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 1", 2);
  // Event 2 Afternoon
  Event e("Social", date,
          Event::freeTimeType::AFTERNOON);

  dialogue = d.printFromFile("day2/user/aft/aft.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Ignore", true);
  Choice c2("Listen", true);

  dialogue = d.printFromFile("day2/user/aft/aft1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day2/user/aft/aft2-1.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day2/soc/soc1.txt");
  dialogue = d.highlightWord(dialogue, "$que",
                             "Who's Canada's Prime Minister on 1949?");
  c2.addResultSentence(d.getDialogue("Mr. Mephistopheles", dialogue));

  dialogue = d.printFromFile("day2/soc/soc2.txt");
  dialogue = d.highlightWord(dialogue, "$ans", "Louis Stephen St. Laurent");
  c2.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day2/user/aft/aft2-2.txt");
  c2.addResultSentence(d.getDialogue(fn, dialogue));

  e.addChoice(c1);
  e.addChoice(c2);

  return e;
}

Event EventMaker::secondDayAfterSchool() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 1", 2);

  // Event 2 Afterschool
  Event e("Get A Job", date, Event::freeTimeType::AFTERSCHOOL);
  dialogue = d.printFromFile("day2/user/afsc/afsc.txt");
  e.addIntroSentence(d.getDialogue(fn,
                                   dialogue));
  Choice c1("Sales Associate", true);
  Choice c2("Mover", true);
  Choice c3("Dog Walker", true);
  Choice c4("Call Center Representative", true);
  Choice c5("Waiter", true);
  Choice c6("Lifeguard", true);
  Choice c7("Drug Dealer?", false);

  c1.getAJob(true);
  c2.getAJob(true);
  c3.getAJob(true);
  c4.getAJob(true);
  c5.getAJob(true);
  c6.getAJob(true);

  dialogue = d.printFromFile("day2/user/afsc/afsc1to6.txt");

  std::string c11 = d.highlightWord(dialogue, "$loc", "ON Mobile");
  c11 = d.highlightWord(c11, "$job", "Sales Associate");
  c1.addResultSentence(d.getDialogue(c11));

  std::string c12 = d.highlightWord(dialogue, "$loc", "UHaul");
  c12 = d.highlightWord(c12, "$job", "Mover");
  c2.addResultSentence(d.getDialogue(c12));

  std::string c13 = d.highlightWord(dialogue, "$loc", "PetSitter");
  c13 = d.highlightWord(c13, "$job", "Dog Walker");
  c3.addResultSentence(d.getDialogue(c13));

  std::string c14 = d.highlightWord(dialogue, "$loc", "Red Cross");
  c14 = d.highlightWord(c14, "$job", "Call Center Representative");
  c4.addResultSentence(d.getDialogue(c14));

  std::string c15 = d.highlightWord
  (dialogue, "$loc", "Benjamin Diner & Restaurant");
  c15 = d.highlightWord(c15, "$job", "Waiter");
  c5.addResultSentence(d.getDialogue(c15));

  std::string c16 = d.highlightWord(dialogue, "$loc",
                                    "Acadia Aquatic Center");
  c16 = d.highlightWord(c16, "$job", "Lifeguard");
  c6.addResultSentence(d.getDialogue(c16));

  dialogue = d.printFromFile("day2/user/afsc/afsc7.txt");
  c7.addResultSentence(d.getDialogue(dialogue));

  e.addChoice(c1);
  e.addChoice(c2);
  e.addChoice(c3);
  e.addChoice(c4);
  e.addChoice(c5);
  e.addChoice(c6);
  e.addChoice(c7);

  return e;
}

Event EventMaker::thirdDayMorning() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 1", 3);

  Event e("Chemistry", date,
          Event::freeTimeType::MORNING);

  dialogue = d.printFromFile("day3/user/morn/morn.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Ignore", true);
  Choice c2("Listen", true);

  dialogue = d.printFromFile("day3/user/morn/morn1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/user/morn/morn2-1.txt");
  c2.addResultSentence(d.getDialogue(dialogue));
  dialogue = d.printFromFile("day3/chem/chem1.txt");
  dialogue = d.highlightWord(dialogue, "$ans", "118");
  c2.addResultSentence(d.getDialogue("Ms.Fluorious", dialogue));
  dialogue = d.printFromFile("day3/user/morn/morn2-2.txt");
  c2.addResultSentence(d.getDialogue(fn, dialogue));

  e.addChoice(c1);
  e.addChoice(c2);

  return e;
}

Event EventMaker::thirdDayLunch() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 1", 3);

  // Event 3 Lunch
  Event e("Cafeteria", date, Event::freeTimeType::LUNCH);

  dialogue = d.printFromFile("day3/user/lun/lun.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Ignore", true);
  Choice c2("Respond", true);

  dialogue = d.printFromFile("day3/user/lun/lun1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/user/lun/lun2-1.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/user/lun/lun2-2.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/user/lun/lun2-3.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  c2.setAffectStat(true);
  c2.setStatToAffect("charisma");
  c2.setAffectStat(true);
  c2.setStatToAffect("guts");

  e.addChoice(c1);
  e.addChoice(c2);

  return e;
}

Event EventMaker::thirdDayAfternoon() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 1", 3);

  Event e("Biology", date,
          Event::freeTimeType::AFTERNOON);

  dialogue = d.printFromFile("day3/user/aft/aft.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Ignore", true);
  Choice c2("Listen", true);

  dialogue = d.printFromFile("day3/user/aft/aft1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/user/aft/aft2-1.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/bio/bio1.txt");
  dialogue = d.highlightWord(dialogue, "$ans", "Mitochondria");
  c2.addResultSentence(d.getDialogue("Mrs. Fishsticks", dialogue));

  dialogue = d.printFromFile("day3/user/aft/aft2-2.txt");
  c2.addResultSentence(d.getDialogue(fn, dialogue));

  e.addChoice(c1);
  e.addChoice(c2);

  return e;
}

Event EventMaker::thirdDayAfterSchool() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 1", 3);

  Event e("Go Home", date, Event::freeTimeType::AFTERSCHOOL);

  dialogue = d.printFromFile("day3/user/afsc/afsc.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Play Video Games", true); // Proficiency
  Choice c2("Use Treadmill", true); // Athleticism
  Choice c3("Study", true); // Knowledge
  Choice c4("Watch Movie", true); // Guts
  Choice c5("Talk with Ma", true); // Understanding
  Choice c6("Read Books", true); // Charisma

  dialogue = d.printFromFile("day3/user/afsc/afsc1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/user/afsc/afsc2.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/user/afsc/afsc3.txt");
  c3.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/user/afsc/afsc4.txt");
  c4.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/user/afsc/afsc5.txt");
  c5.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day3/user/afsc/afsc6.txt");
  c6.addResultSentence(d.getDialogue(dialogue));

  c1.setAffectStat(true); // Setting up a choice to affect stat
  c1.setStatToAffect("proficiency");
  c2.setAffectStat(true); // Setting up a choice to affect stat
  c2.setStatToAffect("athleticism");
  c3.setAffectStat(true); // Setting up a choice to affect stat
  c3.setStatToAffect("knowledge");
  c4.setAffectStat(true); // Setting up a choice to affect stat
  c4.setStatToAffect("guts");
  c5.setAffectStat(true); // Setting up a choice to affect stat
  c5.setStatToAffect("understanding");
  c6.setAffectStat(true); // Setting up a choice to affect stat
  c6.setStatToAffect("charisma");

  e.addChoice(c1);
  e.addChoice(c2);
  e.addChoice(c3);
  e.addChoice(c4);
  e.addChoice(c5);
  e.addChoice(c6);

  return e;
}

Event EventMaker::fourthDayMorning() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  // Morning Class 4
  Date date("Week 1", 4);
  Event e("Gym", date, Event::freeTimeType::MORNING);

  dialogue = d.printFromFile("day4/user/morn/morn.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  dialogue = d.printFromFile("day4/gym/gym1.txt");
  e.addIntroSentence(d.getDialogue("Mrs. Bullock", dialogue));
  e.addIntroSentence("You came to your first day at Gym Class.");

  dialogue = d.printFromFile("day4/user/morn/morn1.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Fast", true);
  Choice c2("Slow", true);

  dialogue = d.printFromFile("day4/user/morn/morn1-1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));
  dialogue = d.printFromFile("day4/user/morn/morn1-2.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day4/user/morn/morn2-1.txt");
  c2.addResultSentence(d.getDialogue(dialogue));
  dialogue = d.printFromFile("day4/user/morn/morn2-2.txt");
  c2.addResultSentence(d.getDialogue(dialogue));
  dialogue = d.printFromFile("day4/user/morn/morn2-3.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  c1.setAffectStat(true);
  c1.setStatToAffect("athleticism");
  c2.setAffectStat(true);
  c2.setStatToAffect("guts");

  e.addChoice(c1);
  e.addChoice(c2);

  return e;
}

Event EventMaker::fourthDayLunch() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 1", 4);

  // Event 4 Lunch
  Event e("Cafeteria", date, Event::freeTimeType::LUNCH);

  dialogue = d.printFromFile("day4/user/lun/lun.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Steal fries", true);
  Choice c2("Do not steal fries", true);

  dialogue = d.printFromFile("day4/user/lun/lun1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day4/user/lun/lun2.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  e.addChoice(c1);
  e.addChoice(c2);

  return e;
}

Event EventMaker::fourthDayAfternoon() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 1", 4);

  // Afternoon Class 4
  Event e("Health", date, Event::freeTimeType::AFTERNOON);
  dialogue = d.printFromFile("day4/user/aft/aft.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Ignore", true);
  Choice c2("Listen", true);

  dialogue = d.printFromFile("day4/user/aft/aft1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));


  dialogue = d.printFromFile("day4/user/aft/aft2-1.txt");
  c2.addResultSentence(d.getDialogue(dialogue));
  dialogue = d.printFromFile("day4/hel/hel1.txt");
  dialogue = d.highlightWord(dialogue, "$emp", "Gifts");
  c2.addResultSentence(d.getDialogue("Mr. Bacillus", dialogue));
  dialogue = d.printFromFile("day4/user/aft/aft2-2.txt");
  c2.addResultSentence(d.getDialogue(fn, dialogue));

  e.addChoice(c1);
  e.addChoice(c2);

  return e;
}

Event EventMaker::fourthDayAfterSchool() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 1", 4);

  // Event 4 Afterschool
  Event e("Invitation from Alex", date, Event::freeTimeType::AFTERSCHOOL);
  dialogue = d.printFromFile("day4/user/afsc/afsc.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("No", true);
  Choice c2("Yes", false);
  Choice c3("Dip", true);

  dialogue = d.printFromFile("day4/user/afsc/afsc1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day4/user/afsc/afsc2-1.txt");
  c2.addResultSentence(d.getDialogue(dialogue));
  dialogue = d.printFromFile("day4/user/afsc/afsc2-2.txt");
  c2.addResultSentence(d.getDialogue(dialogue));
  dialogue = d.printFromFile("day4/user/afsc/afsc2-3.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day4/user/afsc/afsc3.txt");
  c3.addResultSentence(d.getDialogue(dialogue));

  e.addChoice(c1);
  e.addChoice(c2);
  e.addChoice(c3);

  return e;
}

Event EventMaker::fifthDayMorning() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 2", 5);

  // Morning Class 5
  Event e("FINALS", date, Event::freeTimeType::MORNING);
  dialogue = d.printFromFile("day5/finals/start.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));
  dialogue = d.printFromFile("day5/finals/q1.txt");
  e.addIntroSentence(d.getDialogue(dialogue));

  Choice c1("All The Boys", true);
  Choice c2("William Golding", true);
  Choice c3("The Man Beast Pigs", true);

  c1.addResultSentence("Correct!");
  c2.addResultSentence("Wrong!");
  c2.addResultSentence("The answer is 'All The Boys'");
  c3.addResultSentence("Wrong!");
  c3.addResultSentence("The answer is 'All The Boys'");

  c1.setAffectStat(true);
  c1.setStatToAffect("knowledge");

  e.addChoice(c1);
  e.addChoice(c2);
  e.addChoice(c3);

  return e;
}

Event EventMaker::fifthDayLunch() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 2", 5);

  // Event 5 Lunch
  Event e("FINALS", date, Event::freeTimeType::LUNCH);
  dialogue = d.printFromFile("day5/finals/q2.txt");
  e.addIntroSentence(d.getDialogue(dialogue));

  Choice c1("William Lyon Mackenzie King", true);
  Choice c2("Louis Stephen St. Laurent", true);
  Choice c3("Pierre Trudeau ", true);

  c1.addResultSentence("Wrong!");
  c1.addResultSentence("It's Louis Stephen St. Laurent");
  c2.addResultSentence("Correct!");
  c3.addResultSentence("Wrong!");
  c3.addResultSentence("It's Louis Stephen St. Laurent");

  c2.setAffectStat(true);
  c2.setStatToAffect("knowledge");

  e.addChoice(c1);
  e.addChoice(c2);
  e.addChoice(c3);

  return e;
}

Event EventMaker::fifthDayAfternoon() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 2", 5);

  // Afternoon Class 5
  Event e("FINALS", date, Event::freeTimeType::AFTERNOON);
  dialogue = d.printFromFile("day5/finals/q3.txt");
  e.addIntroSentence(d.getDialogue(dialogue));

  Choice c1("120", true);
  Choice c2("119", true);
  Choice c3("108", true);
  Choice c4("None of Them", true);

  c1.addResultSentence("Wrong!");
  c1.addResultSentence("The answer is '118'");
  c2.addResultSentence("Wrong!");
  c2.addResultSentence("The answer is '118'");
  c3.addResultSentence("Correct!");
  c4.addResultSentence("Wrong!");
  c4.addResultSentence("The answer is '118'");

  e.addChoice(c1);
  e.addChoice(c2);
  e.addChoice(c3);
  e.addChoice(c4);

  return e;
}

Event EventMaker::fifthDayAfterSchool() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 2", 5);

  // Event 5 Afterschool
  Event e("FINALS", date, Event::freeTimeType::AFTERSCHOOL);
  dialogue = d.printFromFile("day5/finals/q4.txt");
  e.addIntroSentence(d.getDialogue(dialogue));

  Choice c1("Mitochondria", true);
  Choice c2("Chromosome", true);
  Choice c3("Endoplasmic", true);

  c1.addResultSentence("Correct!");
  c2.addResultSentence("Wrong!");
  c2.addResultSentence("The answer is 'Mitochondria'");
  c3.addResultSentence("Wrong!");
  c3.addResultSentence("The answer is 'Mitochondria'");

  c1.setAffectStat(true);
  c1.setStatToAffect("knowledge");

  e.addChoice(c1);
  e.addChoice(c2);
  e.addChoice(c3);

  return e;
}

Event EventMaker::sixthDayMorning() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 2", 6);

  // Morning Class 6
  Event e("Math", date, Event::freeTimeType::MORNING);

  dialogue = d.printFromFile("day6/user/morn/morn.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Ignore", true);
  Choice c2("Listen", true);

  dialogue = d.printFromFile("day6/user/morn/morn1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day6/user/morn/morn2-1.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day6/math/math1.txt");
  c2.addResultSentence(d.getDialogue("Ms. Mobius", dialogue));

  dialogue = d.printFromFile("day6/user/morn/morn2-2.txt");
  c2.addResultSentence(d.getDialogue(fn, dialogue));

  e.addChoice(c1);
  e.addChoice(c2);

  return e;
}

Event EventMaker::sixthDayLunch() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 2", 6);

  // Event 6 Lunch
  Event e("Cafeteria", date, Event::freeTimeType::LUNCH);
  dialogue = d.printFromFile("day6/user/lun/lun.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));

  Choice c1("Sit with Fred", true);
  Choice c2("Sit Alone", true);

  dialogue = d.printFromFile("day6/user/lun/lun1.txt");
  c1.addResultSentence(d.getDialogue(dialogue));

  dialogue = d.printFromFile("day6/user/lun/lun2.txt");
  c2.addResultSentence(d.getDialogue(dialogue));

  e.addChoice(c1);
  e.addChoice(c2);

  return e;
}

Event EventMaker::sixthDayAfternoon() {
  StringMagician text;
  Dialogue d;
  std::string dialogue;
  Player *p = Player::getInstance();
  std::string fn = p->getFirstName();

  Date date("Week 2", 6);

  // Event 6 Afternoon
  Event e("Physics", date,
          Event::freeTimeType::AFTERNOON);
  dialogue = d.printFromFile("day6/user/aft/aft.txt");
  e.addIntroSentence(d.getDialogue(fn, dialogue));
  dialogue = d.printFromFile("day6/phys/phys1.txt");
  e.addIntroSentence(d.getDialogue("Mr. Gravy", dialogue));

  Choice c1("E = mc^2", true);
  Choice c2("a^2 + b^2 = c^2", true);
  Choice c3("x = VC", true);

  c1.addResultSentence(d.getDialogue("Correct!"));
  dialogue = d.printFromFile("day6/user/aft/aft1.txt");
  c1.addResultSentence(d.getDialogue(fn, dialogue));

  c2.addResultSentence(d.getDialogue("Wrong!"));
  dialogue = d.printFromFile("day6/user/aft/aft2to3.txt");
  c2.addResultSentence(d.getDialogue(fn, dialogue));

  c3.addResultSentence(d.getDialogue("Wrong!"));
  dialogue = d.printFromFile("day6/user/aft/aft2to3.txt");
  c3.addResultSentence(d.getDialogue(fn, dialogue));

  c1.setAffectStat(true);
  c1.setStatToAffect("knowledge");

  e.addChoice(c1);
  e.addChoice(c2);
  e.addChoice(c3);

  return e;
}
