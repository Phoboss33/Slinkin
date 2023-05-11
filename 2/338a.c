#include <stdio.h>

int main()
{
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
    
	printf("Пересечение двух последовательностей: ");
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++) {
			if (a[i] == b[j])
				printf("%d ", a[i]);
		}
    

    return 0;
}
