//ACCEPTED!!
//But, I took help from others code.
/*
I didn't understand one point.

In my approch, I passed a variable "taken" as a parameter which becomes +1 when a new value is taken
at the ending, i just returned taken. But this was not working.

In an accepted solution, when a new value is possible to add in a recursion calling, the solver
added +1 with the recursion function. This changes the whole thing dramatically! I still cannot find a clue
why this happened? :(
*/
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
      if(i==N || balance_capa<0) return 0;

    int res1=0, res2=0;

       if(arr[i][WEIGHT] > balance_capa)
            dp[i][balance_capa]=rec(i+1,balance_capa,taken);
       else{
            res1 = rec(i+1,balance_capa,taken);
            res2 = 1+rec(i+1,min(balance_capa-arr[i][WEIGHT] , arr[i][CAPA]),taken+1);
            dp[i][balance_capa] = max(res1,res2);
       }


return dp[i][balance_capa];

}

int main(){
    //freopen("11003.txt","w",stdout);
    while(cin>>N){

    if(N==0) break;
    for(int i=0;i<N;i++) cin>>arr[i][WEIGHT]>>arr[i][CAPA];
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,6005,1)<<endl;
}

return 0;
}
