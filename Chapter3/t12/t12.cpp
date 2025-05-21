#include <iostream>
using namespace std;

int sum(int m)
{
    if (m == 1) //递归到1的时候返回为1
    {
        return 1;
    }

    return m + sum(m - 1);//递归
}

int main()
{
    //输入一个数
    int x;
    cout << "Please input a number:" << endl;
    cin >> x;

    int a = sum(x);
    cout <<"sum is:" << a <<endl;

    return 0;
}