#include <stdio.h>

int main() {
    int N = 0;
	
	// Ввод последовательности
	printf("Введите длину последовательности:\n");
	scanf(" %d",&N);
	
    int a[N];

    printf("Введите последовательность:\n");
    for (int i = 0; i < N;i++) {
		scanf("%d", &a[i]);
	}

	// Основной код
    printf("(a):");
    for (size_t i = 0; i < N;i++) { // a
        int num = 0;
        for (size_t j = 0;j < N;j++)
            if (a[i] == a[j])
                num++;
        if (num == 1)
            printf("%d ",a[i]);
    }

    printf("\n==============\n");

    int kek = 1;
    for (int i = 1;i < N;i++) {
        if ((a[0] ^ a[i]) != 0)
            kek++;
    }
    
    printf("(в):%d ",kek);
}