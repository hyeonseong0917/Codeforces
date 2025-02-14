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
	// cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<pair<ll,ll>> q;
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			q.push_back({a,b});
		}
		if(n<=2){
			for(ll i=0;i<m;++i){
				ll a=q[i].first;
				ll b=q[i].second;
				cout<<b-a+1<<"\n";
			}
			continue;
		}
		vector<ll> dp(n,0);
		for(ll i=1;i<n-1;++i){
			if(v[i]<=v[i-1] && v[i]>=v[i+1]){
				dp[i]=dp[i-1]+1;
			}else{
				dp[i]=dp[i-1];
			}
		}

		for(ll i=0;i<m;++i){
			ll L=q[i].first-1;
			ll R=q[i].second-1;
			if(L==R){
				cout<<1<<"\n";
				continue;
			}
			cout<<(R-L+1)-(dp[R-1]-dp[L])<<"\n";
		}
	} 	

	return 0;
}