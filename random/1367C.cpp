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
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		bool is_all_zero=1;
		bool is_all_one=1;
		for(ll i=0;i<s.size();++i){
			if(s[i]=='1'){
				is_all_zero=0;
			}
			if(s[i]=='0'){
				is_all_one=0;
			}
		}
		if(is_all_zero || is_all_one){
			if(is_all_one){
				cout<<0<<"\n";
			}else{
				ll idx=1;
				ll ans=0;
				while(idx<=n){
					++ans;
					idx+=(k+1);
				}
				cout<<ans<<"\n";
			}
			continue;
		}
		ll INF=2023101800;
		vector<ll> L_dp(n,INF), R_dp(n,INF);
		// L_dp[x]: x인덱스에서 가장 가까운 왼쪽 1까지의 거리
		// L_dp[0]
		for(ll i=1;i<n;++i){
			if(s[i]=='0'){
				if(s[i-1]=='1'){
					L_dp[i]=1;
				}else{
					L_dp[i]=L_dp[i-1]+1;
				}
			}
		}
		// R_dp[x]: x인덱스에서 가장 가까운 오른쪽 1까지의 거리
		for(ll i=n-2;i>=0;--i){
			if(s[i]=='0'){
				if(s[i+1]=='1'){
					R_dp[i]=1;
				}else{
					R_dp[i]=R_dp[i+1]+1;
				}
			}
		}
		vector<ll> dp(n,0);
		for(ll i=0;i<n;++i){
			if(s[i]=='0'){
				dp[i]=min(L_dp[i],R_dp[i]);
				// cout<<i<<" "<<dp[i]<<"\n";
			}
		}
		ll idx=0;
		ll ans=0;
		while(idx<n){
			if(s[idx]=='0'){
				if(dp[idx]>k){
					++ans;
					idx+=k+1;
				}else{
					++idx;
				}
			}else{
				++idx;
			}
		}
		cout<<ans<<"\n";
	} 

	return 0;
}