//ACCEPTED!!!
#include<iostream>
using namespace std;

int main(){

int S, arr[13], val, t=1;

while(cin>>S){
    if(S<0) break;

    for(int i=0; i<=11; i++) cin>>arr[i];
    cout<<"Case "<<t++<<":"<<endl;

    for(int i=0; i<12; i++){
        cin>>val;
        if(val<=S) {
                cout<<"No problem! :D"<<endl;
                S = S - val;
                S = S + arr[i];
        }
        else {
                cout<<"No problem. :("<<endl;
                S = S + arr[i];
        }
    }

}


return 0;
}
