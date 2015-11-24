//ACCEPTED!!!
#include<iostream>
#include<stdio.h>
using namespace std;

struct car{
    int len;
    string dir;
};

int main(){

int T, len, L, M;
string dir;
car arr_left[100000] , arr_right[100000];

int left_start = 0, left_end = 0, right_start = 0, right_end = 0, leftTotal, rightTotal, sum;

//freopen("in.txt","r",stdin);

    cin>>T;

    for(int t=1; t<=T; t++){

    cin>>L>>M;


    left_start = 0;
    left_end = 0;
    right_start = 0;
    right_end = 0;

    for(int i=1; i<=M; i++){
        cin>>len>>dir;
        //cout<<len<<" --- "<<dir<<endl;
        car ob;
        ob.len = len;
        ob.dir = dir;

        if(dir=="left"){
            arr_left[left_end] = ob;
            left_end++;
        }
        else{
            arr_right[right_end] = ob;
            right_end++;
        }
    }

    //cout<<left_end<<" "<<right_end<<endl;
    int now = 0, ans=0;
    L = L*100;

    while(1){

        if(now==0){
            sum = 0;
            while(left_end>0){
                if( sum + arr_left[left_end-1].len <=L )
                    {sum = sum + arr_left[left_end-1].len;left_end--;}
                else break;
            }
            ans++;
        }

        else{
            sum = 0;
            while(right_end>0){
                if(sum + arr_right[right_end-1].len<=L)
                {sum = sum + arr_right[right_end-1].len; right_end--;}
                else break;
            }
            ans++;
        }

    if(left_end<=0 && right_end<=0) break;
    now = now^1;

    }

    cout<<ans<<endl;
    }


return 0;
}
