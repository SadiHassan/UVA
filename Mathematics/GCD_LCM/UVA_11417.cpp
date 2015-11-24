//ACCEPTED!!! simple gcd
#include<iostream>
#define ULL unsigned long int
using namespace std;

ULL arr[505][505];

ULL GCD(ULL a, ULL b){
    if(b==0) return a;
    return GCD(b,a%b);
}

int main(){

ULL val, N, G;

for(int i=1; i<=500;i++)
for(int j=i; j<=500; j++){
    val = GCD(i,j);
    arr[i][j] = val;
    arr[j][i] = val;
}

while(cin>>N){
    if(N==0) break;
    G=0;
    for(int i=1;i<N;i++)
    for(int j=i+1;j<=N;j++)
        G+=arr[i][j];

    cout<<G<<endl;
}

return 0;
}