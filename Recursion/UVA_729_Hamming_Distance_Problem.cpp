//ACCEPTED!!!
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, H;
char str[20];

void rec(int ind, int tot){

    if(ind==N){
        if(tot==H){
                for(int i=0; i<N; i++) cout<<str[i];
                cout<<endl;
        }
        return;
    }

    str[ind] = '0';
    rec(ind+1,tot);

    if(tot<H){
        str[ind] = '1';
        rec(ind+1,tot+1);
    }

}

int main(){

int T;

cin>>T;

for(int t=1; t<=T; t++){
    cin>>N>>H;
    rec(0,0);
    if(t!=T)
    cout<<endl;
}

return 0;
}