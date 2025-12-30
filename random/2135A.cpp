#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> g[n+1];
		for(ll i=0;i<n;++i){
			cin>>v[i];
			g[v[i]].push_back(i);
		}
		vector<ll> dp(n,0);
		// dp[i]: i인덱스까지 봤을 때 조건을 만족하는 최대 길이
		// dp[i]=max(dp[i-1],v[i]+dp[v[i]가 조건을 만족하는 최대인덱스-1])
		vector<ll> p(n,-1);
		// v[i]가 조건을 만족하는 최대인덱스
		for(ll i=1;i<=n;++i){
			for(ll j=0;j<g[i].size();++j){
				ll cur_idx=g[i][j];
				if(j+1-i>=0){
					p[cur_idx]=g[i][j+1-i];
				}
			}
		}
		// for(ll i=0;i<n;++i){
		// 	cout<<p[i]<<" ";
		// }cout<<endl;
		if(v[0]==1){
			dp[0]=1;
		}
		for(ll i=1;i<n;++i){
			dp[i]=dp[i-1];
			if(p[i]==-1) continue;
			ll c=0;
			if(p[i]){
				c=dp[p[i]-1];
			}
			dp[i]=max(dp[i],c+v[i]);
		}
		cout<<dp[n-1]<<"\n";
	}
	return 0;
}