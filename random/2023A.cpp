#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return (a.first+a.second)<(b.first+b.second);

}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),comp);
		vector<ll> ans;
		for(ll i=0;i<n;++i){
			ans.push_back(v[i].first);
			ans.push_back(v[i].second);
		}
		for(ll i=0;i<n*2;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}