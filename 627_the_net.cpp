//ACCEPTED!!!
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int routing_table[300+10][300+10], Total_Router, start, finish , Q[300+10], parent[300+10], gontobbo;


void EnQ(int val){
    Q[finish] = val;
    finish++;
}

int DeQ(){
    int temp = Q[start];
    start++;
    return temp;
}

int Q_Empty(){ if(start>=finish) return 1; return 0; }

int bfs(int source, int dest){

    int u, v;
    int d[300+10] , visited[300+10];
    for(int i=0;i<305;i++) {d[i] = 10000; visited[i] = 0;}


    d[source] = 0;
    parent[source] = -1;
    visited[source] = 1;
    EnQ(source);

    while(Q_Empty()==0){

        u = DeQ();

        for(v=1; v<=Total_Router; v++){

            if(routing_table[u][v]==1&&visited[v]==0){
                d[v] = d[u] + 1;
                visited[v] = 1;
                parent[v] = u;
                EnQ(v);
            }

        }
    }
    return d[dest];
}

void print(int me){
    if(me==-1) return;
    print(parent[me]);
    printf("%d",me);
    if(me!=gontobbo) printf(" ");

}

int main(){

int i, j, n, m, query;
char dash, str[1000];
char* p;

while(scanf("%d",&Total_Router)==1){

    getchar();

    for(i=0;i<305;i++) for(j=0;j<305;j++) routing_table[i][j] = 0;

    for(i=0;i<Total_Router;i++){

        gets(str);
        p =strtok(str,"-");
        n = atoi(p);
        while(p){
                   m = atoi(p);
                   p = strtok(NULL,",");
                   routing_table[n][m] = 1;
                }
    }

    printf("-----\n");
    scanf("%d",&query);
    int u, v , ans;

    for(int q=1;q<=query;q++){
        scanf("%d %d",&u,&v);
        gontobbo = v;
        start=0;
        finish=0;
        ans = bfs(u,v);
        if(ans>=10000) printf("connection impossible");
        else print(v);
        printf("\n");
    }

}

return 0;
}
