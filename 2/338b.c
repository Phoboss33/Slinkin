#include <stdio.h>

int main() {
	int N = 0;
	int M = 0;
	
	// Ввод последовательносте
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

	// Основной код
	int mas[N + M];
	
	for (int i = 0; i < N;i++){
		mas[i] = a[i];
	}
	
	for (int i = N; i < N + M;i++){
		mas[i] = b[i - N];
	}
	
	for (int i = 0; i < N + M;i++){
		printf("%d ", mas[i]);
	}
	
	
}
