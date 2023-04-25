#include <stdio.h>

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    printf("Введите натуральные числа: ");
    scanf("%d", &n);
    printf("Чичсла меньше %d и взаимно простые с ним: ", n);
    for(int i = 1; i < n; i++) {
        if(gcd(i, n) == 1)
            printf("%d ", i);
    }
    return 0;
}