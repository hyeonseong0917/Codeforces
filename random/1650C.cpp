#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

bool comp(pair<ll,pair<ll,ll>> a, pair<ll,pair<ll,ll>> b){
	return a.second.second<b.second.second;
}
bool cmp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second<b.second;
}
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<pair<ll,pair<ll,ll>>> v;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({i,{a,b}});
		}
		sort(v.begin(),v.end(),comp);
		vector<ll> ans;
		for(ll i=0;i<2*n;++i){
			ans.push_back(v[i].first);
		}
		vector<pair<ll,ll>> p;
		ll sum=0;
		for(ll i=0;i<2*n;++i){
			ll cur_idx=ans[i];
			p.push_back({cur_idx,v[i].second.first});
			// cout<<cur_idx<<" ";
			sum+=v[i].second.second;
		}
		sort(p.begin(),p.end(),cmp);
		// for(ll i=0;i<2*n;++i){
		// 	cout<<p[i].second<<endl;
		// }
		ll L=0, R=2*n-1;
		vector<pair<ll,ll>> c;
		while(L<R){
			// cout<<p[L].second<<" "<<p[R].second<<"\n";
			c.push_back({p[L].first, p[R].first});
			++L;
			--R;
		}
		cout<<sum<<"\n";
		for(ll i=0;i<n;++i){
			cout<<c[i].first+1<<" "<<c[i].second+1<<"\n";
		}
	} 	

	return 0;
}