#include <stdio.h>

int isGreater(int x, int y) {
    int diff = y - x;
    int sign = (diff >> 31) & 1;
    int check = !(diff ^ 0);
    return (sign ^ 1) & 1 & !check;
}

int main() {
    int mas[] = {1, 2, 3, 2, 1, 2, 3, 2, 1};
    int res[] = {};
    int sizemas = (sizeof(mas) / sizeof(int)) - 1;

    for (size_t i = 0;i < sizemas;i++) {
        int kek = isGreater(mas[i],mas[i+1]);
        res[i] = kek; 
        printf("%d\n", kek);
        //printf("res = %d\n", res);
    }

    int result[] = {};
    int lol;

    for (int i = 0;i < sizemas;i++) {
        lol += res[i] ^ res[sizemas-1-i];
        printf("res %d re %d\n",res[i], lol);
        
    }

    if (lol == 0 )
        printf("true\n");
    else 
        printf("false\n");
    return 0;
}
