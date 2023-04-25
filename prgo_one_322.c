#include <stdio.h>
#include <time.h>

int main() {
    int n = 0;
    scanf("%d",&n);

    clock_t start = clock(); 

    int res = 0, max = 0, iter = 0, numb = 0;
    int kek = 0;
    for (int j = 1; j <= n;j++) {
        res = 0;
        for (int i = 1;i <=j;i++) {
            iter++;
            if (j % i == 0) {
                res += i;
                if (max < res) {
                    max = res;
                    numb = j;
                }
            }
        }
    }
    printf("number: %d, sum = %d, count of interation: %d\n",numb, max, iter);



    double time = (double)(clock() - start) / CLOCKS_PER_SEC; 
    printf("Time taken: %f seconds.\n", time); 
    return 0;
}
