//Скопировать из файла FILE1 в файл FILE2 все строки, в которых содержится два одинаковых слова.
//Определить номер слова, в котором больше всего букв «а».
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	ifstream ifile;
	char* str = new char[0];
	ifile.open(str);
	if (ifile.fail()) {
		cout << "Ошибка открытия файла";
		exit(1);
	}
	ifile >> str;
	fprintf(stdout, "%s", str);
	ifile.close();

}