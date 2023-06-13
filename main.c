#include <stdio.h>

#define testbitM(A, B) ((B) >= 0 && (B) <= 63 ? (((A) >> (B)) & 1) : -1)

#define maxM(A, B, C) ((A) > (B) ? (A) > (C) ? (A) : (C) : ((B) > (C)) ? (B) : (C))

#define squarenumM(A, B, C) (((B) * (B) - 4 * (A) * (C)) >= 0 ? ((B) * (B) - 4 * (A) * (C) == 0 ? 1 : 2) : 0) 

#define simpleM(A, result) { \
    int flag = 1; \
    for(int i = 2; i <= (A) / 2; i++) { \
        if((A) % i == 0) { \
            flag = 0; \
            break; \
        } \
    } \
    if(flag == 1) { \
        result = 1; \
    } \
    else { \
        result = 0; \
    } \
}



int main() {
    unsigned long long num = 0b1000001100011111; // 33567
    //printf("%d\n", num);

    printf("1.1) %lld\n",testbitM(num, 15));

    printf("1.2) %d\n", maxM(5,2+10,9));

    printf("1.3) %d\n", squarenumM(1,5-5,-4));
	
	
	//
    int flag = 12;
    int result;
    simpleM(flag, result);
    printf("2.1) %d\n", result); 
}
