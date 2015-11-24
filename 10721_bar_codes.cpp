//ACCEPTED!!!
//nije nije solve kora dp
#include<iostream>
#define ll long long
using namespace std;

int N,K,M;
//N = sum
//K = len
//M = max number; if M==3 then numbers = 1,2,3
ll dp[55][55];

ll rec(int tot, int len){
if(dp[tot][len]!=-1) return dp[tot][len];
if(len==K && tot==N) return 1;
if(len==K) return 0;

ll sum=0;
dp[tot][len]=0;
for(int i=1;i<=M;i++){
    if(tot+i<=N)
        sum += rec(tot+i,len+1);
}
return dp[tot][len]=sum;
}

int main(){

while(cin>>N>>K>>M){
for(int i=0;i<53;i++) for(int j=0;j<53;j++) dp[i][j]=-1;
cout<<rec(0,0)<<endl;
}

return 0;
}
