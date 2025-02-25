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
		vector<ll> a(n,0),b(n,0);
		vector<pair<ll,ll>> av,bv;
		for(ll i=0;i<n;++i){
			cin>>a[i];
			av.push_back({a[i],i});
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
			bv.push_back({b[i],i});
		}
		sort(av.begin(),av.end());
		sort(b.begin(),b.end());
		// |a[i]-b[i]|<=k
		vector<ll> ans(n,0);
		for(ll i=0;i<n;++i){
			ll a_idx=av[i].second;
			ans[a_idx]=b[i];
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}