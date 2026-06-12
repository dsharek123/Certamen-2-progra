#include <iostream>
#include <vector>

using namespace std;


bool solve(vector<vector<char>>& bosque_,int &cont,int posx,int posy){
    if (bosque_[posx][posy] == '*'){
        return true;
    }
    bosque_[posx][posy] = 'V';

    int cont2 = 0;
        int mx[4] = {0,0,-1,1};
        int my[4] = {-1,1,0,0};

    for (int i = 0; i < 4;i++){
        if (bosque_[posx+mx[i]][posy+my[i]] == '.' || bosque_[posx+mx[i]][posy+my[i]] == '*' ){
            cont2++;
        }
    }

    if (cont2 > 1){
        cont += 1;
    }

    for (int i = 0; i < 4;i++){
        if (bosque_[posx+mx[i]][posy+my[i]] == '.' || bosque_[posx+mx[i]][posy+my[i]] == '*' ){
            if (solve(bosque_,cont,posx+mx[i],posy+my[i])){
                return true;
            };
        }
    }
    bosque_[posx][posy] = '.';

    if (cont2 > 1){
        cont -= 1;
    }

    return false;
}

int main(void){

    
    int t;
    int ss = 0;
    scanf("%d",&t);
    while(ss <t){
    int m,n;
    int k;
    int b,v;
    int cont = 0;
    scanf("%d %d",&m,&n);
    vector<vector<char>> bosque(m+2,vector<char>(n+2,'X'));

    for (int i = 1; i < m +1 ; i++){
        for(int j = 1; j < n +1 ;j++){
            scanf(" %c",&bosque[i][j]);
            if (bosque[i][j] == 'M'){
                b = i;
                v = j; 
            }
        }
    }
    scanf("%d",&k);
    solve(bosque,cont,b,v);

    if (cont == k){
        printf("%s","Impressed\n");
    }else{
        printf("%s","Oops!\n");
    }
    ss++;
    }


    return 0;
}
