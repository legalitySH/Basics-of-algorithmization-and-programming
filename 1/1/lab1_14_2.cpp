#include <iostream>
using namespace std;

void compress(int n, char* text, ...) {
	setlocale(LC_ALL, "rus");
	char* p = text, * str;
	int* word_len; int counter = 0; int k = 0;
	for (int i = 0; i < n; ++i)
	{
		word_len = new int[10] {};
		str = p;
		while (*p)
		{
			if (*p != ' ') {
				*str++ = *p;
				k++;
			}
			else
			{
				word_len[counter] = k;
				k = 0;
				counter++;
			}
			++p;
		}
		int max = word_len[0];
		for (int i = 0; i < counter; i++)
		{
			if (max < word_len[i]) {
				max = word_len[i];
			}
		}
		cout << "����� ������� ����� � " << i + 1 << " ����������� ������ - " << max << " ��������" << endl;
		delete[] word_len;
		++p;
	}
}

int main() {
	char text_1[] = "Hello world";
	char text_2[] = "Danger master";
	//compress(1, text_1);
	compress(2, text_1, text_2);
}
