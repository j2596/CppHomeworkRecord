#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point& operator++() {
        ++x; ++y;
        return *this;
    }

    Point& operator--() {
        --x; --y;
        return *this;
    }

    void show() {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int a, b;
    cin >> a >> b;

    Point p(a, b);
    ++p;
    p.show();
    --p;
    p.show();
    return 0;
}
