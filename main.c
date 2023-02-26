#include <stdio.h>
#include <string.h>
//#include <locale.h>
#include <limits.h>
#include <float.h>

#define UCHAR_MIN 0

int main() {

   char str[20]="";
   
   gets(str);
   printf ("Считана строка:\n%s\n", str);
   printf ("==========================\n");
   
   if (strcmp("unsigned char",str) == 0) {
		printf("Байт: 1\n");
		printf("Целочисленный тип\n");
		printf("Штатный размер\n");
		printf("Безнаковый\n");
		printf("Минимальная граница UCHAR_MIN: %d\n", UCHAR_MIN);
		printf("Минимальная граница UCHAR_MAX: %d\n", UCHAR_MAX);
   }
   
   else if (strcmp("long double",str) == 0) {
		printf("Байт: 16\n");
		printf("Вещественный тип\n");
		printf("Длиный размер\n");
		printf("Знаковый\n");
		printf("Минимальная величина LDBL_MIN: %Lg\n", LDBL_MIN);
		printf("Максимальная величина LDBL_MAX: %Lg\n", LDBL_MAX);
		printf("Количество значащих цифр LDBL_DIG: %d\n", LDBL_DIG);
		printf("Минимальная погрешность LDBL_EPSILON: %Lg\n", LDBL_EPSILON);
	}
	
	else if (strcmp("int",str) == 0 || strcmp("signed int",str) == 0 || strcmp("signed",str) == 0) {
		printf("Байт: 4\n");
		printf("Целочисленный тип\n");
		printf("Штатный размер\n");  	
		printf("Знаковый\n");
		printf("Минимальная граница %d\n", INT_MIN);
		printf("Минимальная граница %d\n", INT_MAX);
	}  
	
	else if (strcmp("unsigned", str) == 0 || strcmp("unsigned int", str) == 0) {
		printf("Байт: 2\n");
		printf("Целочисленный тип\n");
		printf("Короткий размер\n");
		printf("Беззнаковый\n");
		printf("Нижняя граница %d\n", 0);
		printf("Верхняя граница UINT_MAX: %u\n", UINT_MAX);
	}
	


	
   else if (strcmp("float",str) == 0) {
		printf("Байт: 4\n");
		printf("Вещественный тип\n");
		printf("Штатный размер\n");
		printf("Знаковый\n");
		printf("Минимальная величина FLT_MIN: %g\n", FLT_MIN);
		printf("Максимальная величина FLT_MAX: %g\n", FLT_MAX);
		printf("Количество значащих цифр FLT_DIG: %d\n", FLT_DIG);
		printf("Минимальная погрешность FLT_EPSILON: %g\n", FLT_EPSILON);
	}
	
   else if (strcmp("double",str) == 0) {
		printf("Байт: 8\n");
		printf("Вещественный тип\n");
		printf("Длиный размер\n");
		printf("Знаковый\n");
		printf("Минимальная величина DBL_MIN: %g\n", DBL_MIN);
		printf("Максимальная величина DBL_MAX: %g\n", DBL_MAX);
		printf("Количество значащих цифр DBL_DIG: %d\n", DBL_DIG);
		printf("Минимальная погрешность DBL_EPSILON: %g\n", DBL_EPSILON);
	}  
	 
    else if (strcmp(str, "char") == 0) {
		printf("Байт: %d \n", CHAR_BIT / 8);
		printf("Целочисленный тип\n");
		printf("Штатный размер\n");
		printf("Знаковый\n");
		printf("Нижняя граница CHAR_MIN: %d\n", CHAR_MIN);
		printf("Верзняя граница CHAR_MAX: %d\n", CHAR_MAX);
	}  
	 
    else if (strcmp(str, "signed char") == 0) {
		printf("Байт: %d \n", CHAR_BIT / 8);
		printf("Целочисленный тип\n");
		printf("Штатный размер\n");
		printf("Знаковый\n"); 
		printf("Нижняя граница SCHAR_MIN: %d\n", SCHAR_MIN);
		printf("Верзняя граница SCHAR_MAX: %d\n", SCHAR_MAX);
	}  
	
	else if ((strcmp("short", str) == 0) || (strcmp("short int", str) == 0) || (strcmp("signed short", str) == 0) || (strcmp("signed short int", str) == 0))  {
		printf("Байт: 2\n");
		printf("Целочисленный тип\n");
		printf("Короткий размер\n");
		printf("Знаковый\n");
		printf("Нижняя граница SHRT_MIN: %hi\n", SHRT_MIN);
		printf("Верхняя граница SHRT_MAX: %hi\n", SHRT_MAX);
	}
	
	else if (strcmp("unsigned short", str) == 0 || strcmp("unsigned short int", str) == 0) {
		printf("Байт: 2\n");
		printf("Целочисленный тип\n");
		printf("Короткий размер\n");
		printf("Беззнаковый\n");
		printf("Нижняя граница: %d\n", 0);
		printf("Верхняя граница USHRT_MAX: %d\n", USHRT_MAX);
	}

	else if ((strcmp("long", str) == 0) || (strcmp("long int", str) == 0) ||
		(strcmp("signed long", str) == 0) || (strcmp("signed long int", str) == 0)) {
		printf("Байт: 8");
		printf("Целочисленный тип\n");
		printf("Длинный размер\n");
		printf("Знаковый\n");
		printf("Нижняя граница LONG_MIN: %li\n", LONG_MIN);
		printf("Верхняя граница LONG_MAX: %li\n", LONG_MAX);
	}

	else if ((strcmp("unsigned long", str) == 0) || (strcmp("unsigned long int", str) == 0)) {
		printf("Байт: 8");
		printf("Целочисленный тип\n");
		printf("Длинный размер\n");
		printf("Беззнаковый\n");
		printf("Нижняя граница: %d\n", 0);
		printf("Верхняя граница ULONG_MAX: %lu\n", ULONG_MAX);
	}

	else if ((strcmp("long long", str) == 0) || (strcmp("long long int", str) == 0) ||
		(strcmp("signed long long", str) == 0) || (strcmp("signed long long int", str) == 0)) {
		printf("Байт: 8\n");
		printf("Целочисленный тип\n");
		printf("Знаковый\n");
		printf("Длинный длинный размер\n");
		printf("Нижняя граница LLONG_MIN: %lli\n", LLONG_MIN);
		printf("Верхняя граница LLONG_MAX: %lli\n", LLONG_MAX);
	}

	else if ((strcmp("unsigned long long", str) == 0) || (strcmp("unsigned long long int", str) == 0)) {
		printf("Байт: 8");
		printf("Целочисленный тип\n");
		printf("Длинный длинный размер\n");
		printf("Беззнаковый\n");
		printf("Нижняя граница: %d\n", 0);
		printf("Верхняя граница ULLONG_MAX: %llu\n", ULLONG_MAX);
	}
	else
		printf("Error\n");
	
	
	
	printf ("==========================\n");
	return 0;
}

