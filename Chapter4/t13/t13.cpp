#include <iostream>
#define PI 3.14

using namespace std;

class Circle
{
public:
    Circle(double a)
    {
        r = a;
    }

    double GetArea()
    {
        return PI * r * r;
    }

private:
    double r;
};


int main()
{
    double a;
    cout << "radius is:";
    cin >> a;

    Circle area(a);
    cout << "area is:" << area.GetArea() << endl;
}