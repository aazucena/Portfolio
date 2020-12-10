#ifndef ORDERTESTING_H
#define ORDERTESTING_H

#include <gtest/gtest.h>
#include "Warehouse.h"
#include "Order.h"

#include <iostream>

using namespace std;

class OrderStateTest : public ::testing::Test
{
public:
    const string MILK = "2% Milk";
    const string APPLE = "Golden Delicious";

protected:
    void SetUp()
    {
        warehouse.add(MILK, 50);
        warehouse.add(APPLE, 25);
    }

protected:
    Warehouse warehouse;
};

TEST_F (OrderStateTest, orderIsFilled){
    Order* order = new Order(OrderStateTest::MILK, 50);
    order->fill(&warehouse);
    EXPECT_TRUE(order->isFilled());
    EXPECT_EQ(0, warehouse.getInventory(OrderStateTest::MILK));
}

TEST_F (OrderStateTest, orderNotEnough){
    Order* order = new Order(OrderStateTest::MILK, 51);
    order->fill(&warehouse);
    EXPECT_FALSE(order->isFilled());
    EXPECT_EQ(50, warehouse.getInventory(OrderStateTest::MILK));
}

#endif // ORDERTESTING_H
