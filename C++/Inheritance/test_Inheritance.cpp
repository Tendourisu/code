#include <iostream>
#include "Inheritance.hpp"

int main() {
    // Create a Circle object
    Circle circle(5);
    std::cout << "Circle Area: " << circle.GetArea() << std::endl;
    std::cout << "Circle Radius: " << circle.GetRadius() << std::endl;

    // Create a Rectangle object
    Rectangle rectangle(4, 6);
    std::cout << "Rectangle Area: " << rectangle.GetArea() << std::endl;
    std::cout << "Rectangle Length: " << rectangle.GetLength() << std::endl;
    std::cout << "Rectangle Width: " << rectangle.GetWidth() << std::endl;

    // Create a Square object
    Square square(4, 3);
    std::cout << "Square Area: " << square.GetArea() << std::endl;
    std::cout << "Square Side: " << square.GetSide() << std::endl;

    Square a = square;
    a.SetLength(5);
    std::cout << "Rectangle Area: " << a.GetArea() << std::endl;
    std::cout << "Rectangle Length: " << a.GetLength() << std::endl;
    std::cout << "Rectangle Width: " << a.GetWidth() << std::endl;
    std::cout << "Square Area: " << a.Rectangle::GetArea() << std::endl;

    return 0;
}