//ACCEPTED!!! LIS
#include<iostream>
#include<vector>
#define LI long int
using namespace std;
vector<LI> sequence, I, L;
LI inf = 1000000;

int main(){

LI val;

while(cin>>val) sequence.push_back(val);

I.push_back(inf*(-1));

LI n = sequence.size();
for( LI i = 1; i <= n; i++ ) I.push_back(inf);

LI LisLength = 0;

for(LI i = 0; i < n; i++ ) {

        LI low, high, mid;
        low = 0;
        high = LisLength;

        while( low <= high ) {
            mid = ( low + high ) / 2;
            if( I[mid] < sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }

        I[low] = sequence[i];

        if( LisLength < low ) LisLength = low;
        L.push_back(low);
    }

cout<<LisLength<<endl;
cout<<"-"<<endl;

LI ind=-1;

for(LI i=L.size()-1; i>=0;i--){
    if(L[i]==LisLength) {ind=i; break;}
}

vector<LI> ans;
ans.push_back(sequence[ind]);
LI i=ind-1;

while(i>=0){
    if(L[i]==L[ind]-1 && sequence[i]<sequence[ind]){
      ans.push_back(sequence[i]);
      ind = i;
    }
    i--;
}

for(i=ans.size()-1;i>=0;i--) cout<<ans[i]<<endl;

return 0;
}
