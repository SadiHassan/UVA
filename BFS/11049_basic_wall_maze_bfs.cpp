//ACCEPTED!!!
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int val(int r, int c){ return ( (r-1)*6 + c ) ; }
int get_row(int val) { val--; return ( (val/6) + 1);}
int get_col(int val) { val--; return ( (val%6) + 1);}

int parent[50];

void print_path(int val){

    if(parent[val]==-1) return;

    print_path(parent[val]);

    int diff = parent[val] - val;
    if(diff==1) printf("W");
    else if(diff==-1) printf("E");
    else if(diff==-6) printf("S");
    else printf("N");


    return;
}

int main(){

int start_col, start_row, end_col, end_row, r1, c1, r2, c2, i, j, t, S, E;
int arr[50][50];

while(scanf("%d %d",&start_col,&start_row)==2){

    if(start_col==0&&start_row==0) break;
    scanf("%d %d",&end_col,&end_row);

    memset(arr,0,sizeof(arr));

    for(t=1;t<=3;t++){

        scanf("%d %d",&c1,&r1);
        scanf("%d %d",&c2,&r2);

        if(c1==c2&&c1!=0&&c1!=6){
            while(++r1<=r2) {
                    arr[val(r1,c1)][val(r1,c1+1)] = 1;
                    arr[val(r1,c1+1)][val(r1,c1)] = 1;
            }
        }else if(r1==r2&&r1!=0&&r1!=6){
            while(++c1<=c2) {
                    arr[val(r1,c1)][val(r1+1,c1)] = 1;
                    arr[val(r1+1,c1)][val(r1,c1)] = 1;
            }
        }
    }

    S = val(start_row,start_col);
    E = val(end_row, end_col);

    int d[50];
    int u, v, r, c;

    memset(d,0,sizeof(d));
    memset(parent,0,sizeof(parent));
    queue<int> Q;
    Q.push(S);
    parent[S] = -1;


    while(!Q.empty()){

        u = Q.front(); Q.pop();

        r = get_row(u);
        c = get_col(u);

        if(r-1>0){
            v = val(r-1,c);

            if(arr[u][v]==0 && d[v]==0 && v!=S){
                d[v] = d[u] + 1;
                Q.push(v);
                parent[v] = u;

                //printf("v : %d %d\n",v,d[v]);
            }
        }
        if(r+1<7){
            v = val(r+1,c);

            if(arr[u][v]==0 && d[v]==0 && v!=S){
                d[v] = d[u] + 1;
                Q.push(v);
                parent[v] = u;

                //printf("v : %d %d\n",v,d[v]);
            }
        }
        if(c-1>0){
            v = val(r,c-1);

            if(arr[u][v]==0 && d[v]==0 && v!=S){
                d[v] = d[u] + 1;
                Q.push(v);
                parent[v] = u;

                //printf("v : %d %d\n",v,d[v]);
            }
        }

        if(c+1<7){
            v = val(r,c+1);

            if(arr[u][v]==0 && d[v]==0 && v!=S){
                d[v] = d[u] + 1;
                Q.push(v);
                parent[v] = u;

                //printf("v : %d %d\n",v,d[v]);
            }
        }

        if(d[E]!=0) break;
    }

    //printf("%d\n",d[E]);
    print_path(E);
    printf("\n");
}

return 0;
}

