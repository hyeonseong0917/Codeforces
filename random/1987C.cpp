#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
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
		ll n;
		cin>>n;
		vector<ll> h(n,0),dp(n,0);
		for(ll i=0;i<n;++i){
			cin>>h[i];
		}
		ll ans=h[n-1];
		for(ll i=n-2;i>=0;--i){
			if(h[i]>h[i+1]){
				if(h[i+1]>=h[i]-dp[i+1]){
					ans=max(ans,dp[i+1]+1+h[i+1]);
					dp[i]=dp[i+1]+1;
					h[i]=h[i+1];
				}else{
					ans=max(ans,h[i]);
				}
				
			}else{
				dp[i]=dp[i+1]+h[i+1]-h[i]+1;
				ans=max(ans,h[i]+dp[i]);
			}

		}
		cout<<ans<<"\n";
	}
	return 0;
}