#include <iostream>
#include <cassert>
#include "Point.hpp"
#include "Face.hpp"

int main() {
    // Create three points
    double coords1[] = {1.0, 2.0, 3.0};
    auto point1 = std::make_shared<Point<3>>(Point<3>(coords1));
    double coords2[] = {4.0, 5.0, 6.0};
    auto point2 = std::make_shared<Point<3>>(Point<3>(coords2));
    double coords3[] = {7.0, 8.0, 9.0};
    auto point3 = std::make_shared<Point<3>>(Point<3>(coords3));
    std::cout << "Created points" << std::endl;

    // Create a face
    Face<3> face(point1, point2, point3);
    Face<3> face2(face);
    Face<3> face3 = face;
    std::cout << "Created face" << std::endl;

    // Test the getters
    assert(face.First == point1);
    assert(face.Second == point2);
    assert(face.Third == point3);
    std::cout << "Tested getters" << std::endl;

    // Test the setters
    double coords4[] = {0.0, 0.0, 0.0};
    auto newPoint1 = std::make_shared<Point<3>>(Point<3>(coords4));
    double coords5[] = {3.0, 0.0, 0.0};
    auto newPoint2 = std::make_shared<Point<3>>(Point<3>(coords5));
    double coords6[] = {0.0, 4.0, 0.0};
    auto newPoint3 = std::make_shared<Point<3>>(Point<3>(coords6));
    face.SetFirst(newPoint1);
    face.SetSecond(newPoint2);
    face.SetThird(newPoint3);
    assert(face.First == newPoint1);
    assert(face.Second == newPoint2);
    assert(face.Third == newPoint3);
    std::cout << "Tested setters" << std::endl;

    // Test the GetArea() function
    double expectedArea = 6.0;
    assert(face.GetArea() == expectedArea);
    std::cout << "Tested GetArea" << std::endl;

    // Test the ToString() function
    std::string expectedString = "Face [ [ 0 0 0 ] [ 3 0 0 ] [ 0 4 0 ] ]";
    assert(face.ToString() == expectedString);
    std::cout << "Tested ToString" << std::endl;

    std::cout << "All tests passed!" << std::endl;

    return 0;
}