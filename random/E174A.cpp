#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n-2,0);
		for(ll i=0;i<n-2;++i){
			cin>>v[i];
		}
		if(n<=4){
			cout<<"YES"<<"\n";
			continue;
		}
		ll m=n-2;
		bool flag=0;
		for(ll i=0;i<m-2;++i){
			if(v[i]==1 && v[i+1]==0 && v[i+2]==1){
				flag=1;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}


	} 	

	return 0;
}