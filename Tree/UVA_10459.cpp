#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<queue>
#define MAX 5050
using namespace std;

vector<int> tree[MAX], worst, best;
int diameter, end_node, min_height, min_height1, min_height2;
int N, child, val, d[MAX], degree[MAX], degree2[MAX];
bool visited[MAX], end_node_found, best_roots[MAX], worst_roots[MAX];
bool printed[MAX];

void print_best(){
    cout<<"Best Roots  : ";
    sort(best.begin(),best.end());
    for(int i=0; i<best.size()-1; i++){
            cout<<best[i]<<" ";
    }
    cout<<best[best.size()-1]<<endl;
}

void print_worst(){
    cout<<"Worst Roots : ";
    sort(worst.begin(),worst.end());
    for(int i=0; i<worst.size()-1; i++){
            cout<<worst[i]<<" ";
    }
    cout<<worst[worst.size()-1]<<endl;
}


void init(){
    for(int i=1; i<=N; i++) {
       visited[i] = false ;
       best_roots[i] = false;
       d[i]=0;
    }
}

int _max(int a, int b){ return ( a >= b ? a : b ); }

void dfs(int u){

    visited[u] = true;
    int v;

    for(int i=0; i<tree[u].size();i++){
        v = tree[u][i];
        if(!visited[v]){
            d[v] = d[u] + 1;
            diameter = _max(diameter,d[v]);
            dfs(v);
        }
    }

    if(!end_node_found){
        end_node_found = true;
        end_node = u;
    }
}

void dfs2(int u, int depth){
    visited[u] = true;
    //if( diameter%2!=0 && degree2[u]==1 && depth>min_height && !worst_roots[u]) {worst.push_back(u);worst_roots[u]=true;};
    //if( diameter%2==0 && degree2[u]==1 && depth==min_height && !worst_roots[u]) {worst.push_back(u);worst_roots[u]=true;};
    if( degree2[u]==1 && depth < min_height) {worst_roots[u]=false;};
    for(int i=0; i<tree[u].size();i++)
        if(!visited[ tree[u][i] ]) dfs2(tree[u][i],depth+1);
}


int main(){
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
while(cin>>N){

    diameter = -1;

    worst.clear();
    best.clear();

    for(int i=1; i<=N; i++) {degree[i]=0; degree2[i]=0; tree[i].clear(); }

    queue<int> Q, QQ;

    for(int u=1; u<=N; u++){
        cin>>child;

        if(child==1) Q.push(u);

        degree[u] = child;
        degree2[u] = child;
        for(int i=1; i<=child; i++){
            cin>>val;
            tree[u].push_back(val);
        }
    }
    /*
    if(N==2){
        cout<<"Best Roots  : 1 2"<<endl;
        cout<<"Worst Roots : 1 2"<<endl;
        continue;
    }*/

    init();
    end_node_found = false;
    for(int i=1; i<=N; i++) if(degree[i]>0) { dfs(i); break; }
    init();
    dfs(end_node);

    //cout<<"diameter : "<<diameter<<endl;
    //cout<<"end_node : "<<end_node<<endl;
    if(diameter%2==0) min_height = diameter/2;
    else min_height = diameter/2 + 1;
    //min_height = diameter/2;
    //cout<<"min_height : "<<min_height<<endl;
    init(); // init() call for BFS and dfs2() execution

    for(int i=1; i<=N; i++) best_roots[i] = false;

    //cout<<"----------------------"<<endl;
    while(!Q.empty()){
        int uu = Q.front(); Q.pop();
        //cout<<uu<<" ";
        QQ.push(uu);
    }
    //cout<<endl<<"----------------------"<<endl;

    while(!QQ.empty()){
        int uu = QQ.front(); QQ.pop();
        int vv;
        degree[uu]--;
        for(int i=0; i<tree[uu].size();i++){
                vv = tree[uu][i];
                if(degree[vv]<=0) continue;
                //if(degree[vv]>1){
                degree[vv]--;
                d[vv] = _max(d[vv],d[uu]+1);
                if(degree[vv]==1) QQ.push(vv);
                if( d[vv]>=min_height && !best_roots[vv]) { best.push_back(vv); best_roots[vv]=true; }
                //}

            }

    }

    for(int i=1; i<=N; i++) worst_roots[i] = true;
    min_height = diameter/2;

    for(int i=0; i<best.size();i++){
        init();
        dfs2(best[i],0);
    }

    for(int i=1; i<=N; i++)
        if(degree2[i]==1 && worst_roots[i]) worst.push_back(i);

    print_best();
    print_worst();
}

return 0;
}
