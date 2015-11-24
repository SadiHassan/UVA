//ACCEPTED!!! easy
#include<iostream>
#include<stdio.h>
using namespace std;
string str[10], commands, temp;

void swp(int r1, int c1, int r2, int c2){
    char ch;
    ch = str[r1][c1];
    str[r1][c1] = str[r2][c2];
    str[r2][c2] = ch;
}


int main(){


bool last_one=false , valid;
int R, C, t=1;

while(1){

    for(int i=0;i<5;i++){
       getline(cin,str[i]);
       if(str[i]=="Z"){
            last_one = true;
            break;
        }
    }
    if(last_one) break;

    valid = true;

    commands = "";

    while(getline(cin,temp)){
        commands += temp;
        if(temp[temp.size()-1]=='0') break;
    }
    R=-1; C=-1;
    for(int i=0; i<5;i++){
        for(int j=0; j<5; j++){
            if(str[i][j]==' '){
                R = i;
                C = j;
                break;
            }
        }
    if(R!=-1) break;
    }

    for(int i=0; i<commands.size(); i++){
        if(commands[i]=='A'){
            if(R-1>=0) {swp(R-1,C,R,C);R--;}
            else valid = false;
        }
        else if(commands[i]=='B'){
            if(R+1<=4) {swp(R+1,C,R,C);R++;}
            else valid = false;
        }
        else if(commands[i]=='L'){
            if(C-1>=0) {swp(R,C-1,R,C);C--;}
            else valid = false;
        }
        else if(commands[i]=='R'){
            if(C+1<=4) {swp(R,C+1,R,C);C++;}
            else valid = false;
        }

        if(!valid) break;
    }

if(t>1) cout<<endl;
cout<<"Puzzle #"<<t++<<":"<<endl;

if(!valid){
    cout<<"This puzzle has no final configuration."<<endl;
    continue;
}

for(int i=0; i<5; i++){
    for(int j=0;j<4;j++) cout<<str[i][j]<<" ";
    cout<<str[i][4]<<endl;
}

}

return 0;
}