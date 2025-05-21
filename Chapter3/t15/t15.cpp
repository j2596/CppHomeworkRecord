#include <iostream>
using namespace std;

double a(int n,double x)
{
    if (n == 0) //递归到0的时候返回为1
    {
        return 1;
    }
    else
    {
        if (n == 1) //递归到1的时候返回为x
        {
            return x;
        }
        else //n>1时返回结果
        {
                return ((2 * n - 1) * x * a(n - 1, x) - (n - 1) * a(n - 2, x)) / n;
        }
    }
}

int main()
{
    //输入两个数
    int n;
    double x;
    cout << "Please input n and x:" << endl;
    cin >> n>>x;

    double m = a(n,x);
    cout << "the Legendre Polynomial is:" << m << endl;

    return 0;
}