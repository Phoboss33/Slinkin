#include <stdio.h>

int main() {
    int arr[] = {4, 8, 10, 8, 4};
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    int d = arr[3];
    int e = arr[4];

    if (((a <= b) && (b <= c)) && ((d >= e) && (c >= d) && (b >= e))) {
        printf("Первые три элемента массива расположены по возрастанию, следующие три - по убыванию\n");
    } else {
        printf("Первые три элемента массива НЕ расположены по возрастанию, либо следующие три НЕ расположены по убыванию\n");
    }

    return 0;
}