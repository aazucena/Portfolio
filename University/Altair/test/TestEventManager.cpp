#include <iostream>
#include <vector>
#include <string>
#include "Choice.h"
#include "Event.h"
#include "EventManager.h"
#include "gtest/gtest.h"

TEST(TestEventManager, addEventTest) {
    EventManager e;
    Event em;
    Event em1;
    Event em2;

    e.addEvent(em);
    e.addEvent(em1);
    e.addEvent(em2);

    std::vector<Event> events = e.getEvents();

    EXPECT_EQ(22, events.size());
}

TEST(TestEventManager, getEventsTest) {
    EventManager e;
    Event em("Event 1");
    Event em1("Event 2");
    Event em2("Event 3");

    e.addEvent(em);
    e.addEvent(em1);
    e.addEvent(em2);

    Event eR = e.getEvent(em2);

    EXPECT_EQ("Event 3", eR.getEventName());
}

TEST(TestEventManager, currentDayTest) {
    EventManager e;
    int day = e.getCurrentDay();

    EXPECT_EQ(1, day);

    e.nextDay();
    day = e.getCurrentDay();

    EXPECT_EQ(2, day);
}
