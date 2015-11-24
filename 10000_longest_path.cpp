//ACCEPTED!!!
#include<stdio.h>

int arr[101][101], Q[101], d[101], start, finish;

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

int main(){

int N, s, t, u, v, i, j, k;
t=1;

while(scanf("%d",&N)==1){

    if(N==0) break;

    scanf("%d",&s);

    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++){
            arr[i][j] = 0;
            d[i] = 0;
        }



    while(scanf("%d %d",&u,&v)==2){
        if(u==0&&v==0) break;
        arr[u][v] = 1;
    }

    d[s]=0;
    start = 0;
    finish = 0;
    EnQ(s);

    while(Q_Empty()==0){
        u = DeQ();

        for(v=1; v<=N; v++){

            if(arr[u][v]==1 ){

                if(d[u]+1>d[v]){
                d[v] = d[u] + 1;
                EnQ(v);
                //printf("u = %d d[u] = %d v = %d d[v] = %d\n",u,d[u],v,d[v]);
                }

            }
        }
    }

        int ind = 0, m = 0;
        for(i=1;i<=N;i++) {
            if(d[i]>m){
                m = d[i];
                ind = i;
            }
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",t++,s,d[ind],ind);
        printf("\n");
    }



return 0;
}
