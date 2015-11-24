#include<iostream>

using namespace std;

int main(){

int N, M, T;
int ans, balance, tot;

while(cin>>N>>M>>T){

        tot=0;
        ans=0;
        balance = 10005;

        for(int t=1; t<=T; t++){


            if(t-tot>=N){
                if(balance>=T-N-tot){
                    ans++;
                    balance = T-N-tot;
                    tot+=N;
                    cout<<balance<<" "<<ans<<endl;
                }
            }
            else if(t-tot>=M){
                if(balance>=T-M-tot){
                    ans++;
                    balance = T-M-tot;
                    tot+=M;
                    cout<<balance<<" "<<ans<<endl;
                }
            }

        }

    cout<<ans<<" "<<balance<<endl;

    }


return 0;
}
