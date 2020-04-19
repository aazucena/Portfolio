#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Choice.h"
#include "Event.h"
#include "gtest/gtest.h"

TEST(TestEvent, constructorEventTest) {
  Date d("month", 1);
  Event e("Event 1", d, Event::freeTimeType::AFTERNOON);

  EXPECT_EQ("Event 1", e.getEventName());

  Date dR = e.getDate();
  EXPECT_EQ("month", dR.getMonth());
  EXPECT_EQ(1, dR.getDay());

  EXPECT_EQ(Event::freeTimeType::AFTERNOON, e.getWhenAvailable());
}


