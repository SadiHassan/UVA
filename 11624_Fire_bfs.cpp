//ACCEPTED!!!
#include<stdio.h>
#include<string.h>

static long int R, C, T, Q[1000010], QQ[1000010], temp[1000010], visited[1010][1010], start, finish, sstart, ffinish;
static long int d[1000010];
char str[1010][1010];

long int get_val(long int r, long int c){ return (r*C + c) ; }
long int get_row(long int node){ return node/C ; }
long int get_col(long int node){ return node%C ; }

void EnQ(long int val){
    Q[finish] = val;
    finish++;
}

long int DeQ(){
    long int temp = Q[start];
    start++;
    return temp;
}

int Q_Empty(){ if(start>=finish) return 1; return 0; }

void EnQQ( long int val){
    QQ[ffinish] = val;
    ffinish++;
}

long int DeQQ(){
    long int temp = QQ[sstart];
    sstart++;
    return temp;
}

long int QQ_Empty(){ if(sstart>=ffinish) return 1; return 0; }


void spread_fire(){

    long int ind=0, cur_fire_node, cur_fire_r, cur_fire_c, i;

    while(QQ_Empty()==0){

        cur_fire_node = DeQQ();
        cur_fire_r = get_row(cur_fire_node);
        cur_fire_c = get_col(cur_fire_node);

        if(cur_fire_r-1>=0){
            if(str[cur_fire_r-1][cur_fire_c]=='.'){
                str[cur_fire_r-1][cur_fire_c] = 'F';
                temp[ind++] = get_val(cur_fire_r-1,cur_fire_c);
            }
        }

        if(cur_fire_r+1<=R-1){
            if(str[cur_fire_r+1][cur_fire_c]=='.'){
                str[cur_fire_r+1][cur_fire_c] = 'F';
                temp[ind++] = get_val(cur_fire_r+1,cur_fire_c);
            }
        }

        if(cur_fire_c-1>=0){
            if(str[cur_fire_r][cur_fire_c-1]=='.'){
                str[cur_fire_r][cur_fire_c-1] = 'F';
                temp[ind++] = get_val(cur_fire_r,cur_fire_c-1);
            }
        }

        if(cur_fire_c+1<=C-1){
            if(str[cur_fire_r][cur_fire_c+1]=='.'){
                str[cur_fire_r][cur_fire_c+1] = 'F';
                temp[ind++] = get_val(cur_fire_r,cur_fire_c+1);
            }
        }
    }

    for(i=0;i<ind;i++) EnQQ(temp[i]);

}


int main(){

long int t , i , j, fire_init, joe_init;

scanf("%ld",&T);

for(t=1; t<=T; t++){

    scanf("%ld %ld",&R,&C);
    getchar();

    sstart = 0;
    ffinish = 0;

    start = 0;
    finish = 0;

    memset(visited,0,sizeof(visited));
    memset(d,1000010,sizeof(d));

    for(i=0;i<R;i++){
        for(j=0;j<C;j++)
            {
                scanf("%c",&str[i][j]);
                if(str[i][j]=='F'){
                    EnQQ(get_val(i,j));
                }
                if(str[i][j]=='J'){
                    joe_init = get_val(i,j);
                    d[joe_init] = 1;
                    visited[i][j] = 1;
                    str[i][j]='.';
                }
            }
        getchar();
    }

    if(get_row(joe_init)==0||get_row(joe_init)==R-1||get_col(joe_init)==0||get_col(joe_init)==C-1){
        printf("1\n");
        continue;
    }

    d[joe_init] = 1;
    EnQ(joe_init);

    long int ind=0, cur_node, cur_r, cur_c, v, ans=-1;

    while(1){

        if(Q_Empty()==1 || ans!=-1) break;
        spread_fire();

        ind = 0;
        while(Q_Empty()==0){
              cur_node = DeQ();
              cur_r = get_row(cur_node);
              cur_c = get_col(cur_node);

              if(cur_r-1>=0){
                    if(str[cur_r-1][cur_c]=='.'&&visited[cur_r-1][cur_c]==0){
                        visited[cur_r-1][cur_c] = 1;
                        temp[ind++] = get_val(cur_r-1,cur_c);
                        v = get_val(cur_r-1,cur_c);
                        d[v] = d[cur_node] + 1;
                        if(cur_r-1==0) ans = d[v];
                    }
              }

              if(cur_r+1<=R-1){
                    if(str[cur_r+1][cur_c]=='.'&&visited[cur_r+1][cur_c]==0){
                        visited[cur_r+1][cur_c] = 1;
                        temp[ind++] = get_val(cur_r+1,cur_c);
                        v = get_val(cur_r+1,cur_c);
                        d[v] = d[cur_node] + 1;
                        if(cur_r+1==R-1) ans = d[v];
                    }
              }

              if(cur_c-1>=0){
                    if(str[cur_r][cur_c-1]=='.'&&visited[cur_r][cur_c-1]==0){
                        visited[cur_r][cur_c-1] = 1;
                        temp[ind++] = get_val(cur_r,cur_c-1);
                        v = get_val(cur_r,cur_c-1);
                        d[v] = d[cur_node] + 1;
                        if(cur_c-1==0) ans = d[v];
                    }
              }

              if(cur_c+1<=C-1){
                    if(str[cur_r][cur_c+1]=='.'&&visited[cur_r][cur_c+1]==0){
                        visited[cur_r][cur_c+1] = 1;
                        temp[ind++] = get_val(cur_r,cur_c+1);
                        v = get_val(cur_r,cur_c+1);
                        d[v] = d[cur_node] + 1;
                        if(cur_c+1==C-1) ans = d[v];
                    }
              }

            if(ans!=-1) break;
        }

        if(ans!=-1) break;
        for(i=0;i<ind;i++) EnQ(temp[i]);

    }

if(ans==-1) printf("IMPOSSIBLE\n");
else printf("%ld\n",ans);

}

return 0;
}

