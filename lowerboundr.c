#include <stdio.h>
#define LIM 1000000

int n, k, num[LIM];

int solve(int start, int end){
    int middle;

    while(end - start > 0){
        middle = (start + end)/2;
        if(num[middle] < k){
            start = middle + 1;
        }
        else{
            end = middle;
        }
    }

    return end+1;
}

int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    scanf("%d", &k);

    printf("%d\n", solve(0, n));

    return 0;
}