#include "Warehouse.h"

void Warehouse::add(const std::string product, unsigned int quantity)
{
    inventory[product] += quantity;
}

void Warehouse::remove(const std::string product, unsigned int quantity)
{
    if(inventory[product] >= quantity)
    {
        inventory[product] -= quantity;
    }
}

unsigned int Warehouse::getInventory(const std::string product)
{
    unsigned int i = inventory[product];
    return i;

}
