#include "logs.c"
#include "string.h"
#include "funcs.h"

int testbitM(unsigned long long A, int B) {
    if (B >= 0 && B <= 63) {
        return ((A >> B) & 1);
    }
    strcpy(lastcall, "testbitM");
    return -1;
}

int maxM(int A, int B, int C) {
    if (A > B) {
        if (A > C) {
            return A;
        } else {
            return C;
        }
    } else {
        if (B > C) {
            return B;
        } else {
            return C;
        }
    }
    strcpy(lastcall, "maxM");
}

int squarenumM(int A, int B, int C) {
    strcpy(lastcall, "squarenumM");
    return (((B)*(B)-4*(A)*(C))>=0 ? ((B)*(B)-4*(A)*(C)==0 ? 1 : 2) : 0);
}
