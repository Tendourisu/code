#include <iostream>
#include "Time.hpp"

int main() {
    Time myTime = Time(2,3,3);
    std::cout << myTime.ToString() << std::endl;
    return 0;
}