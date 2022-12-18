#include <stdio.h>

int abba(int mas[8]){
    char mat[8][8]={'0'};
    for (int i=0; i<8;i++){
        int number=mas[i];
       for (int j=1;j<9;j++){
           int c= number >> (32-(4*j));
           int rez= c & 0xF;
           if(rez < 10) mat[i][j-1] = rez;
           else if(rez == 10) mat[i][j-1] = 'A';
           else if(rez == 11) mat[i][j-1] = 'B';
           else if(rez == 12) mat[i][j-1] = 'C';
           else if(rez == 13) mat[i][j-1] = 'D';
           else if(rez == 14) mat[i][j-1] = 'E';
           else if(rez == 15) mat[i][j-1] = 'F';
       }
    }
    int k=0;
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (mat[i][j]=='A' && mat[i][j+1]=='B' && mat[i][j+2]=='B' && mat[i][j+3]=='A' && (j+3)<8) k=k+1;
            if (mat[i][j]=='A' && mat[i][j+1]=='B' && mat[i][j+2]=='B' && mat[i+1][j+2]=='A' && (j+2)<8 && (i+1<8)) k=k+1;
            if (mat[i][j]=='A' && mat[i][j+1]=='B' && mat[i+1][j+1]=='B' && mat[i+1][j+2]=='A' && (j+2)<8 && (i+1<8)) k=k+1;
            if (mat[i][j]=='A' && mat[i][j+1]=='B' && mat[i+1][j+1]=='B' && mat[i+1][j-1]=='A'&& (j+1)<8 && (i+1<8) && (j-1>0)) k=k+1;
            if (mat[i][j]=='A' && mat[i][j+1]=='B' && mat[i+1][j+1]=='B' && mat[i+2][j+1]=='A'&& (j+1)<8 && (i+2<8)) k=k+1;
            if (mat[i][j]=='A' && mat[i+1][j]=='B' && mat[i+1][j+1]=='B' && mat[i+1][j+2]=='A'&& (j+2)<8 && (i+1<8)) k=k+1;
            if (mat[i][j]=='A' && mat[i+1][j]=='B' && mat[i+1][j+1]=='B' && mat[i+2][j+1]=='A'&& (j+1)<8 && (i+2<8)) k=k+1;
            if (mat[i][j]=='A' && mat[i+1][j]=='B' && mat[i+2][j]=='B' && mat[i+3][j]=='A'&& (i+3<8)) k=k+1;
            if (mat[i][j]=='A' && mat[i+1][j]=='B' && mat[i+2][j]=='B' && mat[i+2][j+1]=='A'&& (i+2<8)) k=k+1;
            if (mat[i][j]=='A' && mat[i][j-1]=='B' && mat[i-1][j-1]=='B' && mat[i-1][j]=='A'&& (j-1)>0 && (i-1>0)) k=k+1;
            if (mat[i][j]=='A' && mat[i-1][j+1]=='B' && mat[i-1][j+2]=='B' && mat[i][j+2]=='A'&& (j+2)<8 && (i-1<0)) k=k+1;
            if (mat[i][j]=='A' && mat[i+1][j]=='B' && mat[i+1][j+1]=='B' && mat[i][j+1]=='A'&& (j+1)<8 && (i+1<8)) k=k+1;



        }
    }


    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            printf("%c ",mat[i][j]);
        }
        printf("\n");
    }
    return k;
}

int main(int argc, char *argv[])
{
    int sample1[8] ={-1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592};
    int sample2[8] ={-1430650880, -1157627904, 3145728, -1442185216, 184549376, 11534336, 655360, 3840};
    printf("%d\n", abba(sample2));
    return 0;
}
