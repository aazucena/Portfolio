#ifndef GIFT_H_INCLUDED
#define GIFT_H_INCLUDED
#include "Character.h"
#include "Item.h"
#include <string>

class Gift: public Item {
 public:
  enum GiftType {Food, Clothes, Plants};
  Gift() {}

  /**
  * Constructor of Event.
  * @param ev Name of the Event ("Unknown").
  * @param d Date of the event.
  * @param f Showing what time in the day the Event is available. Either LUNCH or AFTERNOON
  * @param available bool value saying an event is available everyday
  */
  Gift(GiftType type, std::string desc, int mod,
       double val, std::string it, int qt, bool owned);

  Gift(GiftType type, std::string desc, int mod);
  /**
  * Destructor of Item.
  */
  virtual ~Gift() {}

  bool giveToCharacter(Character c);

  std::string getGiftDescription();

  int getGiftAffMod();

  void setGiftAffMod(int mod);

  /**
  * Gift Type based on gender.
  */
  GiftType getGiftType();
  void printItemInfo();

 private:
  /**
  * Id of The Item.
  */
  int affectionMod;

  /**
  * Description of The Event.
  */
  std::string description;

  int quantity;

  GiftType giftType;
};

#endif // GIFT_H_INCLUDED
