#include <iostream>
using namespace std;

class Shape {
public:
    virtual double GetArea() = 0;
    virtual double GetPerim() = 0;
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double GetArea() override {
        return width * height;
    }
    double GetPerim() override {
        return 2 * (width + height);
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double GetArea() override {
        return 3.14 * radius * radius;
    }
    double GetPerim() override {
        return 2 * 3.14 * radius;
    }
};

int main() {
    Shape* s1 = new Rectangle(3, 4);
    Shape* s2 = new Circle(5);

    cout << "Rectangle Area: " << s1->GetArea() << ", Perimeter: " << s1->GetPerim() << endl;
    cout << "Circle Area: " << s2->GetArea() << ", Perimeter: " << s2->GetPerim() << endl;
    return 0;
}
