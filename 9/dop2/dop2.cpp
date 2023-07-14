#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct Student {
    string surname;
    string name;
    string patronymic;
    int birthYear;
    int course;
    int groupNumber;
    vector<int> grades; // ������ �� ���� ���������

    // ���������� ��������� "<" ��� ���������� �� ����� � ��������
    bool operator<(const Student& other) const {
        if (course != other.course) {
            return course < other.course;
        }
        return surname < other.surname;
    }
};


int main() {
    
    setlocale(LC_ALL, "rus");
    // �������� ������ ���������
    vector<Student> students = {
        {"��������", "������", "������������", 2005, 3, 1, {4, 5, 3, 4, 5}},
        {"����������", "���������", "Ը�������", 2004, 2, 2, {3, 4, 4, 5, 4}},
        {"�����", "�������", "�������������", 1899, 4, 1, {5, 5, 5, 5, 5}},
        {"�����-��", "������", "�� 2 ������", 2002, 2, 2, {5, 4, 5, 3, 5}},
        {"�����", "������ ", "����������",2004, 3, 1, {4, 4, 4, 4, 5}},
        {"������", "������", "������(������)", 2000, 5, 2, {5, 5, 5, 5, 5}},
        {"���", "����", "�����-�������", 2001, 4, 1, {4, 4, 4, 4, 4}},
        {"�������", "�������", "��������", 666, 2, 2, {3, 3, 4, 5, 4}}
    };

    // ���������� ������ ��������� �� ����� � ��������
    sort(students.begin(), students.end());

    // ����� ���������������� ������ ���������
    cout << "��������������� ������ ���������:\n";
    for (const auto& student : students) {
        cout << student.surname << " " << student.name << endl;
        cout << " " << student.patronymic << ", " << student.birthYear << ", ���� " << student.course
            << ", ������ " << student.groupNumber << ", ������: ";
        for (const auto& grade : student.grades) {
            cout << grade << " ";
        }
        cout << endl;
    }

    // ������ �������� ����� ������ ������ �� ������� ��������
    const int numGroups = 2;
    const int numSubjects = 5;
    map<pair<int, int>, pair<double, int>> groupSubjectStats;
    for (const auto& student : students) {
        int groupNumber = student.groupNumber;
        for (int i = 0; i < numSubjects; i++) {
            groupSubjectStats[{groupNumber, i}] = {
                groupSubjectStats[{groupNumber, i}].first + student.grades[i],
                groupSubjectStats[{groupNumber, i}].second + 1
            };
        }
    }
    for (int i = 0; i < numGroups; i++) {
        cout << "������� ������ �� ��������� ��� ������ " << i + 1 << ":\n";
        for (int j = 0; j < numSubjects; j++) {
            auto key = make_pair(i + 1, j);
            double avgGrade = (groupSubjectStats[key].second > 0) ?
                groupSubjectStats[key].first / groupSubjectStats[key].second : 0;
            cout << "������� " << j + 1 << ": " << avgGrade << endl;
        }
    }

    // ����� ������ �������� � ������ �������� ���������
    Student oldestStudent = students.front();
    Student youngestStudent = students.front();
    for (const auto& student : students) {
        if (student.birthYear < oldestStudent.birthYear) {
            oldestStudent = student;
        }
        if (student.birthYear > youngestStudent.birthYear) {
            youngestStudent = student;
        }
    }
    cout << "����� ������� �������: " << oldestStudent.surname << " " << oldestStudent.name
        << " " << oldestStudent.patronymic << ", ��� ��������: " << oldestStudent.birthYear << endl;
    cout << "����� ������� �������: " << youngestStudent.surname << " " << youngestStudent.name
        << " " << youngestStudent.patronymic << ", ��� ��������: " << youngestStudent.birthYear << endl;

    // ����� ������� �������� ��� ������ ������
    vector<Student> bestStudents(numGroups);
    for (const auto& student : students) {
        int groupIndex = student.groupNumber - 1;
        if (student.grades > bestStudents[groupIndex].grades) {
            bestStudents[groupIndex] = student;
        }
    }
    for (int i = 0; i < numGroups; i++) {
        cout << "������ ������� � ������ " << i + 1 << ": " << bestStudents[i].surname << " "
            << bestStudents[i].name << " " << bestStudents[i].patronymic << ", ������: ";
        for (const auto& grade : bestStudents[i].grades) {
            cout << grade << " ";
        }
        cout << endl;
    }

    return 0;
}