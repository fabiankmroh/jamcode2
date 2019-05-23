#include <stdio.h>
int array[1000000];
int n;
int reqn;
int startn;
int endn;
int solven;

void solve(void){
    int med = (startn+endn)/2;
    if(startn > endn){ 
        return;
    }

    if(reqn < array[med]){
        endn = med;
        solve();
    }
    else if(reqn >= array[med]){
        startn = med + 1;
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