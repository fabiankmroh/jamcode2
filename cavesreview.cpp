#include <stdio.h>
#include <algorithm>

int n;
int m[31][31];
int a[100];
int cnt;
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

int main(void){
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &m[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(m[i][j] == 1){
                cnt++;
                search(i, j, cnt+1);
            }
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(m[i][j]){
                a[m[i][j]-2]++;
            }
        }
    }

    std::sort(a, a+cnt, cmp);

    printf("%d\n", cnt);
    for(i = 0; i < cnt; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}