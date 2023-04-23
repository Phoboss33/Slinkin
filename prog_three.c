#include <stdio.h>
#include <assert.h>

/*int isGreater1(int x, int y) {
    int diff = y - x;
    int sign = (diff >> 31) & 1;
    int check = !(diff ^ 0);
    return (sign ^ 1) & 1 & ~check;
}*/

int isUp(int x, int y) {
    return y > x;
}
int isDown(int x, int y) {
    return y < x;
}

int sinusoidal(int* mas, int n) {
    int kek = isUp(mas[0], mas[1]);
    int lol = isDown(mas[2], mas[3]);

    for (int j = 0;j < n;j+=4) {
        for (int i = 0;i < 2; i++) {      // решить проблему с итерациями
            kek &= isUp(mas[j + i], mas[j + i + 1]);
            lol &= isDown(mas[j + i + 2], mas[j + i + 3]);
            printf("%d [%d] < [%d] || %d [%d] > [%d] \n", kek, mas[i + j], mas[i + j+1], lol, mas[i + j+2], mas[i + j+3]);
            
        }
    }
    printf("%d\n",(kek & lol));
    return (kek & lol);
}

int main() {
    //int mas[] = {1, 2, 3, 2, 1, 2, 3, 2, 1, 2, 3, 2, 1};
    //int mas[] = {1, 2, 3, 2, 1, 2, 3, 2, 1};
    //int mas[] = {1, 2, 3, 2, 1};  // y
    //int mas[] = {3, 5, 7, 2, -10}; // y
    //int mas[] = {1, 2, 3, 2, 1, 2, 3, 2, 1}; // y
    //int mas[] = {1, 2, 3, 4, 5, 6, 7, 8}; // n
    //int mas[] = {8, 7, 6, 5, 4, 3, 2, 1};  // n
    //int mas[] = {1, 2, 1, 2, 1, 2, 1, 2};  // n
    //int mas[] = {1, 2, 1, 2, 1, 2, 1, 2, 1}; // n
    //int mas[] = {1, 1, 1, 1, 1, 1, 1, 1};  // n
    //int mas[] = {2, 2, 3, 2, 1}; // n
    //int mas[] ={1, 2, 3, 2, 3};  // n
    //int mas[] = {1, 2, 3, 2, 1, 2, 3, 2, 11, 2, 3, 2, 1}; // n
    //int mas[] = {2, 5, 7, 1, -9, 2, 8, 3, 0, 4, 9, 5, 3};  // y
    printf("write count for numbers:\n");
    int N;
    scanf(" %d",&N);
    int mas[N];
    printf("Write nubmers:\n");

    int numb = 0;
    int len = N-1;

    for (int i;i < N;i++){
        scanf(" %d",&numb); // fgets(mas, 9, stdin);
        mas[i] = numb;
    }

    //sinusoidal(mas,len);
    //int len = sizeof(mas) / sizeof(int) - 1;
    //printf("%d\n", len);


    if (sinusoidal(mas,len) == 1)
        printf("Yes\n");
    else 
        printf("No\n");

    return 0;
}
