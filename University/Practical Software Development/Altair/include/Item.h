#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <string>

class Item {
 public:
  Item();

  /**
  * Constructor of Event.
  * @param ev Name of the Event ("Unknown").
  * @param d Date of the event.
  * @param f Showing what time in the day the Event is available. Either LUNCH or AFTERNOON
  * @param available bool value saying an event is available everyday
  */
  Item(double value, std::string it, int qt, bool owned);

  /**
  * Destructor of Item.
  */
  virtual ~Item() {}

  /**
  * @return The name of the item.
  */
  std::string getItemName();

  /**
  * @return The name of the item.
  */
  double getItemValue();

  int getItemQuantity();

  bool isOwned();

  std::string getOwnership();

  void setItemName(std::string it);

  void setItemValue(double cost);

  void setItemQuantity(int cap);
  void addQuantity();

  void setOwner(bool own);


  virtual void printItemInfo() = 0;

 private:
  /**
  * Value of The Item.
  */
  double itemValue;
  /**
  * Value of The Item.
  */
  int itemQuantity;

  /**
  * Name of The Event.
  */
  std::string itemName;

  bool bought = false;

  const int MAX_QUANTITY = 20;
};

#endif // ITEM_H_INCLUDED
