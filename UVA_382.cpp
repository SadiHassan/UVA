//Accepted!!!
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, sum;
	cout<<"PERFECTION OUTPUT"<<endl;
	while(cin>>N){
		if(N==0) break;
		sum = 0;
		for(int i = 1; i <= sqrt(N); i++){
			if(N%i==0){
				if(N/i==i) {
					sum += i;
					if(N==1) sum -= 1; 
					/*cout<<i<<endl;*/
				}
				else {
					sum = sum + i + N/i; 
					/*cout<<i<<" "<<N/i<<endl;*/
					if(N/i == N) sum -= N/i;
				}
			}
		}
		std::cout.width(5); 
		std::cout << std::right << N << "  ";
		if(sum==N) cout<<"PERFECT"<<endl;
		else if(sum<N) cout<<"DEFICIENT"<<endl;
		else cout<<"ABUNDANT"<<endl; 
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}