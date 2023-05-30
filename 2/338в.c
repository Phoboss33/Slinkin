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
    
    
    for (int i = 0; i < M; i++) { 
        int found = 0; 
        for (int j = 0; j < N; j++) { 
            if (b[i] == a[j]) { 	// b != a => printf....break;
                found = 1; 
                break; 
            }
        }
        if (found == 0) { 
            printf("%d ", b[i]); 
        }
    }
    
    return 0;
}
