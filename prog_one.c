#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

short signedChar(signed char x) {
    short i = 0;
    while (x < SCHAR_MAX) {
        x++;
        i++;
    }
    return i + 1;
}  

short unsignedChar(unsigned char x) {
    short i = 0;
    while (x < UCHAR_MAX) {
        x++;
        i++;
        //printf("%d\n",x);
        
    }
    return i + 1;
}  

short decSignedChar(signed char x) {
    short i = 0; 
    while (x > SCHAR_MIN) {
        x--;
        i++;
        //printf("%d\n",x);
    }
    return i + 1;
}  

short decUnsignedChar(unsigned char x) {
    short i = 0;
    while (x > 0) {
        x--;
        i++;
        //printf("%d\n",x);
    }
    return i + 1;
}  

int main() {
    //unsigned char x = 0;
    signed char x = 0;
    scanf("%hhd", &x);

    printf("inc:= %d\n", signedChar(x));
    printf("dec:= %d\n", decSignedChar(x));
    
    //printf("inc:= %d\n", unsignedChar(x));
    //printf("dec:= %d\n", decUnsignedChar(x));

    
}
