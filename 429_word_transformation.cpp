//ACCEPTED!!!
#include<stdio.h>
#include<string.h>

int T, ind, graph[210][210], start, finish , Q[300];
char s[500],  inp[500], source[200], dest[200];
char str[300][50];
char* p, q;

void EnQ(int val){
    Q[finish] = val;
    finish++;
}

int DeQ(){
    int temp = Q[start];
    start++;
    return temp;
}

int Q_Empty(){ if(start>finish) return 1; return 0; }

int checkDiff(char* p, char* q){

    int i, j, tot=0;

    if(strlen(p)!=strlen(q)) return 0;


    for(i=0;i<strlen(p);i++){
        if(p[i]!=q[i]) tot++;
        if(tot>1) return 0;
    }

    if(tot==1) return 1;

}
void make_graph(){
    int i,j;
    for(i=0;i<ind;i++)
    for(j=i+1;j<ind;j++){
        if(checkDiff(str[i],str[j])==1)
                {
                    //printf("--> %s %s\n",str[i],str[j]);
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }

    }
}

int get_index(char* p){
    int i;
    for(i=0;i<ind;i++) if( strcmp(p,str[i])==0 ) return i;
    return -1;
}

int bfs(char* p, char* q){
    int d[300], u, v;
    int visited[300];

    memset(d,1000,sizeof(d));
    memset(visited,0,sizeof(visited));

    int s = get_index(p);
    int dest = get_index(q);


    d[s] = 0;
    visited[s] = 1;
    EnQ(s);


    while(Q_Empty()==0){
        u = DeQ();
        for(v=0; v<ind; v++){

            if(graph[u][v]==1&&visited[v]==0){
                d[v] = d[u] + 1;
                visited[v] = 1;
                EnQ(v);
            }
        }
    }

    return d[dest];

}
