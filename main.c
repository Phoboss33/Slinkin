#include <stdio.h>

char a[9][14] = {
    "0001010101001",
    "0001010101001",
    "0000010101001",
    "0001010101001",
    "0001010101001",
    "1111010101001",
    "0001000101001",
    "0001010101001",
    "0001010101001"
};

void paint(int x, int y) {
    if (x < 0 || x >= sizeof(a[0]) || y < 0 || y >= sizeof(a) / sizeof(a[0]) || a[y][x] == '1') {
        return;
    }
    a[y][x] = '1';
    paint(x + 1, y);
    paint(x, y + 1);
    paint(x - 1, y);
    paint(x, y - 1);
}

int main() {
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%s\n", a[i]);
    }
    paint(1, 0);
    printf("------------------------\n");
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%s\n", a[i]);
    }
    return 0;
}