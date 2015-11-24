//ACCEPTED!!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

int N; string str;

cin>>N;
for(int i=1; i<=N; i++){
    cin>>str;
    sort(str.begin(),str.end());
    do{
        cout<<str<<endl;
    }while(next_permutation(str.begin(),str.end()));
cout<<endl;
}

return 0;
}
