#include<iostream>
#include<chrono>

using namespace std;
using namespace chrono;

void cocktailSort(int* arr,int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; // ����� = 2*i + 1
    int r = 2 * i + 2; // ������ = 2*i + 2

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // ���������� ���� (�������������� ������)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // ���� �� ������ ��������� �������� �� ����
    for (int i = n - 1; i >= 0; i--)
    {
        // ���������� ������� ������ � �����
        swap(arr[0], arr[i]);

        // �������� ��������� heapify �� ����������� ����
        heapify(arr, i, 0);
    }
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
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int size;
    cout << "������� ������ ������� = "; cin >> size;

    int* arr_1 = new int[size];
    int* arr_2 = new int[size];
    int* arr_3 = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr_1[i] = rand() % 666;
        arr_2[i] = rand() % 666;
        arr_3[i] = rand() % 666;
    }

    auto startTime = high_resolution_clock::now();
    cocktailSort(arr_1,size);
    auto endTime = high_resolution_clock::now();
    duration<double> duration = endTime - startTime;
    double timeInSeconds = duration.count();
    cout << "Coctail Sort: " << timeInSeconds << " ������." << endl;

    startTime = high_resolution_clock::now();
    heapSort(arr_2, size);
    endTime = high_resolution_clock::now();
    duration = endTime - startTime;
    timeInSeconds = duration.count();
    cout << "Heapify Sort: " << timeInSeconds << " ������." << endl;

    startTime = high_resolution_clock::now();
    q_sort(arr_3,0,size-1);
    endTime = high_resolution_clock::now();
    duration = endTime - startTime;
    timeInSeconds = duration.count();
    cout << "Quickly Sort: " << timeInSeconds << " ������." << endl;



    

}