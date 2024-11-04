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
	
	ll t=1;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<ll> v[n+1];
		vector<ll> in_cnt(n+1,0);
		vector<ll> dp(n+1,0);
		for(ll i=0;i<m;++i){
			ll a,b;
			cin>>a>>b;
			v[a].push_back(b);
			++in_cnt[b];
		}
		queue<ll> q;
		for(ll i=1;i<=n;++i){
			if(!in_cnt[i]){
				q.push(i);
				dp[i]=1;
			}
		}
		while(!q.empty()){
			ll cur_num=q.front();
			q.pop();
			for(ll i=0;i<v[cur_num].size();++i){
				ll next_num=v[cur_num][i];
				if(in_cnt[next_num]){
					--in_cnt[next_num];
				}
				dp[next_num]=max(dp[next_num],dp[cur_num]+1);
				if(!in_cnt[next_num]){
					q.push(next_num);
				}
			}
		}
		for(ll i=1;i<=n;++i){
			cout<<dp[i]<<" ";
		}
	}
	return 0;
}