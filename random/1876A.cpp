#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.second==b.second){
		return a.first>b.first;
	}
	return a.second<b.second;
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,p;
		cin>>n>>p;
		vector<ll> a(n,0),b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			v.push_back({a[i],b[i]});
		}

		sort(v.begin(),v.end(),comp);
		ll idx=0;
		ll cost=p;
		ll R=0;
		while(idx<n && R<n){
			if(R+v[idx].first>=n){
				cost+=min(v[idx].second,p)*(n-1-R);
				break;
			}else{
				cost+=min(v[idx].second,p)*v[idx].first;
				R+=v[idx].first;
				++idx;
			}
		}
		cout<<cost<<"\n";
	}
	return 0;
}