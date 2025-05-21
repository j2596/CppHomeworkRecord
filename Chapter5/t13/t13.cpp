#include <iostream>
#include "t13.h"

using namespace std;

int main() 
{
    X x;
    Y y;
    Z z;

    x.show();
    y.g(&x);     // 加1
    x.show();
    z.f(&x);     // 加5
    x.show();
    h(&x);       // 加10
    x.show();

    return 0;
}