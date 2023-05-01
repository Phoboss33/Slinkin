#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

short signedChar(signed char x) {
    short i = 0;
    while (x < SCHAR_MAX) {
        x++;
        i++;
    }
    return i;
}  

short unsignedChar(unsigned char x) {
    short i = 0;
    while (x < UCHAR_MAX) {
        x++;
        i++;
    }
    return i;
}  

int main() {
    //unsigned char x;
    signed char x;
    //x = SCHAR_MIN;
    x = -128;

    printf("%d", signedChar(x));
    //printf("%d", unsignedChar(x));
}