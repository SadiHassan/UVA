//ACCEPTED!!!
/*
Took help from this link --> https://belbesy.wordpress.com/2011/08/12/uva-11790-murcias-skyline-2/
*/
#include<iostream>
#include<vector>
#include<stdio.h>
#define LI long int
using namespace std;

LI t, T, N, Lis_Len, Lds_Len, INC, DEC, temp_height, temp_weight;
vector<LI> height, weight, DP1, DP2;

LI _max(LI a, LI b){ return ( a>=b ? a : b ); }

int main(){

//freopen("11790in.txt","r",stdin);
//freopen("11790out2.txt","w",stdout);

cin>>T;

for(t=1;t<=T;t++){
    cin>>N;
    for(LI i=0; i<N; i++){ cin>>temp_height; height.push_back(temp_height); }
    for(LI i=0; i<N; i++){
            cin>>temp_weight;
            weight.push_back(temp_weight);
            DP1.push_back(0);
            DP2.push_back(0);
        }
    //DP1[0]=weight[0];
    //DP2[0]=weight[0];

    for(LI i=0; i<N; i++){
        DP1[i] = weight[i];
        for(LI j=0; j<i; j++){
            if(height[i]>height[j])
                DP1[i] = _max( DP1[i] , DP1[j]+weight[i]);

        }
    }

    for(LI i=0; i<N; i++){
        DP2[i] = weight[i];
        for(LI j=0; j<i; j++){
            if(height[i]<height[j])
                DP2[i] = _max( DP2[i] , DP2[j]+weight[i]);

        }
    }

    //INC = (LI) max_element( DP1 , DP1 + DP1.size() );
    //DEC = (LI) max_element( DP2 , DP2 + DP2.size() );
    INC = 0;
    DEC = 0;
    for(LI i=0; i<DP1.size();i++){
        INC = _max(DP1[i],INC);
        DEC = _max(DP2[i],DEC);
    }

    cout<<"Case "<<t<<". ";
    if(INC>=DEC)
        cout<<"Increasing ("<<INC<<"). Decreasing ("<<DEC<<")."<<endl;
    else
        cout<<"Decreasing ("<<DEC<<"). Increasing ("<<INC<<")."<<endl;

    height.clear();
    weight.clear();
    DP1.clear();
    DP2.clear();
    }

return 0;
}
