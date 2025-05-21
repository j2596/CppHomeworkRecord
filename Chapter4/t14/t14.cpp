#include <iostream>
using namespace std;

class Tree
{
public:
    Tree(int a)
    {
        ages = a;
    }

    int grow(int years)
    {
        ages = ages + years;
        return 0;
    }

    int age()
    {
        return ages;
    }
private:
    int ages;
};


int main()
{
    int ages, years;

    cout << "Tree age is："; //初始化树的年龄
    cin >> ages;
    Tree a(ages);

    cout << "Tree grow: ";  //增长年龄
    cin >> years;
    a.grow(years);
    cout << "the age of tree is:" << a.age() << endl;
}