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
    vector<int> grades; // оценки по пяти предметам

    // перегрузка оператора "<" для сортировки по курсу и алфавиту
    bool operator<(const Student& other) const {
        if (course != other.course) {
            return course < other.course;
        }
        return surname < other.surname;
    }
};


int main() {
    
    setlocale(LC_ALL, "rus");
    // создание списка студентов
    vector<Student> students = {
        {"Угляница", "Михаил", "Владимирович", 2005, 3, 1, {4, 5, 3, 4, 5}},
        {"Костюченко", "Владислав", "Фёдорович", 2004, 2, 2, {3, 4, 4, 5, 4}},
        {"Шимко", "Алексей", "Александрович", 1899, 4, 1, {5, 5, 5, 5, 5}},
        {"Какой-то", "слабак", "из 2 группы", 2002, 2, 2, {5, 4, 5, 3, 5}},
        {"Буйко", "Максим ", "Алексеевич",2004, 3, 1, {4, 4, 4, 4, 5}},
        {"Топчик", "второй", "группы(слабак)", 2000, 5, 2, {5, 5, 5, 5, 5}},
        {"Шип", "Егор", "Клава-кокавич", 2001, 4, 1, {4, 4, 4, 4, 4}},
        {"Белодед", "Николай", "Иванович", 666, 2, 2, {3, 3, 4, 5, 4}}
    };

    // сортировка списка студентов по курсу и алфавиту
    sort(students.begin(), students.end());

    // вывод отсортированного списка студентов
    cout << "Отсортированный список студентов:\n";
    for (const auto& student : students) {
        cout << student.surname << " " << student.name << endl;
        cout << " " << student.patronymic << ", " << student.birthYear << ", курс " << student.course
            << ", группа " << student.groupNumber << ", оценки: ";
        for (const auto& grade : student.grades) {
            cout << grade << " ";
        }
        cout << endl;
    }

    // расчет среднего балла каждой группы по каждому предмету
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
        cout << "Средние оценки по предметам для группы " << i + 1 << ":\n";
        for (int j = 0; j < numSubjects; j++) {
            auto key = make_pair(i + 1, j);
            double avgGrade = (groupSubjectStats[key].second > 0) ?
                groupSubjectStats[key].first / groupSubjectStats[key].second : 0;
            cout << "Предмет " << j + 1 << ": " << avgGrade << endl;
        }
    }

    // поиск самого старшего и самого младшего студентов
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
    cout << "Самый старший студент: " << oldestStudent.surname << " " << oldestStudent.name
        << " " << oldestStudent.patronymic << ", год рождения: " << oldestStudent.birthYear << endl;
    cout << "Самый младший студент: " << youngestStudent.surname << " " << youngestStudent.name
        << " " << youngestStudent.patronymic << ", год рождения: " << youngestStudent.birthYear << endl;

    // поиск лучшего студента для каждой группы
    vector<Student> bestStudents(numGroups);
    for (const auto& student : students) {
        int groupIndex = student.groupNumber - 1;
        if (student.grades > bestStudents[groupIndex].grades) {
            bestStudents[groupIndex] = student;
        }
    }
    for (int i = 0; i < numGroups; i++) {
        cout << "Лучший студент в группе " << i + 1 << ": " << bestStudents[i].surname << " "
            << bestStudents[i].name << " " << bestStudents[i].patronymic << ", оценки: ";
        for (const auto& grade : bestStudents[i].grades) {
            cout << grade << " ";
        }
        cout << endl;
    }

    return 0;
}