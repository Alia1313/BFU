#include <stdio.h>
double polynom(char *expr,double x){
    int number[5]={0};
    int n=0;
    int simple=1;
    int znak=1;
    for (int i=0; expr[i] !=0;i++){
        if( expr[i]=='+'||expr[i]=='-'){
            if (simple == 1){
                    number[0]=znak*n;
                    n=0;
            }
            if(expr[i]=='+') znak=1;
            else znak=-1;
        }
          else if (expr[i]>='0'&&expr[i]<='9'){
                simple=1;
                n=n*10+(expr[i]-'0');
        }
         else if (expr[i]=='x'){
            simple=0;
            if (n==0) n=1;
            if (expr[i+1]=='^'&&expr[i+2]=='2'){
                    number[2]=znak*n;
                    i=i+2;
            } else if (expr[i+1]=='^'&&expr[i+2]=='3'){
                    number[3]=znak*n;
                    i=i+2;
            } else if (expr[i+1]=='^'&&expr[i+2]=='4'){
                    number[4]=znak*n;
                    i=i+2;
        }else number[1]= znak*n;
                n=0;
            }
    }
            if (n!=0) number[0]=znak*n;
            double rez=0;
            for (int i=0;i<5;i++){
                double proiz=1;
                for(int j=0;j<i;j++){
                    proiz=proiz*x;
                }
                rez+=proiz*number[i];
            }
            return rez;

 }


int main(int argc, char *argv[])
{
        const char *expr = "-2 + x - 3*x^2 +x^4 +5*x^3";
        double x = -10.5;
        printf("y(%f)=%s returns %f", x, expr, polynom(expr, x));

    return 0;
}
