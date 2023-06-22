#include <stdio.h>
#include "findunit.c"


int func(int num) {
    if (num != 3)
        return 0;
    else
        return 1;
}

int bit_func(int num) {
    if (num < 3)
        return -1;
    else if (num > 3)
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


    

}