//ACCEPTED!!!
#include<iostream>
using namespace std;
bool arr[1200];

bool prime(int n){

if(n==1||n==2||n==3) return true;
if(n%2==0||n%3==0) return false;

for(int i=5; i*i<=n; i+=2)
    if( n%i==0|| n%(i+1)==0 ) return false;
return true;
}

int main(){

string str;
int sum;

for(int i=1; i<1200;i++)
    if(prime(i)==true) arr[i]=true;
    else arr[i] = false;

while(cin>>str){

sum = 0;

for(int i=0; i<str.size();i++){
    if(str[i]>='a'&&str[i]<='z')
        sum = sum + str[i] - 'a' + 1;
    else sum = sum + str[i] - 'A' + 27;
}
//cout<<sum<<endl;
if(arr[sum]) cout<<"It is a prime word."<<endl;
else cout<<"It is not a prime word."<<endl;

}

return 0;
}
