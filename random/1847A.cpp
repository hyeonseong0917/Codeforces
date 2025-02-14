#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		ll ans=0;
		vector<ll> diff;
		for(ll i=0;i<n-1;++i){
			ans+=abs(v[i+1]-v[i]);
			diff.push_back(abs(v[i+1]-v[i]));
		}
		sort(diff.rbegin(),diff.rend());
		for(ll i=0;i<k-1;++i){
			ans-=diff[i];
		}
		cout<<ans<<"\n";
	} 	

	return 0;
}