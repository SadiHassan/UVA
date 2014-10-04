#include<iostream>
#include<stdio.h>
#include<string.h>
#define WEIGHT 0
#define CAPA 1
using namespace std;

int arr[1005][2], dp[1005][6010];
int N;
int rec(int i, int balance_capa, int taken){

    if(dp[i][balance_capa]!=-1) return dp[i][balance_capa];
    //if(balance_capa==0) return 0;
    //cout<<i<<" "<<balance_capa<<" "<<taken<<endl;
    //if(i==N && balance_capa>0)
      if(i==N) return taken;

    int res1=0, res2=0, res3 = 0;

    if(i+1<=N){
        if( balance_capa < arr[i+1][WEIGHT] && balance_capa!=0)
            res3 = rec(i+1,balance_capa,taken);
        else{
            if(balance_capa-arr[i+1][WEIGHT]>0)
            res1 = rec( i+1 , min( arr[i+1][CAPA] , balance_capa-arr[i+1][WEIGHT] ) , taken+1 );
            if(arr[i+1][CAPA]>0)
            res2 = rec(i+1,arr[i+1][CAPA],taken);
            }

    }


    res1 = max(res1,res2);
    res1 = max(res1,res3);

    dp[i][balance_capa]=res1;
    //if(res1>=24) cout<<i<<" "<<res1<<endl;
    return res1;
}

int main(){
    //freopen("11003.txt","w",stdout);
    while(cin>>N){

    if(N==0) break;
    for(int i=1;i<=N;i++) cin>>arr[i][WEIGHT]>>arr[i][CAPA];

    memset(dp,-1,sizeof(dp));
    cout<<rec(1,6000,1)<<endl;
}

return 0;
}
