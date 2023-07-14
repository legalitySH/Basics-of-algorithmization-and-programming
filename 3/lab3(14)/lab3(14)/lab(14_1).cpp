//#include<fstream>
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main() {
//	setlocale(LC_ALL, "rus");
//	FILE* file1;
//	fopen_s(&file1, "FILE1.txt", "r");
//	if (!file1) {
//		cout << "Ошибка открытия";
//		exit(1);
//	}
//	char input[255];
//	string buff;
//	string* wordArray = new string[256];
//	string* allWords = new string[256];
//	int counter = 0;
//	int counter2 = 0;
//	int counter3 = 0;
//	int flag = 0;
//	bool* bool_array = new bool[5] {false};
//	while (!feof(file1))
//	{
//		wordArray = new string[256];
//		fgets(input, 254, file1);
//		for (int i = 0; i < strlen(input); i++)
//		{
//			if (input[i] != ' ' && input[i] != '\n') {
//				buff += input[i];
//			}
//			else
//			{
//				wordArray[counter] = buff;
//				allWords[counter3] = buff;
//				buff = "";
//				counter++;
//				counter3++;
//			}
//		}
//		for (int i = 0; i < counter; i++)
//		{
//			for (int j = 0; j < counter; j++)
//			{
//				if (j == i) {
//					continue;
//				}
//				//cout << wordArray[i] << " " << wordArray[j] << endl;
//				if (wordArray[i] == wordArray[j]) {
//					flag++;
//					break;
//				}
//			}
//		}
//		delete[] wordArray;
//		if (flag > 0 && counter != 1) {
//			bool_array[counter2] = true;
//			counter2++;
//		}
//		else
//		{
//			bool_array[counter2] = false;
//			counter2++;
//		}
//		flag = 0;
//		counter = 0;
//
//	}
//	fclose(file1);
//	fopen_s(&file1, "FILE1.txt", "r");
//	ofstream file2("FILE2.txt");
//	while (!feof(file1)) {
//		counter++;
//		if (counter >= counter2) {
//			break;
//		}
//		fgets(input, 254, file1);
//		if (bool_array[counter - 1] == true) {
//			file2 << input;
//		}
//	}
//	fclose(file1);
//	file2.close();
//	char CharWord[255];
//	int countOfNumbers = 0;
//	counter = 0;
//	int* countofNumbersArray = new int[10];
//	for (int i = 0; i < counter3-2; i++)
//	{
//		strcpy_s(CharWord, allWords[i].c_str());
//		for (int i = 0; i < strlen(CharWord); i++)
//		{
//			if (CharWord[i] == '1') {
//				countOfNumbers++;
//			}
//
//		}
//		countofNumbersArray[counter] = countOfNumbers;
//		counter++;
//		countOfNumbers = 0;
//	}
//	int max = countofNumbersArray[0];
//	int indexOfMaxNumbers = 0;
//	for (int i = 0; i < counter; i++)
//	{
//		if (max < countofNumbersArray[i]) {
//			max = countofNumbersArray[i];
//			indexOfMaxNumbers = i;
//		}
//	}
//	cout << "Номер слова с наибольшим числом 1 : " << indexOfMaxNumbers+1 << endl;
//}