//ACCEPTED!!!
#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<map>
using namespace std;

string add(string str1, string str2){
    string temp="", out="";
    char ch;
    int carry = 0, sum=0;
    for(int i=str1.size()-1; i>=0; i--){
        sum = str1[i]-48 + str2[i] - 48 + carry;
        carry = sum/10;
        ch = '0' + (sum%10);
        temp = temp + ch;
    }
    //if(carry>0) return "OVERFLOW";
    for(int i=str1.size()-1;i>=0; i--) out += temp[i];
    return out;
}

typedef struct{
    string str;
    int d;
}lock;

int main(){
    /*
    cout<<add("1212","0101")<<endl;
    cout<<add("999","000")<<endl;
    cout<<add("999","999")<<endl;
    cout<<add("998","001")<<endl;
    cout<<add("988","011")<<endl;
    cout<<add("988","005")<<endl;
    cout<<add("1000","1205")<<endl;
    */
    string first, last, str;
    int N , T=0;

    while(cin>>first>>last>>N){

        if(first=="0" && last=="0" && N==0) break;
        T++;
        vector<string> v;

        for(int i=0; i<N; i++) {
            cin>>str;
            v.push_back(str);
            //cout<<str<<endl;
        }

    queue<lock> Q;
    map<string,bool> m;
    int ans = -1;
    lock ob, u, vv;
    ob.str = first;
    ob.d = 0;
    m[first] = true;
    Q.push(ob);

    while(!Q.empty()){
        u = Q.front(); Q.pop();
        for(int i=0; i<N; i++){
            str = add(u.str,v[i]);
            if(str=="OVERFLOW"||m.find(str)!=m.end()) continue; //||m.find(str)!=m.end()
            /*
            for(int k=0; k<str.size();k++){
                if(str[k]<'0'||str[k]>'9'){
                    cout<<u.str<<" + "<<v[i]<<" = "<<str<<endl;
                    break;
                }
            }*/
            //cout<<"New Value : "<<str<<endl;
            vv.str = str;
            vv.d = u.d + 1;
            m[vv.str] = true;
            Q.push(vv);
            if(vv.str==last){ ans = vv.d; break;}
        }
    if(ans!=-1) break;
    }

    cout<<"Case "<<T<<": ";
    if(ans==-1) cout<<"Permanently Locked";
    else cout<<ans;
    cout<<endl;

    }
return 0;
}

