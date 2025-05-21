#include <iostream>
using namespace std;

class Building {
protected:
    int floors;       // 层数
    int rooms;        // 房间数
    double area;      // 总平方数

public:
    Building(int f = 0, int r = 0, double a = 0.0) : floors(f), rooms(r), area(a) {}

    void setBuilding(int f, int r, double a) {
        floors = f;
        rooms = r;
        area = a;
    }

    void showBuilding() const {
        cout << "Building Info:" << endl;
        cout << "Floors: " << floors << endl;
        cout << "Rooms: " << rooms << endl;
        cout << "Area: " << area << endl;
    }
};

class House : public Building {
private:
    int bedrooms;     // 卧室数
    int bathrooms;    // 浴室数

public:
    House(int f = 0, int r = 0, double a = 0.0, int br = 0, int ba = 0)
        : Building(f, r, a), bedrooms(br), bathrooms(ba) {}

    void setHouse(int f, int r, double a, int br, int ba) {
        setBuilding(f, r, a);
        bedrooms = br;
        bathrooms = ba;
    }

    void showHouse() const {
        showBuilding();
        cout << "Bedrooms: " << bedrooms << endl;
        cout << "Bathrooms: " << bathrooms << endl;
    }
};

class Office : public Building {
private:
    int fireExtinguishers; // 灭火器数量
    int telephones;        // 电话数量

public:
    Office(int f = 0, int r = 0, double a = 0.0, int fe = 0, int tp = 0)
        : Building(f, r, a), fireExtinguishers(fe), telephones(tp) {}

    void setOffice(int f, int r, double a, int fe, int tp) {
        setBuilding(f, r, a);
        fireExtinguishers = fe;
        telephones = tp;
    }

    void showOffice() const {
        showBuilding();
        cout << "Fire Extinguishers: " << fireExtinguishers << endl;
        cout << "Telephones: " << telephones << endl;
    }
};

// 主函数
int main() {
    // 测试 House 类
    House myHouse(2, 6, 120.5, 3, 2);
    myHouse.showHouse();
    cout << endl;

    // 测试 Office 类
    Office myOffice(5, 20, 500.0, 10, 15);
    myOffice.showOffice();

    return 0;
}
