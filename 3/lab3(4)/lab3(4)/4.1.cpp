
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("FILE1.txt");
	ofstream fout("FILE2.txt");
	string s;
	int count = 0;
	while (getline(fin, s))
	{
		bool flag = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			fout << s << endl;
			if (s[0] == 'А' || s[0] == 'A')
			{
				count++;
			}
		}
	}
	cout << "Количество строк, которые начинаются на букву «А» в файле FILE2: " << count << endl;
	fin.close();
	fout.close();
	return 0;
}


