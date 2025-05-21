#include <iostream>
#include <string>
using namespace std;

const int MAX = 100; // 教师数量上限

class Teacher {
public:
    string id;
    string name;
    string gender;
    string title;
    string course;
    string className;
    int theoryHours;
    int experimentHours;
    int classCount;
    int totalHours;

    void calculateTotalHours() {
        totalHours = classCount * (theoryHours + experimentHours); //计算总课时=班级数*（理论课时+实验课时）
    }

    void display() {
        cout << "--------------------------------------------\n";
        cout << "ID: " << id
            << "\n姓名: " << name
            << "\n性别: " << gender
            << "\n职称: " << title
            << "\n课程: " << course
            << "\n班级: " << className
            << "\n理论课时: " << theoryHours
            << "\n实验课时: " << experimentHours
            << "\n班级数: " << classCount
            << "\n总课时: " << totalHours
            << endl;
    }
};

class TeacherManager {
private:
    Teacher teachers[MAX];
    int count;

public:
    TeacherManager() {
        count = 0;
    }

    void addTeacher() {
        if (count >= MAX) {
            cout << "教师人数已满，无法添加。\n";
            return;
        }

        Teacher t;
        cout << "请输入教师ID：";
        cin >> t.id;
        for (int i = 0; i < count; i++) {
            if (teachers[i].id == t.id) {
                cout << "该教师ID已存在！\n";
                return;
            }
        }

        cout << "姓名：";
        cin >> t.name;
        cout << "性别：";
        cin >> t.gender;
        cout << "职称：";
        cin >> t.title;
        cout << "课程：";
        cin >> t.course;
        cout << "班级名称：";
        cin >> t.className;
        cout << "理论课时：";
        cin >> t.theoryHours;
        cout << "实验课时：";
        cin >> t.experimentHours;
        cout << "班级数目：";
        cin >> t.classCount;

        t.calculateTotalHours();
        teachers[count++] = t;

        cout << "教师添加成功！\n";
    }

    void displayAll() {
        if (count == 0) {
            cout << "当前无教师数据。\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            teachers[i].display();
        }
    }

    void searchTeacher() {
        if (count == 0) {
            cout << "无数据可查。\n";
            return;
        }

        int choice;
        cout << "1. 按ID查找\n2. 按姓名查找\n请输入选项：";
        cin >> choice;

        string keyword;
        bool found = false;
        if (choice == 1) {
            cout << "请输入教师ID：";
            cin >> keyword;
            for (int i = 0; i < count; i++) {
                if (teachers[i].id == keyword) {
                    teachers[i].display();
                    found = true;
                }
            }
        }
        else if (choice == 2) {
            cout << "请输入教师姓名：";
            cin >> keyword;
            for (int i = 0; i < count; i++) {
                if (teachers[i].name == keyword) {
                    teachers[i].display();
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "未找到该教师。\n";
        }
    }

    void deleteTeacher() {
        if (count == 0) {
            cout << "无数据可删。\n";
            return;
        }

        string id;
        cout << "请输入要删除的教师ID：";
        cin >> id;

        int index = -1;
        for (int i = 0; i < count; i++) {
            if (teachers[i].id == id) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "未找到该教师。\n";
            return;
        }

        for (int i = index; i < count - 1; i++) {
            teachers[i] = teachers[i + 1];
        }
        count--;
        cout << "删除成功。\n";
    }

    void modifyTeacher() {
        if (count == 0) {
            cout << "无数据可改。\n";
            return;
        }

        string id;
        cout << "请输入要修改的教师ID：";
        cin >> id;

        int index = -1;
        for (int i = 0; i < count; i++) {
            if (teachers[i].id == id) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "未找到该教师。\n";
            return;
        }

        string newId;
        string newName;
        string newGender;
        string newTitle;
        string newCourse;
        string newClassName;
        string judgment;
        char c1, c2;

        Teacher& t = teachers[index];

        cout << "输入新的姓名（当前：" << t.name << "）。或输入“/” 跳过: ";
        cin >> newName;
        if (newName != "/") {
            t.name = newName;
        }

        cout << "输入新的性别（当前：" << t.gender << "）。或输入“/” 跳过: ";
        cin >> newGender;
        if (newGender != "/") {
            t.gender = newGender;
        }

        cout << "输入新的职称（当前：" << t.title << "）。或输入“/” 跳过: ";
        cin >> newTitle;
        if (newTitle != "/") {
            t.title = newTitle;
        }

        cout << "输入新的课程（当前：" << t.course << "）。或输入“/” 跳过: ";
        cin >> newCourse;
        if (newCourse != "/") {
            t.course = newCourse;
        }

        cout << "输入新的班级名称（当前：" << t.className << "）。或输入“/” 跳过: ";
        cin >> newClassName;
        if (newClassName != "/") {
            t.className = newClassName;
        }

        cout << "输入新的理论课时（当前：" << t.theoryHours << "）。或输入“/” 跳过: "; //这里的输入可能出现‘/’,不能被int直接接收，需要特殊处理。下同
        cin >> c1;
        if (c1 != '/') {
            if (cin.peek() == '\n') {   //判断一位输入还是两位输入
                t.theoryHours = c1 - '0';   //转换为int
            }
            else {
                cin >> c2;
                t.theoryHours = 10 * (c1 - '0') + c2 - '0';
            }
        }

        cout << "输入新的实验课时（当前：" << t.experimentHours << "）。或输入“/” 跳过: ";
        cin >> c1;
        if (c1 != '/') {
            if (cin.peek() == '\n') {
                t.experimentHours = c1 - '0';
            }
            else {
                cin >> c2;
                t.experimentHours = 10 * (c1 - '0') + (c2 - '0');
            }
        }

        cout << "输入新的班级数目（当前：" << t.classCount << "）。或输入“/” 跳过: ";
        cin >> c1;
        if (c1 != '/') {
            if (cin.peek() == '\n') {
                t.classCount = c1 - '0';
            }
            else {
                cin >> c2;
                t.classCount = 10 * (c1 - '0') + (c2 - '0');
            }
        }

        t.calculateTotalHours();
        cout << "修改成功！\n";
    }
};

// 主函数：控制台菜单
int main() {
    TeacherManager manager;
    int choice;

    do {
        cout << "\n=== 高校教职工工作量管理系统 ===\n";
        cout << "1. 添加教师\n";
        cout << "2. 浏览所有教师\n";
        cout << "3. 查询教师\n";
        cout << "4. 删除教师\n";
        cout << "5. 修改教师\n";
        cout << "0. 退出系统\n";
        cout << "请选择操作：";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: manager.addTeacher(); break;
        case 2: manager.displayAll(); break;
        case 3: manager.searchTeacher(); break;
        case 4: manager.deleteTeacher(); break;
        case 5: manager.modifyTeacher(); break;
        case 0: cout << "退出系统。\n"; break;
        default: cout << "无效选项，请重试。\n"; break;
        }
    } while (choice != 0);

    return 0;
}
