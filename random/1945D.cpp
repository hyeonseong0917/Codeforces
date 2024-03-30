#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll N,M;
		cin>>N>>M;
		vector<ll> a(N,0), b(N,0), dp(N,0), bsum(N,0);
		for(ll i=0;i<N;++i){
			cin>>a[i];
		}
		for(ll i=0;i<N;++i){
			cin>>b[i];
		}
		dp[N-1]=a[N-1];
		bsum[N-1]=b[N-1];
		for(ll i=N-2;i>=0;--i){
			bsum[i]=bsum[i+1]+b[i];
		}
		for(ll i=N-2;i>=0;--i){
			dp[i]=a[i]+min(bsum[i+1],min(dp[i+1],dp[i+1]-a[i+1]+b[i+1]));
		}
		ll ans=dp[0];
		for(ll i=0;i<M;++i){
			ans=min(ans,dp[i]);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}