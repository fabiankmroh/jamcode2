#include <stdio.h>
#include <stdlib.h>

int n;
int map[35][35];
int area[900]; 
int i, j;
int doodeoji;

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int search(int x, int y){
    if(map[x][y] == 0){
        return 1;
    }
    else{
        return search(x,y-1) + search(x, y+1) + search(x-1, y) + search(x+1, y);
    }
    map[x][y] = doodeoji+1;
}

void solve(void){
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(map[i][j] == 1){
                area[doodeoji] = search(i, j);
                doodeoji++;
            }
        }
    }
}

int main(void){
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &map[i][j]);
        }
    }

    printf("%d\n", doodeoji-1);
    printf("doodeoji printed\n");
    qsort(area, sizeof(area)/sizeof(*area), sizeof(area), comp);
    printf("sort complete\n");
    while(area[i] != 0){
        printf("%d\n", area[i]);
        i++;
    }
}