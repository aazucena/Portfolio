#include <string>
#include "Date.h"
#include "Event.h"
#include "EventManager.h"
Date::Date() {}

Date::Date(std::string m, int d) {
    month = m;
    day = d;
}

Date::~Date() {}


std::string Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}
