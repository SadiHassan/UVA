//ACCEPTED!!!
#include<iostream>
#define ULI unsigned long int
#define MAX 0
#define MIN 1
using namespace std;

ULI arr[100001], leftt[100001], rightt[100001], N, S, now_min, now_max;

ULI _min(ULI a, ULI b){ if(a<=b) return a; return b; }
ULI _max(ULI a, ULI b){ if(a>=b) return a; return b; }

void window(ULI k){
    ULI mx=0, mn=100000001;

    for(ULI i=k-1; i<N; i++){

            if(i-k>=0){
                mx = _max( mx , (leftt[i]-leftt[i-k]) );
                mn = _min( mn , (leftt[i]-leftt[i-k]) );
            }
            else{
                mx = _max( mx , leftt[i] );
                mn = _min( mn , leftt[i] );
            }

            //mx = _max( mx , (rightt[i]-rightt[i+k]) );
            //mn = _min( mn , (rightt[i]-rightt[i+k]) );
        }

    now_max = mx;
    now_min = mn;
    //cout<<mx<<" "<<mn<<endl;
    //return a;
}

int main(){

long int ans;

while(cin>>N>>S){

    cin>>arr[0];
    leftt[0] = arr[0];

    for(ULI i=1; i<N; i++){
        cin>>arr[i];
        leftt[i] = leftt[i-1] + arr[i];
    }

    rightt[N-1] = arr[N-1];

    for(long int i=N-2; i>=0; i--)
        rightt[i] = rightt[i+1] + arr[i];


    ULI* m;
    ULI* l;
    ULI* h;
    ULI low=1, high=N, mid, low_min, low_max, high_min, high_max, mid_min, mid_max, ans = 100000001;
    //cout<<a[0]<<" "<<a[1]<<endl;

    while(low<=high){

    //cout<<low<<" "<<high<<" --> ";

        low_min = 100000001;
        low_max = 0;

        high_min = 100000001;
        high_max = 0;

        mid_min = 100000001;
        mid_max = 0;

        mid = (low + high)/2;

        window(low);
        low_min = now_min;
        low_max = now_max;

        window(high);
        high_min = now_min;
        high_max = now_max;

        window(mid);
        mid_min = now_min;
        mid_max = now_max;


        //if(l[MIN]>=S||l[MAX]>=S){
        if( low_min>=S || low_max>=S ){
            ans = _min(ans,low);
            //cout<<low_min<<" "<<low_max<<endl;
            //cout<<"aaa : "<<low<<" "<<high<<" "<<mid<<" "<<ans<<endl;
            break;
        }
        //else if(m[MIN]>=S||m[MAX]>=S){
        else if(mid_min>=S || mid_max>=S){
            ans = _min(ans,mid);
            high = mid - 1;
            //cout<<"bbb : "<<low<<" "<<high<<" "<<mid<<" "<<ans<<endl;
        }
        else if(mid_max<S){
            low = mid + 1;
            //cout<<"ccc : "<<low<<" "<<high<<" "<<mid<<" "<<ans<<endl;
        }

    }

    if(ans==100000001) ans=0;
    cout<<ans<<endl;
}


return 0;
}
