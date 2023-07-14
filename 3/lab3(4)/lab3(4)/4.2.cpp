//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	string s;
//	cout << "Введите строку, состоящую из цифр и слов, разделенных пробелами: ";
//	getline(cin, s);
//	ofstream fout("FILE.txt");
//	fout << s;
//	fout.close();
//	ifstream fin("FILE.txt");
//	int max = 0;
//	while (getline(fin, s))
//	{
//		int count = 0;
//		for (int i = 0; i < s.length(); i++)
//		{
//			if (s[i] != ' ')
//			{
//				count++;
//			}
//			else
//			{
//				if (count > max)
//				{
//					max = count;
//				}
//				count = 0;
//			}
//		}
//		if (count > max)
//		{
//			max = count;
//		}
//	}
//	cout << "Количество символов в самом длинном слове: " << max << endl;
//	fin.close();
//	fin.open("FILE.txt");
//	while (getline(fin, s))
//	{
//		int count = 0;
//		for (int i = 0; i < s.length(); i++)
//		{
//			if (s[i] != ' ')
//			{
//				count++;
//			}
//			else
//			{
//				if (count == max)
//				{
//					for (int j = i - count; j < i; j++)
//					{
//						cout << s[j];
//					}
//					cout << endl;
//				}
//				count = 0;
//			}
//		}
//
//	}
//	fin.close();
//	return 0;
//}
