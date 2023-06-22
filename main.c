#include <stdio.h>
#include "findunit.h"


int func(int num) {
    if (num != 3)
        return 0;
    else
        return 1;
}

int bin_func(int num) {
    if (num < 13)
        return -1;
    else if (num > 13)
        return 1;
    else 
        return 0;
}


int main() {
    testfunc test = func;
    int mas[5] = {0,3,4,2,3};
    int result[3] = {};
    printf("%d\n",line_find_one(mas, sizeof(mas) / sizeof(mas[0]), test));
    printf("%d\n", find_count);
    printf("=====\n");

    printf("%d\n", line_find_all(mas, 5, test, result, sizeof(result) / sizeof(result[0])));
    
    /*for (int i = 0;i < 3;i++)
        printf("=>%d\n", result[i]);*/


    printf("===binary===\n");
    testfunc test_bin = bin_func;
    int bin_mas[11] = {-1,1,3,5,7,7,9,11,13,15,22};

    printf("%d\n", bin_find_one(bin_mas, 10, test_bin));

    int kek = 0;
    int lol = 0;
    printf("=====\n");
    bin_find_all(bin_mas, 14, test_bin, &kek, &lol);
    
    printf("beg=>%d  end=>%d", kek, lol);
}