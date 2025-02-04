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
		ll n,m;
		cin>>n>>m;
		vector<vector<ll>> b;
		vector<vector<ll>> ans;
		for(ll i=0;i<n;++i){
			vector<ll> tmp;
			vector<ll> tt;
			for(ll j=0;j<m;++j){
				ll a;
				cin>>a;
				tmp.push_back(a);
				tt.push_back(-1);
			}
			b.push_back(tmp);
			ans.push_back(tt);
		}
		vector<ll> min_dp(m,0);
		priority_queue<ll> pq;
		for(ll i=0;i<m;++i){
			pq.push(b[0][i]*-1);
		}
		map<ll,ll> rank;
		for(ll i=0;i<m;++i){
			rank[m-i]=m-i-1;
			ans[0][i]=pq.top()*-1;
			min_dp[i]=ans[0][i];
			pq.pop();
		}
		for(ll i=1;i<n;++i){
			for(ll j=0;j<m;++j){
				pq.push(b[i][j]*-1);
			}
			for(ll j=m-1;j>=0;--j){
				ll cur_rank=rank[j+1];
				ans[i][cur_rank]=pq.top()*-1;
				pq.pop();
			}
			vector<pair<ll,ll>> v;
			for(ll j=0;j<m;++j){
				min_dp[j]=min(min_dp[j],ans[i][j]);
				v.push_back({min_dp[j],j});
			}
			sort(v.rbegin(),v.rend());
			for(ll j=0;j<m;++j){
				rank[m-j]=v[j].second;
			}
		}
		for(ll i=0;i<n;++i){
			for(ll j=0;j<m;++j){
				cout<<ans[i][j]<<" ";
			}cout<<"\n";
		}

	} 

	return 0;
}