#include <iostream>
using namespace std;

class cat
{
private:
    static int howmanycats;

public:
    cat()//创建时+1
    {
        howmanycats++;
    }

    ~cat()//销毁时-1
    {
        howmanycats--;
    }

    static int gethowmany()
    {
        return howmanycats;
    }
};

int cat::howmanycats = 0;

int main()
{
    cat c1, c2; //创建两个
    cout << "Number of cats: " << cat::gethowmany() << endl;

    {
        cat c3;//创建一个
        cout << "Number of cats: " << cat::gethowmany() << endl;
    }//c3销毁

    cout << "Number of cats: " << cat::gethowmany() << endl;

    return 0;
}