#include<iostream>
#include<vector>
#include<string.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

vector <int> arr[100];
int N, M, x, y, timer, entry[100], exit[100];
int visited[100];

void dfs(int u){
    entry[u] = timer;
    visited[u] = GRAY;
    timer++;
    for(int i=0; i<arr[u].size();i++){
        int v = arr[u][i];
        if(visited[v]==WHITE)
            dfs(v);
    }
    exit[u] = timer;
}


int main(){

while(cin>>N>>M){
    memset(visited,WHITE,sizeof(visited));
    for(int i=1; i<=M; i++){
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    timer = 0;
    dfs(1);
    for(int i=1; i<=N; i++) cout<<i<<" entry : "<<entry[i]<<" exit : "<<exit[i]<<endl;
}

return 0;
}
