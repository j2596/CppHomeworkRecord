#include <iostream>
using namespace std;

class Rectangle
{
public:
    Rectangle(double a, double b)
    {
        length = a;
        width = b;
    }

    double s()
    {
        return length * width;
    }

private:
    double length, width;

};


int main()
{
    double a, b;
    cout << "length and width are:";
    cin >> a >> b;

    Rectangle area(a, b);
    cout << "area is:"<<area.s()<<endl;
}