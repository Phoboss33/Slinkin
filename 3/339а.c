#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 0;
  
    // Ввод последовательности
    printf("Введите длину последовательности:\n");
    scanf("%d", &N);
  
    int a[N];

    printf("Введите последовательность:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int new = 0;

    // Основной код
    printf("(a):");
    for (int i = 0; i < N; i++) { // a
        int num = 0;
        for (int j = 0; j < N; j++)
            if (a[i] == a[j]) {
                num++;
                new = num;
            }
        if (num == 1)
            printf("%d ", a[i]);
    }

    printf("\n==============\n");

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-i-1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    int num = 0;
    for (int i = 0;i < N;i++)
        if (a[i] != a[i + 1])
            num++;

    printf("\nРазличных чисел: %d",num);

    return 0;
}