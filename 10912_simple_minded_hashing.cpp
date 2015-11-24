#include<iostream>
#include<string.h>
//#define ll long long
using namespace std;
int K, N, T, P, len, L;
int cc=0;
int dp[360][27];
int marks[30];
//int ans;

int rec(int start, int tot, int taken){
    //cout<<"cc : "<<cc++<<endl;
    if(dp[tot][taken]!=-1) return dp[tot][taken];

    if(taken>=N&&tot==T) return 1;
    else if(taken>=N||start>=len-1) return 0;

    int ans=-1;
    dp[tot][taken]=0;

    for(int i=start;i<len;i++){
            if( tot+marks[i]<=T ) {
            ans = rec(i+1,tot+marks[i],taken+1);
            if(ans!=-1)
            dp[tot][taken] += ans;
            //cout<<dp[tot][taken]<<endl;
        }
    }
    //if(ans==-1)
    return dp[tot][taken];
}

int main(){
    //recurse(0);
int Case=1;
while(cin>>N>>T){ //L S
        if(!N&&!T) break;
        int sum=0;
        int i,j;
        for(i=1;i<=T;i++)
                marks[i] = i;

        len = i;

        cout<<"Case "<<Case++<<": ";
        if(N>26||T>351) {cout<<"0"<<endl; continue;}

        for(i=0;i<=355;i++) for(j=0;j<=27;j++) dp[i][j] = -1;

        cout<<rec(1,0,0)<<endl;
        cout<<"why stop?"<<endl;

        }
return 0;
}
