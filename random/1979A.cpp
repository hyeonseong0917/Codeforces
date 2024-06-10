#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll a=max(v[0],v[1]);
		for(ll i=1;i<n-1;++i){
			a=min(a,max(v[i],v[i+1]));
		}
		cout<<a-1<<"\n";

	} 
	return 0;
}