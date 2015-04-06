//ACCEPTED!!!
#include <iostream>
#include <vector>
#define LI long int
using namespace std;

int main(){

LI N, M, a, b, carry, sum;
vector<LI> arr1, arr2,ans;
cin>>N;

for(LI i=1;i<=N;i++){

    cin>>M;
    for(LI j=0;j<M;j++){
        cin>>a>>b;
        arr1.push_back(a);
        arr2.push_back(b);
    }
    carry = 0;
    for(LI j=M-1;j>=0;j--){
        sum = ( arr1[j] + arr2[j] + carry )%10;
        carry = ( arr1[j] + arr2[j] + carry )/10;
        ans.push_back(sum);
    }
    LI j=M-1;
    while(ans[j]==0) {j--; if(j<0) break;}
    if(j<0) cout<<"0";
    else
    while(j>=0){cout<<ans[j]; j--;}

    cout<<endl;
    if(i<N) cout<<endl;

    arr1.clear();
    arr2.clear();
    ans.clear();
}

return 0;
}
