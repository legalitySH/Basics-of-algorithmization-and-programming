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
//     printf("Ошибка открытия файла fileB.txt\n");
//     return 1;
//   }
//   else if (fileA == NULL)
//   {
//     printf("Ошибка открытия файла fileA.txt\n");
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
//     printf("Файл fileB.txt создан\n");
//     fclose(fileB);
//     fclose(fileA);
//     return 0;
//   }
//}