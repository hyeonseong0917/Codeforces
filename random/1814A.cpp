#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		// 2x+ky=n
		// n-ky가 짝수인지?
		bool flag=0;
		if(n%2==0){
			flag=1;
		}else{
			if(n-k>=0 && (n-k)%2==0){
				flag=1;
			}
			if(n-2*k>=0 && (n-2*k)%2==0){
				flag=1;
			}
		}

		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 
	return 0;
}