#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n+1,0);
		for(ll i=1;i<=n;++i){
			cin>>v[i];
		}
		vector<ll> dp(n+1,0);
		ll ans=0;
		for(ll i=1;i<=n;++i){
			dp[i]=min(dp[i-1]+1,v[i]);
			ans+=dp[i];
		}
		
		cout<<ans<<"\n";
	} 
	return 0;
}