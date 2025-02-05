#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long
ll dp[100000+1][2];
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		string s;
		cin>>s;
		ll n=s.size();
		for(ll i=0;i<n;++i){
			for(ll j=0;j<2;++j){
				dp[i][j]=0;
			}
		}
		vector<pair<ll,ll>> v;
		ll cur_start=-1;
		for(ll i=0;i<n;++i){
			if(s[i]=='1' && cur_start==-1){
				cur_start=i;
			}
			if(s[i]=='0' && cur_start!=-1){
				v.push_back({cur_start,i-1});
				cur_start=-1;
			}
		}
		if(cur_start!=-1){
			v.push_back({cur_start,n-1});
		}
		if(v.empty()){
			cout<<0<<"\n";
			continue;
		}
		// for(ll i=0;i<v.size();++i){
		// 	cout<<v[i].first<<" "<<v[i].second<<"\n";
		// }
		dp[0][0]=a;
		dp[0][1]=0;
		ll vs=v.size();
		for(ll i=1;i<vs;++i){
			ll zero_cnt=v[i].first-v[i-1].second-1;
			dp[i][0]=min(dp[i-1][0]+a,dp[i-1][1]+b*zero_cnt+a);
			dp[i][1]=min(dp[i-1][0],dp[i-1][1]+b*zero_cnt);
			// cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
		}
		cout<<dp[vs-1][0]<<"\n";
	} 

	return 0;
}