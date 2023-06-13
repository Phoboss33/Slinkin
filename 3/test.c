#include <stdio.h>
#include "macros.c"
#include "funcs.h"
#include "logs.c"



int main() {
    int num = 10;
    int bit = 3;
    int a = 1;
    int b = 0;
    int c = -4;
    int result;

    result = testbitM(num, bit);
    //result++;
    printf("result = %d\n",result );
    printf("lastcall: %s\n", lastcall);

    result = testbitF(num, bit);
    printf("result = %d\n",result );
    printf("lastcall: %s\n", lastcall);
	
    result = maxM(a, b, c);
    printf("result = %d\n",result );
    printf("lastcall: %s\n", lastcall);

    result = maxF(a, b, c);
    printf("result = %d\n",result );
    printf("lastcall: %s\n", lastcall);

    result = squarenumM(a, b, c);
    printf("result = %d\n",result );
    printf("lastcall: %s\n", lastcall);

    result = squarenumF(a, b, c);
    printf("result = %d\n",result );
    printf("lastcall: %s\n", lastcall);
}
