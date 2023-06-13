#include <stdio.h>
#include <float.h>
#include <math.h>

#define squareM(A, B, C, NUM, X1, X2) { \
    float D; \
    D = B * B - 4 * A * C; \
    if (fabs(D * D) < FLT_EPSILON) { \
        NUM = 1; \
        X1 = -B / (2 * A); \
        X2 = X1; \
    } \
    else if(D > 0) { \
        NUM = 2; \
        X1 = (-B + sqrt(D)) / (2 * A); \
        X2 = (-B - sqrt(D)) / (2 * A); \
    } \
    else { \
        NUM = 0; \
    } \
}

int main() {
    float a = 2, b = 15, c = -15;
    int num;
    float x1, x2;
    
    squareM(a, b, c, num, x1, x2);
    
    printf("корней: %d\n", num);
    if(num == 2) {
        printf("X1: %f\n", x1);
        printf("X2: %f\n", x2);
    }
    else if(num == 1) {
        printf("X1: %f\n", x1);
    }
    else {
        printf("корней нет\n");
    }
    
    return 0;
}
