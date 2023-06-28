#include <stdio.h>
#include <string.h>

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

void paint(int x, int y, int *count) {
    ++*count;
    if (x < 1 || x > strlen(a[0]) || y < 0 || y >= 9 || a[y][x-1] == '1') {
        return;
    }

    
    a[y][x-1] = '1';
    paint(x+1, y,count);
    paint(x, y+1,count);
    paint(x-1, y,count);
    paint(x, y-1,count);
}

int main() {
    for (int i = 0; i < 9; i++) {
        printf("%s\n", a[i]);
    }
    int count = 0;
    int *p_count = &count;
    
    paint(1, 0, p_count); // стандарнт
    
    printf("------------------------\n");
    for (int i = 0; i < 9; i++) {
        printf("%s\n", a[i]);
    }
    printf("count=>%d\n",count);
    return 0;
}