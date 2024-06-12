#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

const ll MAX=200000+1;
ll dp[MAX][2+1];
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<3;++j){
				dp[i][j]=0;
			}
		}
		dp[0][1]=v[0];
		dp[0][2]=abs(v[0]);
		for(ll i=1;i<n;++i){
			dp[i][1]=min(dp[i-1][1]+v[i],dp[i-1][2]+v[i]);
			dp[i][2]=max(abs(dp[i-1][1]+v[i]),abs(dp[i-1][2]+v[i]));
		}
		ll ans=max(abs(dp[n-1][1]),dp[n-1][2]);
		cout<<ans<<"\n";

	} 
	return 0;
}