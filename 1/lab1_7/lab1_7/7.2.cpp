#include<iostream>
#include<Windows.h>

using namespace std;
void mn(int n,int value,...){
	int* ptr = &value;
	int* num = new int[n];
	for (int i = 0; i < n; i++)
	{
		num[i] = *ptr;
		ptr += 2;
	}
	int min = num[0];
	for (int i = 0; i < n; i++)
	{
		if (min > num[i]) {
			min = num[i];
		}
	}
	cout << "����������� ������� = " << min << endl;
}
void mn(int n, double value, ...) {
	double* ptr = &value;
	double* num = new double[n];
	for (int i = 0; i < n; i++)
	{
		num[i] = *ptr;
		ptr += 2;
	}
	double min = num[0];
	for (int i = 0; i < n; i++)
	{
		if (min > num[i]) {
			min = num[i];
		}
	}
	cout << "����������� ������� = " << min << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	mn(5, 1, 2, 3, 4, 5);
	mn(4,1.2,3.4,-7.5,-2);

	// � ������� ��������� ���� ������� , ��� ���� ��� ������ �� ����� ����� ��������
	// � ������ ������ � ������� ���������� � ������� ����� ��������� ��������� ��� 
	// int , ��� � double ������� � �������� , ��� ����� ���������� , ��� �� ������.
}