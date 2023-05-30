#include <stdio.h>
#include <math.h>

int main() {
    int x = 0;
	int N = 0;
	
	// Ввод Числа
	printf("Введите число x:\n");
	scanf(" %d",&x);

	// Ввод последовательности
	printf("Введите длину последовательности y >= 2:\n");
	scanf(" %d",&N);

    int a[N];

    printf("Введите последовательность y:\n");
    for (int i = 0; i < N;i++) {
		scanf("%d", &a[i]);
	}

	// Основной код

	float diff = fabs((float)(a[0] + a[1]) / 2 - x);
	int one = a[0];
	int two = a[1];
	float difarifm = 0;

    for (size_t i = 0;i < N;i++) {
        for (size_t j = i;j < N;j++) {   
		if (i != j) {
				difarifm = fabs(x - (float)(a[i] + a[j]) / 2);
				//printf("[%g] ", difarifm);
				if (difarifm < diff) {
					one = a[i];
					two = a[j];
					diff = difarifm;
				}
			}

        }
    }
	printf("[%d %d]\n", one, two);

}
