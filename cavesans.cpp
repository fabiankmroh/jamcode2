#include <stdio.h>
#include <algorithm>

int n;
int m[31][31];
int size[30];
int doodeojiN;
int i, j;

bool safe(int x, int y){
    return (0 <= x && x < n) && (0 <= y && y < n);
}

bool cmp(int a, int b){
    return a>b;
}

void search(int x, int y, int fill){
    m[x][y] = fill;

    if(safe(x, y-1) && m[x][y-1] == 1)
        search(x, y-1, fill);
    if(safe(x, y+1) && m[x][y+1] == 1)
        search(x, y+1, fill);
    if(safe(x-1, y) && m[x-1][y] == 1)
        search(x-1, y, fill);
    if(safe(x+1, y) && m[x+1][y] == 1)
        search(x+1, y, fill);
}

void solve(){
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &m[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(m[i][j] == 1){
                doodeojiN++;
                search(i, j, doodeojiN+1);
            }
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(m[i][j]){
                size[m[i][j]-2]++;
            }
        }
    }

    std::sort(size, size+doodeojiN, cmp);

    printf("%d\n", doodeojiN);

    for(i = 0; i < doodeojiN; i++){
        printf("%d\n", size[i]);
    }
}

int main(void){
    solve();
}