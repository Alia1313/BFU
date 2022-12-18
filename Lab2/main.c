#include <stdio.h>
int Calc(char *s){
    char op;
    int a;
    int b;
    int rez;
    if (s[1]=='=') {
        op=s[3];
        if (s[0]=='x') rez=-1;
        else rez=s[0]-'0';
        if (s[2]=='x') a=-1;
        else a=s[2] -'0';
        if (s[4]=='x') b=-1;
        else b=s[4]-'0';
    } else if (s[3]=='=') {
        op=s[1];
        if (s[0]=='x') {
            a=-1;
            b=s[2]-'0';
            rez=s[4]-'0';
        }
        else if (s[2]=='x'){
            a=s[0]-'0';
            b=-1;
            rez=s[4]-'0';
        }
        else if (s[4]=='x') {
            a=s[0]-'0';
            b=s[2]-'0';
            rez=-1;
        }
    }
    if (rez==-1){
        if (op=='+') return(a+b);
        if (op=='-') return(a-b);
        if (op=='*') return(a*b);
        if (op=='/') return(a/b);
    }
    if (a==-1){
        if (op=='+') return(rez-b);
        if (op=='-') return(rez+b);
        if (op=='*') return(rez/b);
        if (op=='/') return(rez*b);
    }
    if (b==-1){
        if (op=='+') return(rez-a);
        if (op=='-') return(a-rez);
        if (op=='*') return(rez/a);
        if (op=='/')  return(a/rez);

    }

    return 0;

}

int main(int argc, char *argv[])
{
 char *expression[]={"2+x=6","6-x=2","x-3=7","x*5=5","x/3=2","4/x=4","x=4+2","x+3=7","4/x=1","x-0=8","x+3=2","6-x=4","x-3=0","x*2=6","x/2=4","5/x=1","x=4/2","x*3=6","7/x=1","x=9*0","x=3/1","x+6=6","x=6-1"};
 int len=sizeof(expression)/sizeof(char *);
 for (int i=0; i<len;i++)
     printf("%s x=%d\n",expression[i],Calc(expression[i]));
}
