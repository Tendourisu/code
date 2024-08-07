#include <cassert>
#include "CoffeeMaker.hpp"

int main() {
    // Test case 1: Creating a CoffeeMaker object with initial coffee powder and water
    CoffeeMaker coffeeMaker1(5, 10);
    assert(coffeeMaker1.IsCoffeePowderFull == false);
    assert(coffeeMaker1.IsWaterFull == false);

    // Test case 2: Copy constructor
    CoffeeMaker coffeeMaker2(coffeeMaker1);
    assert(coffeeMaker2.IsCoffeePowderFull == false);
    assert(coffeeMaker2.IsWaterFull == false);

    // Test case 3: Assignment operator
    CoffeeMaker coffeeMaker3 = coffeeMaker1;
    assert(coffeeMaker3.IsCoffeePowderFull == false);
    assert(coffeeMaker3.IsWaterFull == false);

    // Test case 4: Adding coffee powder
    coffeeMaker1.AddCoffeePowder(3);
    assert(coffeeMaker1.IsCoffeePowderFull == false);
    assert(coffeeMaker1.CoffeePowder == 8);

    // Test case 5: Adding water
    coffeeMaker1.AddWater(5);
    assert(coffeeMaker1.IsWaterFull == false);
    assert(coffeeMaker1.Water == 15);

    // Test case 6: Making coffee
    bool result = coffeeMaker1.Make();
    assert(result == true);
    assert(coffeeMaker1.Water == 14);
    assert(coffeeMaker1.CoffeePowder == 7);

    return 0;
}