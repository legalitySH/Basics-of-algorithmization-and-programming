#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string name;
	int exams;
	int* marks;
};

void check(Student* student)
{
	int count = 0;
	for (int i = 0; i < student->exams; i++)
	{
		if (student->marks[i] >= 4 && student->marks[i] <= 10)
		{
			count++;
		}
	}
	if (count == student->exams)
	{
		cout << "��� �������� �����" << endl;
	}
	else
	{
		cout << "�� ��� �������� �����" << endl;
	}
}

void checkAll(Student* students, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		int countMarks = 0;
		for (int j = 0; j < students[i].exams; j++)
		{
			if (students[i].marks[j] >= 4 && students[i].marks[j] <= 10)
			{
				countMarks++;
			}
		}
		if (countMarks == students[i].exams)
		{
			count++;
		}
	}
	cout << "������� ���������, ������� ��� ��������: " << (double)count / size * 100 << "%" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "������� ���������� ��������� ";
	cin >> size;
	Student* students = new Student[size];
	for (int i = 0; i < size; i++)
	{
		cout << "\n������� ��� ��������: ";
		cin >> students[i].name;
		cout << "������� ���������� ���������: ";
		cin >> students[i].exams;
		students[i].marks = new int[students[i].exams];
		for (int j = 0; j < students[i].exams; j++)
		{
			cout << "������� ������: ";
			cin >> students[i].marks[j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << "�������: " << students[i].name << endl;
		check(&students[i]);
	}
	checkAll(students, size);
	for (int i = 0; i < size; i++)
	{
		delete[] students[i].marks;
	}
	delete[] students;
	return 0;
	cin.get();
}