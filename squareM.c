#include <stdio.h>
#include <math.h>

#define squareM(A,B,C,NUM,X1,X2) \
{ \
    float D; \
    D = B*B - 4*A*C; \
    if(D > 0) { \
        NUM = 2; \
        X1 = (-B + sqrt(D)) / (2*A); \
        X2 = (-B - sqrt(D)) / (2*A); \
    } else if(D == 0) { \
        NUM = 1; \
        X1 = -B / (2*A); \
        X2 = X1; \
    } else { \
        NUM = 0; \
    } \
}

int main() {
    float a = 1, b = 2, c = -3;
    int num;
    float x1, x2;
    
    squareM(a, b, c, num, x1, x2);
    
    printf("Number of roots: %d\n", num);
    if(num == 2) {
        printf("First root: %f\n", x1);
        printf("Second root: %f\n", x2);
    } else if(num == 1) {
        printf("Root: %f\n", x1);
    } else {
        printf("No roots\n");
    }
    
    return 0;
}