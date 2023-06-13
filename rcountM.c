#include <stdio.h>
#include <string.h>

#define rcountM(A,Result)\
    int counts = 0;\
    for (int i = 0; i < strlen(A); i++) {\
        if ((A[i] & 0xC0) == 0xC0) {\
            counts++;\
            i++;\
        }\
    }\
    Result = counts; 

int main() {
    char str[] = "Привет мирfа";
    int count;
    rcountM(str, count);
    printf("Букв: %d\n", count);
    return 0;
} 