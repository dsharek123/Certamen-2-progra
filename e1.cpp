#include <stdio.h>
int calcular(int n,int a,int b,int c){
    if (n == 1){
        return a;
    }else if(n == 2){
        return b;
    }else if (n == 3){
        return c;
    }
    return (calcular(n - 1,a,b,c) + calcular(n - 2,a,b,c) + calcular(n-3,a,b,c));

}


int main(void){
    int n,a,b,c,res;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    res = calcular(n,a,b,c);
    printf("%d",res);




    return 0;
}
