#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=1;
	// cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0),dp(n,0),psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		string s;
		cin>>s;
		dp[0]=1;
		for(ll i=1;i<n;++i){
			if(s[i]==s[i-1]){
				dp[i]=dp[i-1]+1;
			}else{
				dp[i]=1;
			}
		}
		vector<pair<ll,ll>> p;
		vector<ll> start_pos;
		start_pos.push_back(0);
		for(ll i=1;i<n;++i){
			if(dp[i]==1){
				start_pos.push_back(i);
			}
		}
		start_pos.push_back(n);
		for(ll i=0;i<start_pos.size()-1;++i){
			p.push_back({start_pos[i],start_pos[i+1]-start_pos[i]});
		}
		// for(ll i=0;i<p.size();++i){
		// 	cout<<p[i].first<<" "<<p[i].second<<"\n";
		// }
		ll ans=0;
		for(ll i=0;i<p.size();++i){
			ll cur_start=p[i].first;
			ll cur_len=p[i].second;
			ll sum=0;
			priority_queue<ll> pq;
			for(ll j=cur_start;j<cur_start+cur_len;++j){
				sum+=v[j];
				pq.push(v[j]*-1);
			}
			if(p[i].second<=k){
				ans+=sum;		
			}else{
				ll c=cur_len-k;
				while(c--){
					ll cur_num=pq.top()*-1;
					pq.pop();
					sum-=cur_num;
				}
				ans+=sum;
			}
		}
		cout<<ans;
	} 	

	return 0;
}