#include <iostream>
using namespace std;

int main()
{
    //输入一个数
    int x;
    cout << "Please input a number:" << endl;
    cin >> x; 
    
    //1,2为质数
    if(x<3)
    {
        cout << "it is prime1" << endl; 
        return 0;
    }

    //能被大于2的数整除的不是质数
    for (int i = 2 ; i < x ; i++)
    {

        if (x % i == 0)
        {
            cout << "it is not prime" << endl;
            return 0;
        }

    }

    //其余为质数
    cout << "it is prime" << endl;

    return 0;
}