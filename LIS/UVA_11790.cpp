#include<iostream>
#include<vector>

#define LI long int
using namespace std;

LI t, T, N, Lis_Len, Lds_Len;
vector<LI> height, weight;

int main(){

cin>>T;
LI temp_height, temp_weight;

for(t=1;t<=T;t++){
    cin>>N;
    for(LI i=0; i<N; i++){ cin>>temp_height; height.push_back(temp_height); }
    for(LI i=0; i<N; i++){ cin>>temp_weight; weight.push_back(temp_weight); }
}

return 0;
}
