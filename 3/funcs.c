#include "logs.c"
#include "string.h"

int testbitF(unsigned long long A, int B) {
    strcpy(lastcall, "testbitF");
    if (B >= 0 && B <= 63) {
        return ((A >> B) & 1);
    }
    return -1;
}

int maxF(int A, int B, int C) {
    strcpy(lastcall, "maxF");
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
	
}

int squarenumF(int A, int B, int C) {
    strcpy(lastcall, "squarenumF");
    return (((B) * (B) - 4 * (A) * (C)) >= 0 ? ((B) * (B) - 4 * (A) * (C) == 0 ? 1 : 2) : 0);
}
