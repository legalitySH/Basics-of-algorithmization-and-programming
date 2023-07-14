#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream fin("FILE1.txt");
	ofstream fout("FILE2.txt");

	if (fin.fail()||fout.fail())
	{
		cout << "Failure..." << endl;
		exit(1);
	}
	else
	{
		cout << "Files are open" << endl;
	}

	string str;
	int i = 1;
	
	while (getline(fin, str))
	{
		if (i % 2 == 0)
		{
			fout << str << '\n';
		}
		i++;
	}

	cout << "Yes ura oaoao" << endl;

	fin.close();
	fout.close();

	ifstream finSize("FILE1.txt");
	ifstream foutSize("FILE2.txt");

	finSize.seekg(0, ios::end);
	long sizeFin = finSize.tellg();
	finSize.seekg(0, ios::beg);

	foutSize.seekg(0, ios::end);
	long sizeFout = foutSize.tellg();
	foutSize.seekg(0, ios::beg);

	cout << "First size=  " << sizeFin << " байт" << endl;
	cout << "Second size=  " << sizeFout << " байт" << endl;

	finSize.close();
	foutSize.close();
}