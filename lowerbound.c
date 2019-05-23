#include <stdio.h>
int array[1000000];
int n;
int reqn;
int startn;
int endn;
int med;

void solve(void){
    while(endn - startn > 0){
        med = (startn + endn)/2;

        if(reqn > array[med]){}
    }
    return endn+1;
}

int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    scanf("%d", &reqn);

    endn = n+1;

    solve();
    return 0;
}