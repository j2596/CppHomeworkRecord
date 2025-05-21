#include <iostream>
using namespace std;

class Mammal {
public:
    Mammal() {
        cout << "Mammal constructor called" << endl;
    }

    ~Mammal() {
        cout << "Mammal destructor called" << endl;
    }
};

class Dog : public Mammal {
public:
    Dog() {
        cout << "Dog constructor called" << endl;
    }

    ~Dog() {
        cout << "Dog destructor called" << endl;
    }
};

int main() {
    cout << "Creating a Dog object" << endl;
    Dog myDog;
    cout << "Dog object created" << endl << endl;
    return 0;
}