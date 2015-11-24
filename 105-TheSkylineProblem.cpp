/*
UVA-105
The Sky-Line Problem
Type: Ad hoc/Brute force
Difficulty: Easy
*/
#include<iostream>
#include<string.h>
using namespace std;

int main(){

int arr[10000+5];
int L, H, R;
memset(arr,0,sizeof(arr));
int LL=15000;
int RR=-1;

while(cin>>L>>H>>R){
    for(int i=L; i<R; i++){
        if(arr[i]<H) arr[i]=H;
    }
    if(LL>L) LL=L;
    if(RR<R) RR=R;
}

for(int i=LL; i<=RR; i++){

    if(i==LL) {cout<<i<<" "<<arr[i];if(i!=RR) cout<<" ";}
    else if(arr[i]!=arr[i-1]) {cout<<i<<" "<<arr[i];if(i!=RR) cout<<" ";}

}
cout<<endl;
return 0;
}
