#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first>b.first;
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<vector<ll>> v;
		vector<pair<ll,ll>> p;
		for(ll i=0;i<n;++i){
			vector<ll> tmp;
			ll sum=0;
			for(ll j=0;j<m;++j){
				ll a;
				cin>>a;
				tmp.push_back(a);
				sum+=a;
			}
			v.push_back(tmp);
			p.push_back({sum,i});
		}
		sort(p.begin(),p.end(),comp);
		vector<ll> c;
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				c.push_back(v[p[i].second][j]);
			}
		}
		vector<ll> psum(n*m,0);
		// for(ll i=0;i<n*m;++i){
		// 	cout<<c[i]<<" ";
		// }cout<<endl;
		psum[0]=c[0];
		for(ll i=1;i<n*m;++i){
			psum[i]=psum[i-1]+c[i];
		}
		ll ans=psum[0];
		for(ll i=1;i<n*m;++i){
			ans+=c[i]+psum[i-1];
		}
		cout<<ans<<"\n";
	} 	

	return 0;
}