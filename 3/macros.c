#include "logs.c"
#include <string.h>

#define testbitM(A, B) (strcpy(lastcall, "testbitM"), ((B) >= 0 && (B) <= 63 ? (((A) >> (B)) & 1 ) : -1))

#define maxM(A, B, C) (strcpy(lastcall, "maxM"), ((A) > (B) ? (A) > (C) ? (A) : (C) : ((B) > (C)) ? (B) : (C)))

#define squarenumM(A, B, C) (strcpy(lastcall, "squarenumM"), (((B) * (B) - 4 * (A) * (C)) >= 0 ? ((B) * (B) - 4 * (A) * (C) == 0 ? 1 : 2) : 0))
        