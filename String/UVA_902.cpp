//ACCEPTED!!!
#include<iostream>
#include<string.h>
#include<map>
using namespace std;

int main(){

int N, freq;
string str, t, ans;
map<string,int>m;

while(cin>>N>>str){
    t = "";
    freq = 0;
    for(int i=0; i<N;i++)
        t += str[i];
    m[t] = 1;

    if(m[t]>freq){
        freq = m[t];
        ans = t;
    }

    for(int i=N; i<str.size();i++){
        t.erase(0,1);
        t += str[i];
        if(m.count(t)==0) m[t] = 1;
        else m[t]++;

        if(m[t]>freq){
            freq = m[t];
            ans = t;
        }
    }

    cout<<ans<<endl;
}

return 0;
}
