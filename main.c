#include <stdio.h>
#include <string.h>

char a[9][14] = {
    "0001010101001",
    "0001010101001",
    "0000010101001",
    "0001010101001",
    "0001010101001",
    "1111010101001",
    "0001000001001",
    "0001010101001",
    "0001010101001"   
};

void paint(int x, int y, int *count) {
    int kek[9 * 14][2]; 
    int front = 0;
    int next = 0;

    kek[next][0] = x;
    kek[next][1] = y;
    next++;

    ++*count;
    while (front < next) {
        x = kek[front][0];
        y = kek[front][1];
        front++;

        if (x < 1 || x > strlen(a[0]) || y < 0 || y >= 9 || a[y][x - 1] == '1') {
            continue;
        }


        a[y][x-1] = '1';

        for (int i = x + 1; i <= strlen(a[0]); i++) {
            if (a[y][i - 1] == '1') {
                break;
            }
            kek[next][0] = i;
            kek[next][1] = y;
            next++;
        }

        paint(x, y+1,count); 
        paint(x-1, y,count); 

        for (int i = y-1; i >= 0; i--) {
            if (a[i][x-1] == '1') {
                break;
            }
            kek[next][0] = x;
            kek[next][1] = i;
            next++;
        }
    }
}

int main() {
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%s\n", a[i]);
    }
    int count = 0;
    int *p_count = &count;

    paint(1, 0, p_count);
    printf("------------------------\n");
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        printf("%s\n", a[i]);
    }

    printf("count=>%d",*p_count);
    return 0;
}