#include <stdio.h>

int main()
{   
    char mas[8];
    int sum = 0;

    for (int i = 0; i < 8; i++) {
        printf("Write %d element = ", i + 1);
        scanf(" %c", &mas[i]);  // fgets(mas, 9, stdin);
    }

    
    for (int i = 0; i < 8; i++) {
        mas[i] = ((int)mas[i] >= 48) && ((int)mas[i] <= 57);

        //printf("%d", mas[i]);
        
        sum += (mas[i] << (7 - i));
    }

    printf("sum = %d\n", sum);

    return 0;
}