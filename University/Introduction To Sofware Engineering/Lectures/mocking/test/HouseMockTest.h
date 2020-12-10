#ifndef HOUSEMOCKTEST_H_INCLUDED
#define HOUSEMOCKTEST_H_INCLUDED

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "House.cpp"

using ::testing::Expectation;
using ::testing::Return;

class MockDoor : public Door {
public:
    explicit MockDoor() {}
    virtual ~MockDoor() {}

    MOCK_METHOD1(lock, void(bool state));
    MOCK_METHOD0(open, std::string());
    MOCK_METHOD0(close, std::string());

    TEST (HouseMockTest, dogOut)
    {
      MockDoor door;

      //door->lock(false);
      Expectation unlock = EXCEPT_CALL(door, lock(false))
      .Times(1);

      //door->open();
      Expectation openDoor

      //dogInHouse = false;
      //door->close();
      //door->lock(true);

      House* house = new House(&door);
      house->dogOut();
      EXPECT_FALSE(house->dogOut())
    }
};
