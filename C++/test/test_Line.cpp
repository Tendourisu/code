#include <iostream>
#include <cassert>
#include "Point.hpp"
#include "Line.hpp"

int main() {
    // Create two points
    double coords1[] = {1.0, 2.0, 3.0};
    auto point1 = std::make_shared<Point<3>>(Point<3>(coords1));
    double coords2[] = {1.0, 2.0, 4.0};
    auto point2 = std::make_shared<Point<3>>(Point<3>(coords2));
    std::cout << "Created points" << std::endl;

    // Create a line
    std::shared_ptr<Point<3>> points[] = { point1, point2 };
    Line<3> line(points);
    std::cout << "Created line" << std::endl;
    Line<3> line2(point1, point2);

    // Test the getters
    assert(line.First == point1);
    assert(line.Second == point2);
    std::cout << "Tested getters" << std::endl;

    // Test the setters
    double coords3[] = {7.0, 8.0, 9.0};
    auto newPoint1 = std::make_shared<Point<3>>(Point<3>(coords3));
    double coords4[] = {10.0, 11.0, 12.0};
    auto newPoint2 = std::make_shared<Point<3>>(Point<3>(coords4));
    line.SetFirst(newPoint1);
    line.SetSecond(newPoint2);
    assert(line.First == newPoint1);
    assert(line.Second == newPoint2);
    std::cout << "Tested setters" << std::endl;

    // Test the GetLength() function
    double expectedLength = Point<3>::Distance(*newPoint1, *newPoint2);
    assert(line.GetLength() == expectedLength);
    std::cout << "Tested GetLength" << std::endl;

    // Test the ToString() function
    std::string expectedString = "Line [ [ 7 8 9 ] [ 10 11 12 ] ]";
    assert(line.ToString() == expectedString);
    std::cout << "Tested ToString" << std::endl;

    std::cout << "All tests passed!" << std::endl;

    return 0;
}