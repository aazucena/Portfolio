#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "Warehouse.h"

class Order
{
    public:
        Order(const std::string p, const unsigned int q):product{p}, quantity{q}{filled = false;}
        virtual ~Order(){}
        void fill(Warehouse* w);
        bool isFilled();

    private:
        const std::string product;
        const unsigned int quantity;
        bool filled;
};

#endif // ORDER_H
