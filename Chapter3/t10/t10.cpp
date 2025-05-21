#include <iostream>
using namespace std;

//最大公因数
int a(int m, int n)
{
    int min;//找到两个数中最小的数
    if (m < n)
        min = m;
    else
        min = n;

    for (int i = min ; i > 0;i--) //从最小的数字开始递减
    {
        if (m % i == 0 && n % i == 0) //可以被两个数字同时整除
            return i;
    }
}

//最小公倍数
int b(int m, int n)
{
    int max;//找到两个数中最大的数
    if (m < n)
        max = n;
    else
        max = m;

    for (int i = max ; i <= m*n ;i++) //从最大的数字开始递减
    {
        if (i % m == 0 && i % n == 0) //可以被两个数字同时整除
            return i;
    }
}

int main()
{
    //输入两个数
    int x,y;
    cout << "Please input two numbers:" << endl;
    cin >> x >> y;

    int m = a(x, y);//最小公倍数
    int n = b(x, y);//最大公倍数
    cout <<"the greatest common divisor:" << m << endl;
    cout <<"the least common multiple:" << n << endl;
    return 0;
}