#include <stdio.h>
int array[1000000];
int n;
int reqn;
int startn;
int endn;
int solven;

void solve(void){
    if(startn == endn){ 
        printf("-1\n");
        return;
    }

    if(reqn < array[(startn + endn)/2]){
        endn = (startn + endn)/2 - 1;
        solve();
    }
    else if(reqn == array[(startn + endn)/2]){
        printf("%d\n", (startn + endn)/2 + 1);
    }
    else if(reqn > array[(startn + endn)/2]){
        startn = (startn + endn)/2 + 1;
        solve();
    }


}

int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    scanf("%d", &reqn);

    endn = n;

    solve();

    return 0;
}