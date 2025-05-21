#include <iostream>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date() {}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void set()
	{
		cin >> year >> month >> day;
	}
	void show()
	{
		cout << year << '/' << month << '/' << day;
	}
};

class People
{
private:
	unsigned long number;
	char sex;
	Date birthday;
	unsigned long id;

public:
	//带缺默认形参值的成员函数
	People(unsigned long n = 0, char s = 'm', Date bd = Date(2000,1,1), unsigned long i = 1234) {
		number = n;
		sex = s;
		birthday = bd;
		id = i;
	}

	//析构函数
	~People() {
		cout << "goodbye!" << endl << endl;
	}

	//复制构造函数
	People(const People& p){
		number = p.number;
		sex = p.sex;
		birthday = p.birthday;
		id = p.id;
	}

	//内联成员函数
	void set()
	{
		cout << "请输入编号: ";
		cin >> number;
		cout << "请输入性别(m/f): ";
		cin >> sex;
		cout << "请输入生日: ";
		birthday.set();
		cout << "请输入身份证号: ";
		cin >> id;
	}

	void show() {
		cout << "number:" << number << endl;

		cout << "sex:";
		if (sex == 'm') cout << "male" << endl;
		else if (sex == 'f') cout << "female" << endl;
		else cout << "error" << endl;

		cout << "birthday:";
		birthday.show();
		cout << endl << "id:" << id << endl;
	}
};

int main()
{
	{
		// 使用带默认值的构造函数创建对象
		People p1;
		cout << "默认信息：" << endl;
		p1.show();
		cout << endl;
	}//使用析构函数

	// 手动录入
	People p2;
	p2.set();
	cout << endl << "录入后的人员信息：" << endl;
	p2.show();
	cout << endl;

	// 测试复制构造函数
	People p3(p2);
	cout << endl << "复制p2生成p3后的信息：" << endl;
	p3.show();
	cout << endl;

	return 0;
}