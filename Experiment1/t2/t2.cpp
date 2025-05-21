#include<iostream>
using namespace std;

float exchange(float& x, float& y, float& z) {
    float a;
    a = y;
    y = x;
    x = z;
    z = a;
    return 0;
}

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    exchange(a, b, c);
    cout << a << " " << b << " " << c << " " << endl;
    return 0;
}