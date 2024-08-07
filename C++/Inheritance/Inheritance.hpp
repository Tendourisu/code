// Shape类：double类型成员x和y，通过构造函数给定值，GetArea函数返回面积0（直接返回，不进行任何计算）。
// Circle类：继承于Shape，不新增数据成员，构造函数用于设定半径，限定半径≥0，新增半径的Getter和Setter， GetArea函数返回圆面积。
// Rectangle类：继承于Shape，不新增数据成员，构造函数用于设定长宽，限定长宽均≥0，新增长宽的Getter和Setter， GetArea函数返回矩形面积。
// Square类：继承于Rectangle，不新增数据成员，构造函数用于设定边长，限定长宽均≥0，新增边长的Getter和Setter， GetArea函数返回正方形面积。

#ifndef INHERITANCE_HPP
#define INHERITANCE_HPP

class Shape {
public:
    Shape(){};
    Shape(const Shape &source) = default;
    Shape& operator=(const Shape &source) = default;
    virtual ~Shape() = default;
    virtual double GetArea() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double _radius = 0);
    Circle(const Circle &source) = default;
    Circle& operator=(const Circle &source);
    ~Circle() override = default;
    double GetArea() const override;
    double GetRadius() const;
    void SetRadius(double r);
};


class Rectangle : public Shape {
private:
    double x;
    double y;
public:
    Rectangle(double _x = 0, double _y = 0);
    Rectangle(const Rectangle &source)= default;
    Rectangle& operator=(const Rectangle &source);
    ~Rectangle() override = default;
    double GetArea() const override;
    double GetLength() const;
    double GetWidth() const;
    void SetLength(double length);
    void SetWidth(double width);
};

class Square : public Rectangle {
public:
    Square(double _x = 0, double _y = 0);
    Square(const Square &source)= default;
    Square& operator=(const Square &source);
    ~Square() override = default;
    double GetArea() const override;
    double GetSide() const;
    void SetSide(double side);
private:
    using Rectangle::SetLength;
    using Rectangle::SetWidth;
};

#endif // INHERITANCE_HPP