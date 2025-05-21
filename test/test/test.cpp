#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // 对齐
#include <algorithm> // for find_if
using namespace std;

// 教师信息结构体设计
struct Teacher {
    string id;            // 教师号
    string name;          // 姓名
    string gender;        // 性别
    string title;         // 职称
    string course;        // 任教课程
    string classes;       // 任教班级
    int theoryHours;      // 理论课时
    int experimentHours;  // 实验课时
    int classCount;       // 班级数目
    double totalHours;    // 教学总课时
};

// 根据班级数计算教学总课时的函数
double calculateTotalHours(int theory, int experiment, int classCount) {
    double factor;
    if (classCount == 2) factor = 1.5;
    else if (classCount == 3) factor = 2.0;
    else factor = 2.5;
    return (theory + experiment) * factor;
}

// 浏览所有教师信息
void displayAll(const vector<Teacher>& teachers) {
    if (teachers.empty()) {
        cout << "没有任何教师信息。\n";
        return;
    }
    cout << "所有教师信息列表：\n";
    cout << left
        << setw(10) << "ID"
        << setw(10) << "姓名"
        << setw(8) << "性别"
        << setw(10) << "职称"
        << setw(10) << "课程"
        << setw(10) << "班级"
        << setw(12) << "理论课时"
        << setw(12) << "实验课时"
        << setw(8) << "班级数"
        << setw(10) << "总课时" << endl;

    for (const auto& t : teachers) {
        cout << left
            << setw(10) << t.id
            << setw(10) << t.name
            << setw(8) << t.gender
            << setw(10) << t.title
            << setw(10) << t.course
            << setw(10) << t.classes
            << setw(12) << t.theoryHours
            << setw(12) << t.experimentHours
            << setw(8) << t.classCount
            << setw(10) << fixed << setprecision(1) << t.totalHours << endl;
    }
}

// 按教师号或姓名查询教师信息
void searchTeacher(const vector<Teacher>& teachers) {
    if (teachers.empty()) {
        cout << "没有任何教师信息。\n";
        return;
    }
    cout << "请输入教师ID或姓名进行查询: ";
    string key;
    cin >> key;
    bool found = false;
    for (const auto& t : teachers) {
        if (t.id == key || t.name == key) {
            cout << "找到教师信息：\n";
            cout << "ID: " << t.id
                << "\n姓名: " << t.name
                << "\n性别: " << t.gender
                << "\n职称: " << t.title
                << "\n课程: " << t.course
                << "\n班级: " << t.classes
                << "\n理论课时: " << t.theoryHours
                << "\n实验课时: " << t.experimentHours
                << "\n班级数: " << t.classCount
                << "\n总课时: " << t.totalHours << "\n";
            found = true;
            // 不break，以便查找同名的其他教师
        }
    }
    if (!found) {
        cout << "未找到相关教师。\n";
    }
}

// 按教师号删除教师信息
void deleteTeacher(vector<Teacher>& teachers) {
    if (teachers.empty()) {
        cout << "没有任何教师信息。\n";
        return;
    }
    cout << "请输入要删除的教师ID: ";
    string id;
    cin >> id;
    auto it = find_if(teachers.begin(), teachers.end(), [&](const Teacher& t) {
        return t.id == id;
        });
    if (it != teachers.end()) {
        teachers.erase(it);
        cout << "删除成功。\n";
    }
    else {
        cout << "未找到该教师ID。\n";
    }
}

// 录入新教师信息
void addTeacher(vector<Teacher>& teachers) {
    Teacher t;
    cout << "录入新教师信息：\n";
    cout << "教师ID: ";
    cin >> t.id;
    // 检查ID是否已存在
    for (const auto& ex : teachers) {
        if (ex.id == t.id) {
            cout << "该ID已存在，无法添加。\n";
            return;
        }
    }
    cout << "姓名: ";
    cin >> t.name;
    cout << "性别: ";
    cin >> t.gender;
    cout << "职称: ";
    cin >> t.title;
    cout << "任教课程: ";
    cin >> t.course;
    cout << "任教班级: ";
    cin >> t.classes;
    cout << "理论课时: ";
    cin >> t.theoryHours;
    cout << "实验课时: ";
    cin >> t.experimentHours;
    cout << "班级数目: ";
    cin >> t.classCount;
    // 计算并赋值教学总课时
    t.totalHours = calculateTotalHours(t.theoryHours, t.experimentHours, t.classCount);
    teachers.push_back(t);
    cout << "添加成功。\n";
}

// 修改指定教师信息（根据ID查找）
void modifyTeacher(vector<Teacher>& teachers) {
    if (teachers.empty()) {
        cout << "没有任何教师信息。\n";
        return;
    }
    cout << "请输入要修改的教师ID: ";
    string id;
    cin >> id;
    auto it = find_if(teachers.begin(), teachers.end(), [&](Teacher& t) {
        return t.id == id;
        });
    if (it == teachers.end()) {
        cout << "未找到该教师ID。\n";
        return;
    }
    // 找到教师，提示修改各字段（输入新值或回车保留原值）
    cout << "修改教师信息（输入新值或直接回车保留原值）：\n";
    cout << "当前姓名: " << it->name << "\n新 姓名: ";
    string input;
    cin.ignore(); // 忽略上一行输入留下的换行符
    getline(cin, input);
    if (!input.empty()) it->name = input;
    cout << "当前性别: " << it->gender << "\n新 性别: ";
    getline(cin, input);
    if (!input.empty()) it->gender = input;
    cout << "当前职称: " << it->title << "\n新 职称: ";
    getline(cin, input);
    if (!input.empty()) it->title = input;
    cout << "当前课程: " << it->course << "\n新 任教课程: ";
    getline(cin, input);
    if (!input.empty()) it->course = input;
    cout << "当前班级: " << it->classes << "\n新 任教班级: ";
    getline(cin, input);
    if (!input.empty()) it->classes = input;
    cout << "当前理论课时: " << it->theoryHours << "\n新 理论课时: ";
    getline(cin, input);
    if (!input.empty()) it->theoryHours = stoi(input);
    cout << "当前实验课时: " << it->experimentHours << "\n新 实验课时: ";
    getline(cin, input);
    if (!input.empty()) it->experimentHours = stoi(input);
    cout << "当前班级数: " << it->classCount << "\n新 班级数目: ";
    getline(cin, input);
    if (!input.empty()) it->classCount = stoi(input);
    // 重新计算教学总课时
    it->totalHours = calculateTotalHours(it->theoryHours, it->experimentHours, it->classCount);
    cout << "修改完成。\n";
}

int main() {
    vector<Teacher> teachers;
    int choice;
    do {
        cout << "\n--- 高校教职工工作量管理系统 ---\n";
        cout << "1. 浏览所有教师信息\n";
        cout << "2. 查询教师信息\n";
        cout << "3. 删除教师信息\n";
        cout << "4. 录入新教师信息\n";
        cout << "5. 修改教师信息\n";
        cout << "0. 退出系统\n";
        cout << "请选择功能编号: ";
        cin >> choice;
        switch (choice) {
        case 1:
            displayAll(teachers);
            break;
        case 2:
            searchTeacher(teachers);
            break;
        case 3:
            deleteTeacher(teachers);
            break;
        case 4:
            addTeacher(teachers);
            break;
        case 5:
            modifyTeacher(teachers);
            break;
        case 0:
            cout << "退出系统。\n";
            break;
        default:
            cout << "无效选择，请重新输入。\n";
        }
    } while (choice != 0);

    return 0;
}
