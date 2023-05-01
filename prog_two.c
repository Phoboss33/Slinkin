#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void func(short N, short len) {
    short mas[len];

    printf("print number: \n");

    for (int i = 0;i < len;i++) {
        scanf("%hd",&N);
        mas[i] = N;
    }

    for (int i = 0;i < len;i++) {
        printf("mas[%d]:= %hd\n",i,mas[i]);
    }
    if (mas[0] < mas[1]) {      // mas[len-1]
        printf("является\n"); 
    }
    else {
        printf("err\n"); 
    }
}

int main() {
    short N = 0, len = 0;

    printf("input number N > 1, [one: len, two: your number]\n");
    scanf("%hd",&len);
    printf("len:= %hd\n",len);

    func(N,len);
}