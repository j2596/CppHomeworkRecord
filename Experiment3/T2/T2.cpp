#include <iostream>
#define PI 3.14
using namespace std;

class CPoint {
protected:
    double x, y;

public:
    CPoint(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    void setPoint(double x_val, double y_val) {
        x = x_val;
        y = y_val;
    }

    void showPoint() const {
        cout << "(" << x << ", " << y << ")";
    }

    double getX() const { return x; }
    double getY() const { return y; }
};

class CLine : public CPoint {
protected:
    CPoint endPoint;

public:
    CLine(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0)
        : CPoint(x1, y1), endPoint(x2, y2) {}

    void setLine(double x1, double y1, double x2, double y2) {
        x = x1;
        y = y1;
        endPoint.setPoint(x2, y2);
    }

    double length() const {
        return sqrt(pow(endPoint.getX() - x, 2) + pow(endPoint.getY() - y, 2));
    }

    double slope() const {
        double dx = endPoint.getX() - x;
        double dy = endPoint.getY() - y;
        if (dx == 0) {
            throw runtime_error("Slope is undefined (vertical line).");
        }
        return dy / dx;
    }

    void showLine() const {
        cout << "Line starts at ";
        showPoint();
        cout << " and ends at ";
        endPoint.showPoint();
        cout << endl;
        cout << "Length: " << length() << endl;
        try {
            cout << "Slope: " << slope() << endl;
        }
        catch (const runtime_error& e) {
            cout << "Slope: " << e.what() << endl;
        }
    }
};

class CCircle : public CPoint {
private:
    double radius;

public:
    CCircle(double x_val = 0, double y_val = 0, double r = 0) : CPoint(x_val, y_val), radius(r) {}

    void setCircle(double x_val, double y_val, double r) {
        setPoint(x_val, y_val);
        radius = r;
    }

    double area() const {
        return PI * radius * radius;
    }

    void showCircle() const {
        cout << "Circle center at ";
        showPoint();
        cout << ", radius: " << radius << endl;
        cout << "Area: " << area() << endl;
    }
};

int main() {
    // 测试 CLine
    CLine line(1, 2, 4, 6);
    line.showLine();
    cout << endl;

    // 测试 CCircle
    CCircle circle(0, 0, 5);
    circle.showCircle();

    return 0;
}
