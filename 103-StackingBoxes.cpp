/*
UVA-103 Stacking Boxes
Type: DFS,Graph
Difficulty: Easy
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int N, D, ans;
int arr[32][12];
int visited[32];
int graph[32][32];
int st[32];
int ans_arr[32];
int ind, ans_ind=0;

void save(){
    for(int i=0; i<=ind; i++)
        ans_arr[i]=st[i];
    ans_ind = ind;
}

void push(int val){
    ind++;
    st[ind]=val;
}

void pop(){
//    int val = st[ind];
    ind--;
    //return val;
}

bool check(int i, int j){
    for(int d=0; d<D; d++)
        if(arr[i][d]>=arr[j][d]) return false;
    return true;
}

void dfs(int cur, int tot){
    if(tot>ans) save();
    ans = max(tot,ans);

    visited[cur]=1;

    for(int i=0; i<N; i++)
    {
        if(graph[cur][i]==1&&!visited[i]){
            push(i);
            dfs(i,tot+1);
            visited[i]=0;
            pop();
        }
    }

    visited[cur]=0;
    return;
}


int main(){

while(cin>>N>>D){

    memset(graph,0,sizeof(graph));
    memset(visited,0,sizeof(visited));

    for(int i=0; i<N; i++)
            for(int j=0; j<D; j++)
                cin>>arr[i][j];

    for(int i=0; i<N; i++)
        sort(arr[i],arr[i]+D);
    /*
    cout<<"After Sorting..."<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<D; j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<"---------------------"<<endl;
    */
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(i!=j&&check(i,j))
                graph[i][j]=1;

    /*
    cout<<"The graph..."<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cout<<graph[i][j]<<" ";
        cout<<endl;
    }
    cout<<"---------------------"<<endl;
    */
    ans = -1;
    ind = -1;
    for(int i=0; i<N; i++) {
            push(i);
            dfs(i,1);
            pop();
    }
    cout<<ans<<endl;
    //cout<<"ans index: "<<ans_ind<<endl;
    for(int i=0; i<=ans_ind; i++){
        cout<<ans_arr[i]+1<<" ";
        //if(i<ans_ind) cout<<" ";
    }
    cout<<endl;
}

return 0;
}

