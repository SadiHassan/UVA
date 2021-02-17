//ACCEPTED!!!
#include<bits/stdc++.h>
using namespace std;

int main(){

//cout << pow(2, 31) << endl;

vector<long long> twos;
long long two_val = 1;
for(int i = 1; i <= 31; i++){
    twos.push_back(two_val);
    two_val *= 2;
}

vector<long long> threes;
long long three_val = 1;
for(int i = 1; i <= 31; i++){
    threes.push_back(three_val);
    three_val *= 3;
}

vector<long long> arr;
for(int i = 0; i < 31; i++)
for(int j = 0; j < 31; j++){
    if(twos[i] * threes[j] <= pow(2,31))
        arr.push_back(twos[i] * threes[j]);
    else break;
}

sort(arr.begin(), arr.end());

/*
for(int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
cout << endl;
*/

long long val;

while(cin >> val){
    if(val == 0) break;
    long long ans = 0;
    int left = 0;
    int right = arr.size() - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == val){
            ans = arr[mid];
            break;
        }
        else if(arr[mid] > val){
            ans = arr[mid];
            right = mid - 1;
        }
        else
            left = mid + 1;
        //cout << arr[mid] << endl;
    }

    cout << ans << endl;
}

return 0;
}
