//ACCEPTED!!!
#include<iostream>
#include<vector>
using namespace std;
int M, N;
vector<string> str;
vector<string> path;
string key = "IEHOVA";


void rec(int col, int row, int ind){

    if(col-1>=0){
        if(ind==6){
            if(str[row][col-1]=='#'){
                path.push_back("left");
                return;
            }
        }
        else if(str[row][col-1]==key[ind]){
            path.push_back("left");
            rec(col-1,row,ind+1);
        }

    }

    if(col+1<=N-1){
        if(ind==6){
            if(str[row][col+1]=='#'){
                path.push_back("right");
                return;
            }
        }
        else if(str[row][col+1]==key[ind]){
            path.push_back("right");
            rec(col+1,row,ind+1);
        }
    }

    if(row-1>=0){
        if(ind==6){
            if(str[row-1][col]=='#'){
                path.push_back("forth");
                return;
            }
        }
        else if(str[row-1][col]==key[ind]){
            path.push_back("forth");
            rec(col,row-1,ind+1);
        }
    }
}



int main(){

int T, j;
string temp;

cin>>T;

for(int t=1;t<=T; t++){
   cin>>M>>N;
   for(int i=0; i<M; i++){
        cin>>temp;
        str.push_back(temp);
   }

for(j=0;j<N;j++)
        if(str[M-1][j]=='@') break;

rec(j,M-1,0);

for(int i=0; i<path.size();i++){
    cout<<path[i];
    if(i!=path.size()-1) cout<<" ";
}
cout<<endl;
str.clear();
path.clear();
}

return 0;
}