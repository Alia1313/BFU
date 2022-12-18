#include <stdio.h>
#define N 6

int check(int a, int x, int y) {
    if(x >= a || x < 0) return 0;
    else if(y >= a|| y < 0) return 0;
    else return 1;
}

int main(int argc, char *argv[])
{
    int mat[N][N] = {0};
    int storona=0; // 0=вниз,1=диаг.вверх,2=вправо,3=диаг.вниз
    int n =1;
    mat[0][0] = n;
    n+=1;
    int x=0;
    int y=0;
    while(n != N*N+1) {
        if(storona==0) {
            if(check(N, x, y+1)==1 && mat[y+1][x]==0) {//Двигаемся вниз
                y++;
                mat[y][x] = n;
                n++;
            }
            storona=1;
        }
        if(storona==1) {
            if(check(N, x+1, y-1)==1 && mat[y-1][x+1]==0){//по диагонали вверх
                x++;
                y--;
                mat[y][x]=n;
                n++;
            } else storona=2;
        }
        if(storona==2) {
            if(check(N, x+1, y)==1 && mat[y][x+1]==0) {// вправо
                x++;
                mat[y][x]=n;
                n++;
            }
            storona=3;
        }
        if(storona==3) {
            if(check(N,x-1, y+1) && mat[y+1][x-1] == 0) {// по диагонали вниз
                x--;
                y++;
                mat[y][x]=n;
                n++;
            } else storona=0;
        }
    }
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            if(mat[i][j] <= 9) {
                printf(" %d ", mat[i][j]);
            } else {
                printf("%d ", mat[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
