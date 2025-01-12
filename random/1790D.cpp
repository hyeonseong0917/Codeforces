#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first<b.first;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0);
		map<ll,ll> m;
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			if(!m[a[i]]){
				v.push_back({a[i],0});
			}
			++m[a[i]];
		}
		ll vs=v.size();
		for(ll i=0;i<vs;++i){
			v[i].second=m[v[i].first];
		}
		sort(v.begin(),v.end(),comp);
		ll ans=0;
		ll cur_open=0;
		for(ll i=0;i<vs;++i){
			if(i==0 || v[i].first!=v[i-1].first+1){
				cur_open=v[i].second;
				ans+=cur_open;
			}else{
				if(cur_open<v[i].second){
					ans+=v[i].second-cur_open;
				}
				cur_open=v[i].second;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}