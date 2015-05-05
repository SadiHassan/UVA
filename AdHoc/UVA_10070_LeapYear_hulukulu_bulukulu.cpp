//ACCEPTED!!!
#include<iostream>
using namespace std;

int main(){

string str;
long int len, sum_even, sum_odd, diff, m400;
bool shuru, leap, hulu, bulu, mod4, mod100, mod11, mod3, mod5,mod400;

shuru=true;

while(cin>>str){

    len = str.size();
    sum_even = 0;
    sum_odd = 0;
    m400 = 0;
    mod11 = false;
    mod100 = false;
    mod4 = false;
    mod400 = false;
    mod3 = false;
    mod5 = false;


    for(int i=0; i<len;i+=2){
        sum_odd = sum_odd + str[i] - '0';
        if(i+1<len) sum_even = sum_even + str[i+1] - '0';

        m400 = (m400*10 + str[i] - '0')%400;
        if(i+1<len) m400 = (m400*10 + str[i+1] - '0')%400;
    }

    diff = sum_odd - sum_even;
    if(diff<0) diff = diff * (-1);

    if(diff%11==0) mod11 = true;

    if(str[len-1]=='0'&&str[len-2]=='0') mod100 = true;

    if( (10*(str[len-2]-'0') + str[len-1]-'0') % 4 ==0 ) mod4=true;
    if( (sum_odd+sum_even) % 3 == 0 ) mod3=true;
    if( str[len-1]=='0' || str[len-1]=='5' ) mod5 = true;

    if(m400==0) mod400=true;

    if(shuru==false) cout<<endl;
    shuru= false;

    leap = false;
    hulu = false;
    bulu = false;

    /*
    cout<<"mod100 : "<<mod100<<endl;
    cout<<"mod4 : "<<mod4<<endl;
    cout<<"mod400 : "<<mod100<<endl;
    cout<<"mod11 : "<<mod11<<endl;
    cout<<"mod3 : "<<mod3<<endl;
    cout<<"mod5 : "<<mod5<<endl;
    */


    if( (mod4 && !mod100) || mod400  ){
        cout<<"This is leap year."<<endl;
        leap=true;
    }
    if( mod3 && mod5 )
        {cout<<"This is huluculu festival year."<<endl; hulu=true;}

    if(leap && mod5 && mod11)
        {cout<<"This is bulukulu festival year."<<endl; bulu=true;}

    if(hulu||bulu||leap) continue;

    cout<<"This is an ordinary year."<<endl;

}

return 0;
}
