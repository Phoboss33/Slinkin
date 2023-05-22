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
    
    //int a[] = {1,3,2};
    //int b[] = {2,3,2}; 
    
    printf("Введите первую последовательность\n");
    for (int i = 0; i < N;i++) {
		scanf("%d", &a[i]);
	}
    printf("Введите вторую последовательность\n");
    for (int i = 0; i < M;i++) {
		scanf("%d", &b[i]);
	}

	// Основной код
	int mas[N];
	
	/*for (int i = 0; i < N;i++){
		mas[i] = a[i];
	}
	
	for (int i = N; i < N + M;i++){
		mas[i] = b[i - N];
	}*/
	int LOL = N;
	for (size_t i = 0; i < N;i++) { 
        //int num = 0;
        for (size_t j = 0;j < M;j++) {
			
				if (a[i] == b[j]) {
					if (mas[i-1] == a[i]) {
						LOL -= 1;
						break;
					}
					
					else {
					mas[i] = a[i];
					printf("[%d] [i: %ld] [j: %ld]\n",mas[i], i, j);
					break;
				}
				
			}
	}	
}

	
	//int size = sizeof(mas) / sizeof(mas[0]);
	for (int i = 0; i < LOL;i++){
		if (mas[i])
			printf("%d ", mas[i]);
	}
	
	
	
	
}
