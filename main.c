#include <stdio.h>
#include <string.h>
//#include <locale.h>
#include <limits.h>
#include <float.h>

#define UCHAR_MIN 0

int main() {

   char str[20]="";
   
   gets (str);
   printf ("Считана строка:\n%s\n",str);
   printf ("==========================\n");
   
   if (strcmp("unsigned char",str) == 0) {
		printf("Байт: 1\n");
		printf("Целочисленный тип\n");
		printf("Штатный размер\n");
		printf("Беззнаковый\n");
		printf("Минимальная граница %d\n", UCHAR_MIN);
		printf("Минимальная граница %d\n", UCHAR_MAX);
   }
   
   if (strcmp("long double",str) == 0) {
		printf("Байт: 16\n");
		printf("Вещественный тип\n");
		printf("Длиный размер\n");
		printf("Беззнаковый\n");
		printf("Минимальная величина %Lg\n", LDBL_MIN);
		printf("Максимальная величина %Lg\n", LDBL_MAX);
		printf("Количество значащих цифр %d\n", LDBL_DIG);
		printf("Минимальная погрешность %Lg\n", LDBL_EPSILON);
	}
	
   if (strcmp("int",str) == 0) || strcmp("short int",str) == 0 || strcmp("signed short",str) == 0 || strcmp("signed short int",str) == 0) {
		printf("Байт: 4\n");
		printf("Целочисленный тип\n");
		printf("Штатный размер\n");  // Доделать
		printf("Беззнаковый\n");
		printf("Минимальная граница %d\n", INT_MIN);
		printf("Минимальная граница %d\n", INT_MAX);
	}  
	
   if (strcmp("float",str) == 0) {
		printf("Байт: 4\n");
		printf("Вещественный тип\n");
		printf("Штатный размер\n");
		printf("Беззнаковый\n");
		printf("Минимальная величина %g\n", FLT_MIN);
		printf("Максимальная величина %g\n", FLT_MAX);
		printf("Количество значащих цифр %d\n", FLT_DIG);
		printf("Минимальная погрешность %g\n", FLT_EPSILON);
	}
	
   if (strcmp("double",str) == 0) {
		printf("Байт: 4\n");
		printf("Вещественный тип\n");
		printf("Длиный размер\n");
		printf("Беззнаковый\n");
		printf("Минимальная величина %g\n", DBL_MIN);
		printf("Максимальная величина %g\n", DBL_MAX);
		printf("Количество значащих цифр %d\n", DBL_DIG);
		printf("Минимальная погрешность %g\n", DBL_EPSILON);
	}  
	 
    if (strcmp(str, "char") == 0) {
		printf("Байт: %d \n", CHAR_BIT / 8);
		printf("Целочисленный тип\n");
		printf("Штатный размер\n");
		printf("Беззнаковый\n");
		printf("Минимальная величина %d\n", CHAR_MIN);
		printf("Максимальная величина %d\n", CHAR_MAX);
	}  
	
	if ((strcmp("short", str) == 0) || (strcmp("short int", str) == 0) || (strcmp("signed short", str) == 0) || (strcmp("signet short int", str) == 0))  {
		printf("Байт: 2\n");
		printf("Целочисленный тип \n");
		printf("Короткий размер \n");
		printf("Нижняя граница: SHRT_MIN = %d \n", SHRT_MIN);
		printf("Верхняя граница: SHRT_MAX = %d \n", SHRT_MAX);
	}

	if (strcmp("unsigned short", str) == 0 || strcmp("unsigned short int", str) == 0) {
		printf("Байт: 2");
		printf("Целочисленный тип \n");
		printf("Короткий размер \n");
		printf("Беззнаковый \n");
		printf("Нижняя граница: USHRT_MIN = %d \n", 0);
		printf("Верхняя граница: USHRT_MAX = %d \n", USHRT_MAX);
	}
	else
		printf("Error\n");
	
	
	
	printf ("==========================\n");
	return 0;
}

