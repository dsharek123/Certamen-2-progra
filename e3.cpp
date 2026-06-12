#include <stdio.h>
int lomuto(int *numeros,int min,int max,int n){
    int pv = numeros[max];
    int i = min - 1;

    for (int j = min; j < max; j++){
        if (numeros[j] < pv){
            i++;
            int temp = numeros[i];numeros[i] = numeros[j];numeros[j] = temp;
        }
    }
    int temp = numeros[i+1];
    numeros[i+1] = numeros[max];
    numeros[max] = temp;

    for (int k = 0; k <= n-1;k++){
        printf("%d ",numeros[k]);
    }
    printf("\n");
    return i + 1;
}
void qsort(int *numeros,int min,int max,int n){
    if (min < max){
        int l = lomuto(numeros,min,max,n);
        qsort(numeros,min,l-1,n);
        qsort(numeros,l+1,max,n);
    }
}


int main(void){

    int n;

    scanf("%d",&n);

    int numbers[n];

    for (int i = 0;i < n;i++){
        scanf("%d",&numbers[i]);
    }

    qsort(numbers,0,n-1,n);

    return 0;
}
