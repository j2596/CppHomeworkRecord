#include <iostream>
using namespace std;

int main()
{
    //输入摄氏度
    double x;
    cout << "Please input a Centigrade:";
    cin >> x;

    //用公式计算华氏度并输出
    cout << "Fahrenheit:"<<(x*9/5+32)<<endl;
        
    return 0;
}