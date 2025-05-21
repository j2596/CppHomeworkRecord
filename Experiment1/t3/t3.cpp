#include <iostream>
using namespace std;

int aIf(int score) {    //用if
    if (score >= 90) return 5;
    else if (score >= 80) return 4;
    else if (score >= 60) return 3;
    else return 2;
}

int aSwitch(int score) {    //用switch
    switch (score / 10) {
    case 10:
    case 9: return 5;
    case 8: return 4;
    case 7:
    case 6: return 3;
    default: return 2;
    }
}

int main() {
    int a;
    cin >> a;

    cout << "use if:" << aIf(a) << endl;
    cout << "use switch:" << aSwitch(a) << endl;

    return 0;
}