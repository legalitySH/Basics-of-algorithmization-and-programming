//#include<iostream>
//#include<fstream>
//#include<Windows.h>
//
//using namespace std;
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	FILE* fout; errno_t err;
//	err = fopen_s(&fout, "FILE1.txt", "r");
//	if (err != NULL) {
//		exit(1);
//	}
//	char tmp[255];
//	string str;
//	ofstream fin("FILE2.txt");
//	while (!feof(fout))
//	{
//		fgets(tmp, 255, fout);
//		for (int i = 0; i < strlen(tmp); i++)
//		{
//			str += tmp[i];
//			if (tmp[i] == ' ') {
//				str = "";
//				break;
//			}
//		}
//		fin << str;
//		str = "";
//
//	}
//	fclose(fout);
//	fin.close();
//
//	ifstream file("FILE2.txt");
//	while (!file.eof()) {
//		file >> str;
//		if (str.length() == 5) {
//			cout << str << endl;
//		}
//
//	}
//
//}