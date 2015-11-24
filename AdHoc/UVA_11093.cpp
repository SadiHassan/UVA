//ACCEPTED !!! Finally :)
#include<iostream>
#define LL long long
using namespace std;

LL has[100005];

int main(){

LL T, N, sum, ind, sum_so_far, need;
cin>>T;

for(LL t=1; t<=T; t++){
    cin>>N;

    for(LL i=0; i<N; i++)
        cin>>has[i];

    ind = -1;
    cin>>need;

    sum_so_far = has[0]-need;
    sum = has[0]-need;
    if(sum_so_far>=0) ind=0;
    else sum_so_far = 0;

    for(LL i=1; i<N; i++){
        cin>>need;
        sum_so_far += has[i] - need;
        sum += has[i] - need;
        if(sum_so_far<0) {ind = -1;sum_so_far=0;}
        else if(sum_so_far>=0&&ind==-1) ind=i;
    }

    cout<<"Case "<<t<<": ";
    if(sum<0) { cout<<"Not possible"<<endl; continue; }
    cout<<"Possible from station "<<(ind+1)<<endl;
}

return 0;
}
