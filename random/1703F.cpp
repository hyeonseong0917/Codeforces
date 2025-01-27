#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first<b.first;
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=1;i<=n;++i){
			ll a;
			cin>>a;
			v.push_back({a,i});
		}
		sort(v.begin(),v.end(),comp);
		vector<ll> dp(n,0);
		if(v[n-1].first<v[n-1].second){
			dp[n-1]=1;
		}
		for(ll i=n-2;i>=0;--i){
			if(v[i].first<v[i].second){
				dp[i]=dp[i+1]+1;
			}else{
				dp[i]=dp[i+1];
			}
		}
		ll ans=0;
		for(ll i=0;i<n-1;++i){
			if(v[i].first<v[i].second){
				ll L=i+1;
				ll R=n-1;
				ll idx=2023101800;
				while(L<=R){
					ll mid=(L+R)/2;
					if(v[mid].first>v[i].second){
						idx=min(idx,mid);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
				if(idx==2023101800) continue;
				ans+=dp[idx];
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}