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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		map<ll,ll> m;
		vector<ll> dp(n,0);
		for(ll i=n-1;i>=0;--i){
			if(m[v[i]]){
				dp[i]=m[v[i]];
				m[v[i]]=i;
			}else{
				dp[i]=i;
				m[v[i]]=i;
			}
		}
		ll ans=1;
		if(dp[0]==0){
			cout<<1<<"\n";
			continue;
		}
		// for(ll i=0;i<n;++i){
		// 	cout<<i<<" ";
		// }cout<<"\n";
		// for(ll i=0;i<n;++i){
		// 	cout<<dp[i]<<" ";
		// }cout<<"\n";
		ll L=1, R=dp[0];
		while(L<n && R<n && L<=R){
			// cout<<L<<" "<<R<<" "<<ans<<"\n";
			ll max_idx=-1;
			bool flag=0;
			for(ll i=L;i<=R;++i){
				if(dp[i]==i){
					flag=1;
					break;
				}else{
					max_idx=max(max_idx,dp[i]);
				}
			}
			if(flag){
				++ans;
				break;
			}
			++ans;
			L=R+1;
			R=max_idx;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
