#ifndef ITEMINVENTORY_H_INCLUDED
#define ITEMINVENTORY_H_INCLUDED
#include "Item.h"
#include "Character.h"
#include <locale>
#include <vector>

class ItemInventory {
 public:
  /**
  * Constructor of Item Inventory.
  */
  ItemInventory() {}

  /**
  * Destructor of Item Inventory.
  */
  virtual ~ItemInventory() {}

  /**
  * @return The items in the Event Manager.
  */
  std::vector<Item*> getItems();

  /**
  * Add an Item to the Inventory
  * @param it the item to add
  * @exception event_operation_failed_error Thrown if \a evis a duplicate of existing event
  */
  void addItem(Item* it);

  void buyItem(double money, Item *it); // no selling

  /**
  * Delete an Item from the Inventory
  * @param it the item to delete
  * @exception event_operation_failed_error Thrown if \a evis a duplicate of existing event
  */
  void useItem(Item *it);

  static ItemInventory* getInstance() {
    if (instance == nullptr) {
      instance = new ItemInventory();
    }

    return instance;
  }

 private:
  /**
  * Set of items in the game.
  */
  std::vector<Item*> items;
  static ItemInventory* instance;
};

#endif // ITEMINVENTORY_H_INCLUDED
