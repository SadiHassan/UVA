//ACCEPTED!!!
#include<stdio.h>
#include<iostream>
using namespace std;

int arr[10], row[10], col[10], temp[10];
int places[100][10], ind;

int my_abs(int val){ if(val<0) return (val*(-1)) ;  return val; }
int _min(int a, int b){ if(a<=b) return a; return b;}

void init(){
    int i;
    for(i=1; i<=8; i++) {row[i] = 0; col[i] = 0; temp[i] = 0 ;}
}

int check_pos(int r1, int c1, int r2, int c2){
    if(r1==r2||c1==c2) return 0;
    if( my_abs(r1-r2)==my_abs(c1-c2)) return 0;
    return 1;
}

int check(int r, int c){
    for(int i=1; i<c; i++)
        if( check_pos(r,c,temp[i],i) == 0 ) return 0;
    return 1;
}

void save(){

    for(int i=1; i<=8; i++)
        places[ind][i] = temp[i];
    ind++;
    return;
}

void rec(int c){

    if(c==9){ save(); return; }

    if(col[c]==1)
        rec(c+1);

    for(int r=1; r<=8; r++){
        if(row[r]==1) continue;
        if(check(r,c)==1){
            row[r] = 1;
            col[c] = 1;
            temp[c] = r;
            rec(c+1);
            row[r] = 0;
            col[c] = 0;
        }
    }
}


int main(){

int t=1, i, ans, tot;
init();
rec(1);

while(scanf("%d %d %d %d %d %d %d %d",&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6],&arr[7],&arr[8])==8){

    printf("Case %d: ",t++);
    ind = 0;

    //cout<<ind<<endl;
    ans = 1000;

    for(int i=0; i<92; i++){
        tot = 0;
        for(int j=1;j<=8;j++)
        if(arr[j]!=places[i][j]) tot++;
        ans = _min(ans,tot);
    }
    cout<<ans<<endl;
}

return 0;
}
