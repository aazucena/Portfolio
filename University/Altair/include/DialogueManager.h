#ifndef DIALOGUEMANAGER_H_INCLUDED
#define DIALOGUEMANAGER_H_INCLUDED

#include <vector>
#include "KeyLines.h"

class DialogueManager {
 public:
  /**
  * Constructor of Item Inventory.
  */
  DialogueManager() {}

  /**
  * Destructor of Item Inventory.
  */
  virtual ~DialogueManager() {}

  /**
  * Add an Item to the Inventory
  * @param it the item to add
  * @exception event_operation_failed_error Thrown if \a evis a duplicate of existing event
  */
  std::vector<KeyLines*> getLines();

  /**
  * Add an Item to the Inventory
  * @param it the item to add
  * @exception event_operation_failed_error Thrown if \a evis a duplicate of existing event
  */
  void addLine(KeyLines* kl);

  bool searchLine(KeyLines* kl);

  /**
  * Delete an Item from the Inventory
  * @param it the item to delete
  * @exception event_operation_failed_error Thrown if \a evis a duplicate of existing event
  */
  void delLine(KeyLines* kl);

 private:
  /**
  * Set of items in the game.
  */
  std::vector<KeyLines*> lines;
};

#endif // DIALOGUEMANAGER_H_INCLUDED
