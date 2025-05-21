#include <iostream>
using namespace std;

class Car;

class Boat {
private:
    int weight;
public:
    Boat(int w) 
    {
        weight = w;
    }
    friend int totalWeight(Boat b, Car c);
};

class Car {
private:
    int weight;
public:
    Car(int w)
    {
        weight = w;
    }
    friend int totalWeight(Boat b, Car c);
};

int totalWeight(Boat b, Car c)
{
    return b.weight + c.weight;

}

int main() 
{
    int a, b;
    cout << "Enter weight of boat and car: ";
    cin>>a>>b;
    Boat boat(a);
    Car car(b);

    cout << "Total weight: " << totalWeight(boat, car) << endl;

    return 0;
}
