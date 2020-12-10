#ifndef ORDERMOCKTEST_H_INCLUDED
#define ORDERMOCKTEST_H_INCLUDED

#include "gmock/gmock.h"
#include "Warehouse.h"

using namespace ::testing;

class MockWarehouse : public Warehouse
{
public:
    explicit MockWarehouse() {}
    virtual ~MockWarehouse() {}

    MOCK_METHOD2(add, void(const std::string product, unsigned int quantity));
    MOCK_METHOD2(remove, void(const std::string product, unsigned int quantity));
    MOCK_METHOD1(getInventory, unsigned int(const std::string product));

};

TEST (OrderMockTest, orderIsFilled)
{
    const std::string PRODUCT = "Milk";
    const int QUANTITY = 50;

    MockWarehouse warehouse;

    // Expect that getInventory() will be called only once
    // with argument "Milk".
    // Return a value of 50
    Expectation e = EXPECT_CALL(warehouse, getInventory("Milk"))
    .Times(1)
    .WillOnce(Return(50));

    // Expect that remove() will be called only once (ignore arguments)
    // after calling getInventory
    EXPECT_CALL(warehouse, remove(_,_))
    .Times(1)
    .After(e)
    .WillOnce(Return());



    Order* order = new Order(PRODUCT, QUANTITY);
    order->fill(&warehouse);
    EXPECT_TRUE(order->isFilled());
}

TEST (OrderMockTest, orderNotEnough)
{
    MockWarehouse warehouse;

    // Expect that getInventory() will be called (ignore argument)
    // Return a value of 50
    EXPECT_CALL(warehouse, getInventory(_))
    .Times(1)
    .WillOnce(Return(50));

    Order* order = new Order("Milk", 51);
    order->fill(&warehouse);
    EXPECT_FALSE(order->isFilled());
}

#endif // ORDERMOCKTEST_H_INCLUDED
