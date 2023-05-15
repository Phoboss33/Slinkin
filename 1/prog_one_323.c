#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d",&n);
    
    int count = 0; 
    for (int i = 1; i < n; i++) { 
        int is_prost = 1; 
        for (int j = 2; j < i; j++) { 
            if (i % j == 0 && n % j == 0) { 
                is_prost = 0;
                break;
            }
        }
        if (is_prost) { 
            printf("%d ", i);
            count++; 
        }
    }
    printf("\nКоличество простых числе для числа %d = %d", n,count);
    return 0;
}
