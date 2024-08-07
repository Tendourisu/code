#include "Date.hpp"
#include <cassert>
#include <iostream>

void testDate() {
    // Test constructor
    Date date1(2022, 10, 15);
    assert(date1.year == 2022);
    assert(date1.month == 10);
    assert(date1.day == 15);

    // Test copy constructor
    Date date2(date1);
    assert(date2.year == 2022);
    assert(date2.month  == 10);
    assert(date2.day == 15);

    // Test assignment operator
    Date date3 = date1;
    assert(date3.year == 2022);
    assert(date3.month  == 10);
    assert(date3.day  == 15);

    // Test Set method
    date1.Set(2023, 12, 31);
    assert(date1.year == 2023);
    assert(date1.month  == 12);
    assert(date1.day  == 31);

    // Test IsLeapYear method
    assert(Date::IsLeapYear(2020));
    assert(!Date::IsLeapYear(2021));

    // Test DaysFrom19000101 method

    assert(date1.DaysFrom19000101() == 45289);

    // Test DayBetween method
    Date date4(2022, 1, 1);
    std::cout << date1.DayBetween(date4) << std::endl;
    assert(date1.DayBetween(date4) == 729);

    // Test IsSame method
    assert(!date1.IsSame(date4));

    // Test IsLaterThan method
    assert(date1.IsLaterThan(date4));

    // Test IsEarlierThan method
    assert(date4.IsEarlierThan(date1));

    // Test IsValid method
    assert(Date::IsValid(2022, 2, 30) == false);
    assert(Date::IsValid(2022, 2, 28) == true);

    // Test comparison operators
    assert(date1 == date3);
    assert(date1 > date4);
    assert(date4 < date1);
    assert(date1 != date4);
    assert(date1 >= date3);
    assert(date4 <= date1);
}

int main() {
    testDate();
    return 0;
}