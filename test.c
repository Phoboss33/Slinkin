#include <stdio.h>
#include <assert.h>

/*int isGreater1(int x, int y) {
    int diff = y - x;
    int sign = (diff >> 31) & 1;
    int check = !(diff ^ 0);
    return (sign ^ 1) & 1 & ~check;
}*/
int isGreater(int x, int y) {
    return y > x;
}

int sinusoidal(int* mas, int n) {
    int ascendingOrder = isGreater(mas[0], mas[1]) & isGreater(mas[1], mas[2]);
    int descendingOrder = isGreater(mas[n-1], mas[n-2]) & isGreater(mas[n-2], mas[n-3]);

    int i = 3;
    while (i < n-2) {
        int j = i;
        while (j <= n-2 & mas[j] == mas[j+2]) {
            j += 2;
        }
        ascendingOrder &= isGreater(mas[j], mas[j-1]) & isGreater(mas[j+1], mas[j]) & (j <= n-2);
        descendingOrder &= isGreater(mas[j+1], mas[j]) & isGreater(mas[j], mas[j-1]) & (j <= n-2);
        i = j + 4; 
    }

    return (ascendingOrder & descendingOrder);
}

void testSinusoidal() {
    int mas1[] = {1, 2, 3, 2, 1};
    int mas2[] = {3, 5, 7, 2, -10};
    int mas3[] = {1, 2, 3, 2, 1, 2, 3, 2, 1};
    int mas4[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int mas5[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int mas6[] = {1, 2, 1, 2, 1, 2, 1, 2};
    int mas7[] = {1, 2, 1, 2, 1, 2, 1, 2, 1};
    int mas8[] = {1, 1, 1, 1, 1, 1, 1, 1};
    int mas9[] = {2, 2, 3, 2, 1};
    int mas10[] ={1, 2, 3, 2, 2};
    int mas11[] = {1, 2, 3, 2, 1, 2, 3, 2, 1, 2, 3, 2, 1};
    int mas12[] = {2, 5, 7, 1, -9, 2, 8, 3, 0, 4, 9, 5, 3};

    assert(sinusoidal(mas1, 5));
    assert(sinusoidal(mas2, 5));
    assert(sinusoidal(mas3, 9));
    assert(!sinusoidal(mas4, 8));
    assert(!sinusoidal(mas5, 8));
    assert(!sinusoidal(mas6, 8));
    assert(!sinusoidal(mas7, 9));
    assert(!sinusoidal(mas8, 8));
    assert(!sinusoidal(mas9, 5));
    assert(!sinusoidal(mas10, 5));
    assert(sinusoidal(mas11, 13));
    assert(sinusoidal(mas12, 13));
}

int main() {
    testSinusoidal();
    printf("All tests successfully!\n");
    return 0;
}
