#include "Inheritance.hpp"
//Shape

//Circle
Circle::Circle(double _radius) : Shape() {
        if (_radius < 0) radius = 0;
        else radius = _radius;
}
Circle& Circle::operator=(const Circle &source) {
    if (this == &source) return *this;
    Shape::operator=(source);
    radius = source.radius;
    return *this;
}

double Circle::GetArea() const {
    const double pi = 3.14159; 
    return pi * radius * radius;
}
double Circle::GetRadius() const { return radius; }
void Circle::SetRadius(double r) {radius = r >= 0 ? r : 0;}
//Rectangle
Rectangle::Rectangle(double _x, double _y) : Shape() {
    if (_x >= 0) x = _x;
    else x = 0;
    if (_y >= 0) y = _y;
    else y = 0; 
}
Rectangle& Rectangle::operator=(const Rectangle &source) {
    if (this == &source) return *this;
    Shape::operator=(source);
    x = source.x;
    y = source.y;
    return *this;
}
double Rectangle::GetArea() const {
    return x * y;
}
double Rectangle::GetLength() const { return x; }
double Rectangle::GetWidth() const { return y; }
void Rectangle::SetLength(double length) {x = length >= 0 ? length : 0;}
void Rectangle::SetWidth(double width) {y = width >= 0 ? width : 0;}
//Square
Square::Square(double _x, double _y) : Rectangle(_x, _x) {}
Square& Square::operator=(const Square &source) {
    if (this == &source) return *this;
    Rectangle::operator=(source);
    return *this;
}
double Square::GetArea() const {
    return GetSide() * GetSide();
}
double Square::GetSide() const { return Rectangle::GetLength(); }
void Square::SetSide(double side) {SetLength(side >= 0 ? side : 0);SetWidth(side >= 0 ? side : 0);}