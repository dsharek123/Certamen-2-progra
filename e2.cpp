
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int supersum(char* cadena,int n){
    char *aux = malloc(sizeof(char)*100001);
    long long suma = 0;
    int tam = strlen(cadena);
    if (tam == 1 && n == 1){
        free(aux);
        return cadena[0] - '0';
    }

    for (int i = 0; i < tam; i++){
        suma += cadena[i] - '0';
    }

    
    if (n > 1){
        suma *= n;
    }

    sprintf(aux,"%lld",suma);

    if (n != 1){
        n = 1;
    }
    int res = supersum(aux, n);
    free(aux);
    return res;
}

int main(void){
    int m,h;
    char *cadena = malloc(sizeof(char)*100001);
    scanf("%s",cadena);
    scanf("%d",&m);
    h = supersum(cadena,m);
    printf("%d",h);
    free(cadena);
    return 0;
}
