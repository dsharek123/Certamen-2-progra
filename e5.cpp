#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void btracking(vector<int>& stackc,vector<int>& acum,int suma,int obj,int indice,int& res){

    if (suma == obj){
        res += 1;
        return;
    }
    if (suma > obj){
        return;
    }
    for (int i = indice; i < acum.size();i++){
        stackc.push_back(acum[i]);
        btracking(stackc,acum,suma + acum[i],obj,i + 1, res);
        stackc.pop_back();
    }
}


int main(void){

    int n,m;
    int res = 0;
    vector<int> stack = {};
    vector<int> acum = {};
    
    
    scanf("%d %d",&n,&m);
    int num = round(pow(n,(1.0/m)));

    for ( int i = 1; i <= num; i++){
        acum.push_back(pow(i,m));
    }

    btracking(stack,acum,0,n,0,res);

    printf("%d", res);

    return 0;
}
