#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter(int c = 0) : count(c) {}

    Counter operator+(int value) {
        return Counter(count + value);
    }

    void show() {
        cout << "Count: " << count << endl;
    }
};

int main() {
    int a, b;
    cin >> a >> b;

    Counter c1(a);
    Counter c2 = c1 + b;
    c2.show();
    return 0;
}