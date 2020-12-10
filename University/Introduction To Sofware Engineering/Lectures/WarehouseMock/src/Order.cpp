#include "Order.h"

void Order::fill(Warehouse* w)
{
    if(!filled && w->getInventory(product) >= quantity)
    {
        w->remove(product, quantity);
        filled = true;
    }
}

bool Order::isFilled()
{
    return filled;
}
