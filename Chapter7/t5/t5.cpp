#include <iostream>
#define PI 3.14
using namespace std;

class Shape
{
public:
    virtual double GetArea() = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h)
    {
        width = w;
        height = h;
    }

    double GetArea()
    {
        return width * height;
    }

private:
    double width;
    double height;
};

class Circle : public Shape
{
public:
    Circle(double r)
    {
        radius = r;
    }

    double GetArea()
    {
        return PI * radius * radius;
    }

private:
    double radius;
};

class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side) {}
};

int main()
{
    double w, h;
    cout << "Enter width and height of rectangle: ";
    cin >> w >> h;
    Rectangle rect(w, h);
    cout << "Rectangle Area: " << rect.GetArea() << endl;

    double r;
    cout << "Enter radius of circle: ";
    cin >> r;
    Circle circle(r);
    cout << "Circle Area: " << circle.GetArea() << endl;

    double s;
    cout << "Enter side length of square: ";
    cin >> s;
    Square square(s);
    cout << "Square Area: " << square.GetArea() << endl;

    return 0;
}