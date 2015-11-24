//ACCEPTED!!!
#include<stdio.h>

int arr[10][10], r, c, sol;

int my_abs(int val){ if(val<0) return (val*(-1)) ;  return val; }

void init(){
    int i, j;
    for(i=1; i<=8; i++) for(j=1; j<=8; j++) arr[i][j] = 0;
}

int check_pos(int r1, int c1, int r2, int c2){
    if(r1==r2||c1==c2) return 0;
    if( my_abs(r1-r2)==my_abs(c1-c2)) return 0;
    return 1;
}

int check(int row, int col){
    int i,j;

    for(i=1;i<=8;i++)
    for(j=1;j<=8;j++){
        if(arr[i][j]==1){
            if(check_pos(row,col,i,j)==0)   return 0;
        }
    }
    return 1;
}

void print(){

    int i, j;
    if(sol/10==0) printf(" ");
    printf("%d      ",sol++);
    for(j=1;j<=8;j++){
        for(i=1; i<=8; i++){
            if(arr[i][j]==1) {
                    printf("%d",i);
                    if(j!=8) printf(" ");
                    break;
            }
        }

    }
    printf("\n");

}

void rec(int col){

    int i, j;

    if(col==9){
        print();
        return;
    }

    if(col==c) rec(col+1);

    for(i=1;i<=8;i++){
            if(arr[i][col]==0&&check(i,col)==1){

                arr[i][col]=1;
                rec(col+1);
                arr[i][col]=0;
            }
        }

return;
}

int main(){

    int T, t;

    scanf("%d",&T);
    for(t=1; t<=T; t++){
        scanf("%d %d",&r,&c);
        init();
        arr[r][c] = 1;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        sol=1;
        rec(1);
        if(t<T) printf("\n");
    }

    return 0;
}
