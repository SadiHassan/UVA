#include<bits/stdc++.h>
using namespace std;

int main(){

int N;
int T = 1;
while(cin >> N){

    if(N == 0) break;
    if(T > 1) cout << endl;
    string cur;
    string prev = "";

    char last_char = '.';
    vector<string> ans;

    for(int i = 0; i < N; i++){
        cin >> cur;
        if(prev == ""){
            ans.push_back(cur);
            prev = cur;
        }
        else if( atoi(cur.c_str()) - 1 == atoi(prev.c_str()) ){
            last_char = cur[cur.size() - 1];
            cout << last_char << endl;
            prev = cur;
        }
        else {
            if(last_char != '.'){
                int len = ans.size();

                ans[len-1] += "-";
                ans[len-1] += last_char;

                last_char = '.';

                //cout << cur << endl;
            }
            ans.push_back(cur);
            prev = cur;
            //cout << endl;
        }

    }

    if(last_char != '.'){
        int len = ans.size();
        //cout << ans[len - 1] << endl;
        ans[len-1] += "-";
        ans[len-1] += last_char;
    }
    cout << "Case " << T << ":" << endl;
    T++;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

}

return 0;
}
