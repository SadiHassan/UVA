//ACCEPTED!!!
#include<stdio.h>

char str[1000][1000];

int dist(int i, int j, int k, int l){
    int x, y;
    if(i-k>=0) x = i - k;
    else x = k - i;
    if(j-l>=0) y = j - l;
    else y = l - j;
    return (x+y);
}

int _max(int a, int b){ return ( a>=b ? a : b ); }
int _min(int a, int b){ return ( a<=b ? a : b ); }

int main(){

int N, i, j, k, l, m, ans;

while(scanf("%d",&N)==1){

    getchar();

    for(i=0;i<N;i++) gets(str[i]);
    ans = 0;

    for(i=0;i<N;i++)
    for(j=0;j<N;j++){
        if(str[i][j]=='1'){
            m = 10000;
            for(k=0;k<N;k++)
                for(l=0;l<N;l++)
                if(str[k][l]=='3') m = _min(m,dist(i,j,k,l));
            ans = _max(ans,m);
        }
    }

    printf("%d\n",ans);
}

return 0;
}
