#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    void settime(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    void print_time() {
        cout << "Time: " << hour << ":" << minute << ":"<< second << endl;
    }

    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    ~Time() {
        cout << "goodbye!" << endl;
    }

    Time(const Time& t) {
        hour = t.hour;
        minute = t.minute;
        second = t.second;
    }
};

int main() {
    {
        //a.用settime设置时间为9点20分30秒并显示该时间
        Time t1;
        t1.settime(9, 20, 30);
        t1.print_time();
    }//析构函数中输出“goodbye!”

    {
        // b. 使用构造函数设置时间为10点40分50秒，并显示该时间
        Time t2(10, 40, 50);
        t2.print_time();
    }//析构函数中输出“goodbye!”

    //构造函数不带参数,使小时、分、秒均为0
    Time t3;
    t3.print_time();

    //复制构造函数
    Time t4 = t3;
    t4.print_time();

    return 0;
}
