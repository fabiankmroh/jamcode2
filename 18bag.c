#include <stdio.h>

int end, max;
int maxvalue;
int oW[100];
int oV[100];

void f(weight, value, point, condition){
    if(condition == 0) printf("0\n");
    if(condition == 1) printf("1\n");
    if(point == end){
        if(value > maxvalue && weight == max){
            maxvalue = value;
        }
    }
    if(point < end-1 && weight < max){
        f(weight+oW[point+1], value+oV[point+1], point+1,0);
        f(weight, value, point+1,1);
    }
    return;
}

int main(void){
    scanf("%d %d", &end, &max);

    for(int i = 0; i < end; i++){
        scanf("%d %d", &oW[i], &oV[i]);
    }

    f(oW[0],oV[0],1,0);
    f(0,0,1,1);

    printf("%d\n", maxvalue);

    return 0;
}