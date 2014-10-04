//ACCEPTED!!!
// Almost myself
#include<iostream>
#include<string.h>
#define ull long long
using namespace std;
int K, N, T, P, len;

ull dp[72][72];
int marks[72];
int ans;
ull rec(int tot, int taken){

    if(taken==N&&tot==T) return 1;
    else if(taken==N) return 0;

    if(dp[tot][taken]!=-1) return dp[tot][taken];

    ull ans=-1;
    dp[tot][taken]=0;
    for(int i=0;i<len;i++){
            if(tot+marks[i]<=T) {
            ans = rec(tot+marks[i],taken+1);
            dp[tot][taken] += ans;
        }
    }
    return dp[tot][taken];
}

int main(){

while(cin>>K){
    for(int k=1;k<=K;k++){
        cin>>N>>T>>P;

        int m = P, i;
        ans=0;
        for(i=0;;i++){
                marks[i] = m;
                m++;
                if( m > (T-P*(N-1)) + 1 ) break;
        }
        len = i;
        //for(int i=0; i<len;i++) cout<<marks[i]<<" ";
        if(len==0) cout<<"0"<<endl;
        else {
                //memset(dp,-1,sizeof(dp));
                //rec(0,0);
                for(int i=0;i<72;i++) for(int j=0;j<72;j++) dp[i][j]=-1;

                cout<<rec(0,0)<<endl;

        }
    }
}
return 0;
}
