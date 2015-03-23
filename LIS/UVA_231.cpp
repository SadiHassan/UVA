//ACCEPTED!!! LIS
#include<iostream>
#include<vector>
using namespace std;
int inf = 50000;

vector<int> sequence, I, arr;
int test=1;

int LisNlogK() {

    I.push_back(inf*(-1));

    int n = sequence.size();

    for( int i = 1; i <= n; i++ ) I.push_back(inf);

    //for(int i=0; i<=n; i++) cout<<I[i]<<" ";
    //cout<<endl;

    int LisLength = 0;

    for(int i = 0; i < n; i++ ) {
        //cout<<"LisLength : "<<i<<" : "<<LisLength<<endl;
        int low, high, mid;
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
        //cout<<low<<" : "<<I[low]<<endl;
        if( LisLength < low ) LisLength = low;
    }

    I.clear();

    return LisLength;
}

void process(){

    for(int i=arr.size()-1; i>=0;i--) sequence.push_back(arr[i]);

    cout<<"Test #"<<test++<<":"<<endl;
    cout<<"  maximum possible interceptions: "<<LisNlogK()<<endl;
    //for(int i=0; i<sequence.size();i++) cout<<sequence[i]<<" ";
    //cout<<endl;
    sequence.clear();
    arr.clear();

}


int main(){

int val, minus_one=0, first=1;

while(cin>>val){
    if(val==-1) minus_one++;
    else {
            arr.push_back(val);
            minus_one=0;
    }

    if(minus_one==1) {
            if(first==0) cout<<endl;
            process();
            if(first==1) first=0;
    }
    else if(minus_one==2) break;

}

return 0;
}