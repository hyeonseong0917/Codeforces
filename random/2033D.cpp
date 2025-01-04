#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n+1,0),psum(n+1,0),dp(n+1,0);
		for(ll i=1;i<=n;++i){
			cin>>v[i];
		}
		if(n==1){
			if(v[1]==0){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
			continue;
		}
		psum[1]=v[1];
		for(ll i=2;i<=n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		map<ll,ll> m;
		if(v[1]==0) ++dp[1];
		m[psum[1]-v[1]]=1;
		for(ll i=2;i<=n;++i){
			m[psum[i]-v[i]]=i;
			dp[i]=dp[i-1];
			if(m[psum[i]]>=1){
				dp[i]=max(dp[i],dp[m[psum[i]]-1]+1);
			}
		}
		// cout<<m[-1]<<endl;
		cout<<dp[n]<<"\n";
	}
	return 0;
}