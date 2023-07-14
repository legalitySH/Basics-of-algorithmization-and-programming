#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;

void bubble_sort(int* A, int size)//���������� ���������. ���������� ��������� �� ������ ������� ������� � ��� ������
{
	int* arr = new int[size];// ������������� ������ ������������� �������
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(A + i);
	}
	for (int i = 0; i < size; i++)// size - 1 ����������, ����� �� ����� �� ������, ���������� ��� ������
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);//������� swap() ������ ������� �������� ���� ����������
		}
	}
	cout << "A = ";
	for (int i = 0; i < size; i++)//����� ���������������� �������
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr; // ������������ ������
}

void �ocktail_sort(int* A, int size)//������-����������
{
	int* arr = new int[size];// ������������� ������ ������������� �������
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(A + i);
	}
	bool sort_or_not = true;

	int  right_border, left_border = 0;
	right_border = size - 1;
	do
	{

		//������� ��� ��������, ���� ��������� � ������, ������ - � �����
		 //���� ������������ �� ���������, �� ������ ������ ������������, ������, sort_or_not = true - ���������� do...while �����
		sort_or_not = true;
		for (int i = left_border; i < right_border; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				sort_or_not = false;
			}

		}


		for (int i = right_border; i > left_border; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
				sort_or_not = false;
			}
		}

		++left_border;
		--right_border;


	} while (sort_or_not == false);

	cout << "B = ";
	for (int i = 0; i < size; i++)//����� ���������������� �������
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}

void comb_sort(int* A, int size)//���������� ���������
{
	double factor = 1.2473309;//������ ���������� ����
	int step = size - 1;//��� ����������
	int* arr = new int[size];// ������������� ������ ������������� �������
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(A + i);
	}

	while (step >= 1)
	{

		for (int i = 0; i + step < size; i++)
		{
			if (arr[i] > arr[i + step])
			{

				swap(arr[i], arr[i + step]);
			}
		}
		step /= factor;
	}
	cout << "C = ";
	for (int i = 0; i < size; i++)//����� ���������������� �������
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}

void insertion_sort(int* A, int size)// ���������� ���������
{
	int* arr = new int[size];// ������������� ������ ������������� �������
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(A + i);
	}
	int temp, // ��������� ���������� ��� �������� �������� �������� ������������ �������
		item;// ����������, �������� � ���� ������ ����������� ��������
	for (int i = 1; i < size; i++)
	{
		temp = arr[i]; // �������������� ��������� ���������� ������� ��������� �������� �������
		item = i - 1; // ���������� ������ ����������� �������� �������
		while (item >= 0 && arr[item] > temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
		{
			arr[item + 1] = arr[item]; // ������������ ��������� �������
			arr[item] = temp;
			item--;
		}
	}
	cout << "D = ";
	for (int i = 0; i < size; i++)//����� ���������������� �������
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}



void  selection_sort(int* A, int size)// ���������� �������
{
	int* arr = new int[size];// ������������� ������ ������������� �������
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(A + i);
	}
	for (int i = 0; i < size - 1; i++)// size - 1 ����������, ����� �� ����� �� ������, ���������� ��� ������
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);//������� swap() ������ ������� �������� ���� ����������
		}
	}
	cout << "E = ";
	for (int i = 0; i < size; i++)//����� ���������������� �������
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr; // ������������ ������
}

void q_sort(int* arr, int left, int right)
{
	int i = left,//����� �������
		j = right;// ������ �������
	int pivot = arr[(left + right) / 2]; // ����������� �������

	while (i <= j)
	{
		while (arr[i] < pivot) i++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		while (arr[j] > pivot) j--;// �������� ������ ������� ���� ������� [right] ������ [pivot]

		if (i <= j)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}

			i++; j--;
		}

	};
	 //���������� �������� ���������� ��� ����� � ������ ����� �������
	if (left < j) q_sort(arr, left, j);
	if (i < right) q_sort(arr, i, right);
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL)); // ��� ����, ����� �� �������� ���� � �� �� ������
	int size;
	clock_t time_start, time_end;
	double bubble_time, insertion_time, cocktail_time, comb_time, selection_time, qsort_time;
	cout << "������� ���������� ��������� ������� ";
	cin >> size;
	int* arr = new int[size];// � ��������� ������� �������� �� �����
	cout << "arr = ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 + 1;// ������ �������� �� 1 �� 100
		cout << arr[i] << " ";
	}
	cout << endl;
	time_start = clock();
	bubble_sort(arr, size);
	time_end = clock();
	bubble_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;//���������� ������� ����������

	time_start = clock();
	insertion_sort(arr, size);
	time_end = clock();
	insertion_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;

	time_start = clock();
	�ocktail_sort(arr, size);
	time_end = clock();
	cocktail_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;

	time_start = clock();
	comb_sort(arr, size);
	time_end = clock();
	comb_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;

	time_start = clock();
	selection_sort(arr, size);
	time_end = clock();
	selection_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;

	time_start = clock();
	q_sort(arr, 0, size - 1);
	time_end = clock();
	qsort_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;

	cout << "F = ";
	for (int i = 0; i < size; i++)//����� ���������������� �������
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr; // ������������ ������
	cout << "����� ����������\n������� = " << bubble_time << endl <<
		"������� = " << insertion_time << endl << "������ = " << cocktail_time << endl <<
		"�������� = " << comb_time << endl << "����� = " << selection_time <<
		endl << "������� = " << qsort_time;
}