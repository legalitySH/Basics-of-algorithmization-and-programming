//#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>
//
//
//int main() {
//    FILE* file;
//    fopen_s(&file,"lab14.txt", "r");
//    char** str = (char**)malloc(sizeof(char*));
//    int n = 0;
//    while (!feof(file))
//    {
//        str[n] = (char*)malloc(sizeof(char) * 256);
//        fgets(str[n], 255, file);
//        n++;
//        str = (char**)realloc(str, sizeof(char*) * (n + 1));
//    }
//    printf("%s", str[4]);
//    printf("%s", str[5]);
//    printf("%s", str[6]);
//    int k = 0;
//    printf("\n k = ");
//    scanf_s("%d", &k);
//    switch (k)
//    {
//    case 1: {
//        printf("%s", str[1]);
//        break;
//    }
//    case 2: {
//        printf("%s", str[2]);
//        break;
//    }
//    case 3: {
//        printf("%s", str[3]);
//        break;
//    }
//    default:
//        return 0;
//        break;
//    }
//    fclose(file);
//    FILE* dfile;
//    fopen_s(&dfile, "file.txt", "w");
//    fputs(str[k], dfile);
//    fclose(dfile);
//
//}