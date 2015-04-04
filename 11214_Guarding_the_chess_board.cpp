#include<iostream>
using namespace std;

string str[12];
int m, n, tot_block;

int check(int rr, int cc){

    int tot = 0;
    int r = rr, c = cc;
    while(r>=0){
            if(str[r][c]=='X'){
                str[r][c] = '.';
                tot++;
            }
    r--;
    }

    r = rr; c = cc;
    while(r<m){
            if(str[r][c]=='X'){
                str[r][c] = '.';
                tot++;
            }
    r++;
    }

    r = rr; c = cc;
    while(c>=0){
            if(str[r][c]=='X'){
                str[r][c] = '.';
                tot++;
            }
    c--;
    }

    r = rr; c = cc;
    while(c<n){
            if(str[r][c]=='X'){
                str[r][c] = '.';
                tot++;
            }
    c++;
    }




return tot;
}

int main(){

while(cin>>m){
    if(m==0) break;
    cin>>n;
    for(int i=0; i<m; i++) cin>>str[i];
    tot_block = 0;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) if(str[i][j]=='X') tot_block++;

}

return 0;
}
