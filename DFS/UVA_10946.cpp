/* ACCEPTED!!!
Note: I was getting WA because of this line in the comp() function
      "return ( a.ch <= b.ch );" . I changed this into "return ( a.ch < b.ch );" and got AC
      Donno why.... :Osss
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int N, M;

struct bostu{
    int val;
    char ch;
};

vector<bostu> arr;
vector<string> str;
bool visited[52][52];
int tot;

void dfs(int r, int c, char ch){
    visited[r][c] = true;
    tot++;
    if(r-1>=0){
        if( str[r-1][c] == ch && !visited[r-1][c]) dfs( r-1, c ,ch );
    }
    if(r+1<N){
        if(str[r+1][c]==ch && !visited[r+1][c]) dfs(r+1,c,ch);
    }
    if(c-1>=0){
        if(str[r][c-1]==ch && !visited[r][c-1]) dfs(r,c-1,ch);
    }
    if(c+1<M){
        if(str[r][c+1]==ch && !visited[r][c+1]) dfs(r,c+1,ch);
    }
}

bool comp(bostu a, bostu b){
    if(a.val==b.val) return ( a.ch < b.ch );
    return ( a.val > b.val );
}

int main(){

//freopen("10946in.txt","r",stdin);
//freopen("10946out.txt","w",stdout);
string temp;
int t=1;

while(cin>>N>>M){

    if(N==0&&M==0) break;

    for(int i=0; i<N; i++) for(int j=0; j<M; j++) visited[i][j] = false;

    for(int i=0; i<N; i++){
        temp = "";
        cin>>temp;
        str.push_back(temp);
    }

    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        if( !visited[i][j] &&  str[i][j] != '.' )
            {
                tot = 0;
                dfs(i,j,str[i][j]);

                bostu ob ;
                ob.val = tot;
                ob.ch = str[i][j];

                arr.push_back(ob);
            }
    }

    sort(arr.begin(),arr.end(),comp);
    cout<<"Problem "<<t++<<":"<<endl;

    for(int i=0; i<arr.size();i++)
        cout<<arr[i].ch<<" "<<arr[i].val<<endl;
    arr.clear();
    str.clear();
}


return 0;
}
