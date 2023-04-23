#include <stdio.h>

int isUp(int x, int y) {
    return x < y;
}

int main() {
    printf("write count of numbers:\n");

    int N = 0;

    scanf("%d",&N);
    printf("write numbers:\n");

    int mas[N];
    int numb = 0;
    for (int i = 0;i < N; i++){
        scanf("%d",&numb);  // fgets(mas, 9, stdin);
        mas[i] = numb;
    }

    int sum = isUp(mas[0],mas[1]);
    for (int i = 0;i < N-1;i++){
        sum &= isUp(mas[i],mas[i + 1]);
        printf("%d\n", sum);
    }

    if (sum == 1) {
        printf("\nYes\n");
    }
    else
        printf("No\n");
    
}