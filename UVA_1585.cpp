//ACCEPTED!!!
#include<bits/stdc++.h>
using namespace std;
int main(){

int T;

cin >> T;

for(int t = 1; t <= T; t++){
    string str;
    cin >> str;
    int len = str.size();
    int cur_sum = 0;
    int score = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == 'X')
            cur_sum = 0;
        else{
            cur_sum += 1;
            score += cur_sum;
        }
    }
    cout << score << endl;
}
return 0;
}
