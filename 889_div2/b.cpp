#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		long long n=0;
		cin>>n;
		if(n==1){
			cout<<1<<"\n";
		}else if(n==2){
			cout<<2<<"\n";
		}else{
			for(long long i=1;i<=n;++i){
				if(n%i!=0){
					cout<<i-1<<"\n";
					break;
				}
			}
		}
		cout<<"\n";
	}
	return 0;
}