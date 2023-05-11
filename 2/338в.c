#include <stdio.h>

int main() {
	int N = 0;
	int M = 0;
	
	printf("Введите длину 1 последовательности\n");
	scanf(" %d",&N);
	printf("Введите длину 2 последовательности\n");
	scanf(" %d",&M);
	
    int a[N];
    int b[M];
    
    printf("Введите первую последовательность\n");
    for (int i = 0; i < N;i++) {
		scanf("%d", &a[i]);
	}
    printf("Введите вторую последовательность\n");
    for (int i = 0; i < M;i++) {
		scanf("%d", &b[i]);
	}
    
    
    for (int i = 0; i < M; i++) { // для каждого элемента второй последовательности
        int found = 0; // флаг для проверки, найден ли элемент в первой последовательности
        for (int j = 0; j < N; j++) { // идем по первой последовательности
            if (b[i] == a[j]) { // если элемент нашелся в первой последовательности
                found = 1; // устанавливаем флаг
                break; // выходим из второго цикла
            }
        }
        if (found == 0) { // если элемент не нашелся
            printf("%d ", b[i]); // выводим его на экран
        }
    }
    
    return 0;
}
