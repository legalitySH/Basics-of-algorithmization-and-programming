//#include <iostream>
//#include <stdio.h> 
//
//using namespace std;
//  
//int main()
//{
//  setlocale(LC_ALL, "Russian");
//  int a;
//  FILE* fileA, * fileB;
//   fopen_s(&fileA, "fileA4.txt", "r");
//   fopen_s(&fileB, "fileB4.txt", "w");
//   if (fileB == NULL)
//   {
//     printf("������ �������� ����� fileB.txt\n");
//     return 1;
//   }
//   else if (fileA == NULL)
//   {
//     printf("������ �������� ����� fileA.txt\n");
//     return 1;
//   }
//   else {
//     while (!feof(fileA))
//     {
//       fscanf_s(fileA, "%d", &a);
//
//       if (a > 0)
//       {
//           fprintf(fileB, "%d ", a);
//       }
//     }
//     printf("���� fileB.txt ������\n");
//     fclose(fileB);
//     fclose(fileA);
//     return 0;
//   }
//}