#include "logs.c"
#include <string.h>

#define testbitM(A, B) ((B) >= 0 && (B) <= 63 ? (((A) >> (B)) & 1 ) : -1); \
        strcpy(lastcall, "testbitM");

#define maxM(A, B, C) ((A) > (B) ? (A) > (C) ? (A) : (C) : ((B) > (C)) ? (B) : (C)); \
        strcpy(lastcall, "maxM");

#define squarenumM(A, B, C) (((B) * (B) - 4 * (A) * (C)) >= 0 ? ((B) * (B) - 4 * (A) * (C) == 0 ? 1 : 2) : 0); \
        strcpy(lastcall, "squarenumM"); 
        