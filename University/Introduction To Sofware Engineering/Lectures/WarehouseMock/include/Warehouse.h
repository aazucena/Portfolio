#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <map>

#include <iostream>
using namespace std;

class Warehouse
{
public:
    Warehouse() {}

    virtual ~Warehouse() {}

    virtual void add(const std::string product, unsigned int quantity);

    virtual void remove(const std::string product, unsigned int quantity);

    virtual unsigned int getInventory(const std::string product);

private:
    std::map<const std::string, unsigned int> inventory;
};

#endif // WAREHOUSE_H
