//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<cstdlib>
//#include<string>
//
//int main() {
//	FILE* file1;
//	fopen_s(&file1, "file1.txt", "w");
//	for (int i = 0; i < 5; i++)
//	{
//			fprintf(file1, "%d\n", rand() % 25 + 20);
//
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		fprintf(file1, "%d\n", rand() % 50 - 100);
//	}
//	fclose(file1);
//	fopen_s(&file1, "file1.txt", "r");
//	FILE* file2;
//	fopen_s(&file2, "file2.txt", "w");
//	char tmp[4];
//	int value = 0;
//	while (!feof(file1))
//	{
//		fgets(tmp,4,file1);
//		value = std::atoi(tmp);
//		if(value!=0)
//		fprintf(file2, "%d\n", abs(value));
//	}
//	fclose(file1);
//	fopen_s(&file1, "file1.txt", "r");
//	while (!feof(file1))
//	{
//		fgets(tmp, 4, file1);
//		value = std::atoi(tmp);
//		if (value != 0) {
//			if (value > 0){
//				fprintf(file2, "%d\n", abs(value)*(-1));
//			}
//			else
//			{
//				fprintf(file2, "%d\n", value);
//			}
//		}
//
//	}
//}