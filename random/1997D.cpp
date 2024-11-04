#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> cost(n+1,0);
		vector<ll> in_cnt(n+1,0);
		vector<ll> v[n+1];
		vector<ll> g[n+1];
		for(ll i=1;i<=n;++i){
			cin>>cost[i];
		}
		for(ll i=2;i<=n;++i){
			ll a;
			cin>>a;
			v[a].push_back(i);
			++in_cnt[a];
			g[i].push_back(a);
		}
		queue<ll> q;
		vector<ll> dp(n+1,1222232421);
		for(ll i=2;i<=n;++i){
			if(!in_cnt[i]){
				q.push(i);
				dp[i]=cost[i];
			}
		}
		while(!q.empty()){
			ll cur_num=q.front();
			// cout<<cur_num<<endl;
			q.pop();
			for(ll i=0;i<g[cur_num].size();++i){
				ll next_num=g[cur_num][i];
				if(next_num==1) continue;
				dp[next_num]=min(dp[next_num],min(cost[cur_num],dp[cur_num]));
				if(in_cnt[next_num]){
					--in_cnt[next_num];
				}
				if(!in_cnt[next_num]){
					q.push(next_num);
				}
			}
		}
		// for(ll i=2;i<=n;++i){
		// 	cout<<i<<" "<<dp[i]<<endl;
		// }
		ll ans=1222232421;
		for(ll i=0;i<v[1].size();++i){
			ll next_num=v[1][i];
			if(cost[next_num]>=dp[next_num]){
				ans=min(ans,cost[1]+dp[next_num]);
			}else{
				ans=min(ans,cost[1]+cost[next_num]+((dp[next_num]-cost[next_num])/2));
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}