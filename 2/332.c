#include <stdio.h>
#include <math.h>

int main() {
    int c[4] = {0, 0, 0, 0};

    int n;
    printf("Введите n: ");
    scanf("%i", &n);

    int i;
    for (i = 0; i < 4; ++i) {
        if (n > 0) {
            c[i] = (int) sqrt(n);
            n -= c[i] * c[i];
        }
        else
            break;
    }

    printf("Значения x, y, z, t: [");
    for (int i = 0;i < 4;i++) {
        if (i < 3)
            printf("%i, ", c[i]);
        else
            printf("0]\n");

    }

    return 0;
}