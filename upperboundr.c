#include <stdio.h>

int n, k;
int num[1000000];

int solve(int start, int end){
    int middle;

    while(end - start > 0){
        middle = (start+end)/2;

        if(num[middle] <= k)
            start = middle + 1;
        else end = middle;
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