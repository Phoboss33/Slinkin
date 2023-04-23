#include <stdio.h>
#include <math.h>

int main()
{   
    char mas[8];
    int sum = 0;

    for (unsigned char i = 0; i < 8; i++) {
        printf("Введите %d элемент = ", i + 1);
        scanf("%d", &mas[i]);
    }

    
    for (unsigned char i = 0; i < 8; i++) {
        mas[i] = ((int)mas[i] >= 48) && ((int)mas[i] <= 57);
        //sum = sum + (mas[i] * pow(2, 7 - i));
    }

    printf("sum = %d", sum);

    return 0;
}