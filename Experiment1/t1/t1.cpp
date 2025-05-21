#include <iostream>
#include <cmath>
using namespace std;

double distance(int x1, int y1, int x2 = 0, int y2 = 0) {
    int a = pow(x1 - x2, 2);
    int b = pow(y1 - y2, 2);
    return sqrt(a + b);
}

double distance(double x1, double y1, double x2=0.0, double y2=0.0) {
    double a = pow(x1 - x2, 2);
    double b = pow(y1 - y2, 2);
    return sqrt(a + b);
}

int main() {
    int a, b, c, d;
    double q, w, e, r;

    cout << "输入第一个整数坐标：";
    cin >> a >> b;
    if (cin.peek() == '\n') {  // 如果输入完前两个数字之后按回车则默认到原点的距离
        cout << "距离原点: " << distance(a, b) << endl;
    }
    else if (cin >> c >> d) {  // 尝试读取两个数字
        cout << "两点距离: " << distance(a, b, c, d) << endl;
    }

    cout << "输入第一个浮点坐标：";
    cin >> q >> w;
    if (cin.peek() == '\n') {  // 如果输入完前两个数字之后按回车则默认到原点的距离
        cout << "距离原点: " << distance(q, w) << endl;
    }
    else if (cin >> e >> r) {  // 尝试读取两个数字
        cout << "两点距离: " << distance(q, w, e, r) << endl;
    }
    return 0;
}
