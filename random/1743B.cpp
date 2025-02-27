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
		ll n;
		cin>>n;
		ll L=1, R=n;
		for(ll i=0;i<n;++i){
			if(i%2==0){
				cout<<L<<" ";
				++L;
			}else{
				cout<<R<<" ";
				--R;
			}
		}
	} 
	return 0;
}