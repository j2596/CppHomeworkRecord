#include <iostream>
using namespace std;

class Object {
protected:
    double weight;
public:
    Object(double w) : weight(w) {
        cout << "Object created, weight: " << weight << endl;
    }
    ~Object() {
        cout << "Object destroyed, weight: " << weight << endl;
    }
};

class Box : public Object {
private:
    double height, width;
public:
    Box(double w, double h, double wi) : Object(w), height(h), width(wi) {
        cout << "Box created, height: " << height << ", width: " << width << endl;
    }
    ~Box() {
        cout << "Box destroyed, height: " << height << ", width: " << width << endl;
    }
};

int main() {
    double w, h, wi;
    cout << "Enter weight: ";
    cin >> w;
    cout << "Enter height: ";
    cin >> h;
    cout << "Enter width: ";
    cin >> wi;

    Box myBox(w, h, wi);
    cout << "\nBox object created successfully!\n";
    return 0;
}