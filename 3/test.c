#include <stdio.h>
#include "macros.c"
#include "funcs.h"
#include "logs.c"



int main() {
    int num = 10;
    int bit = 2;
    int a = 5;
    int b = 7;
    int c = 9;
    int result;

    result = testbitM(num, bit);
    printf("lastcall: %s\n", lastcall);

    result = testbitF(num, bit);
    printf("lastcall: %s\n", lastcall);

    result = maxM(a, b, c);
    printf("lastcall: %s\n", lastcall);

    result = maxF(a, b, c);
    printf("lastcall: %s\n", lastcall);

    result = squarenumM(a, b, c);
    printf("lastcall: %s\n", lastcall);

    result = squarenumF(a, b, c);
    printf("lastcall: %s\n", lastcall);

    return 0;
}