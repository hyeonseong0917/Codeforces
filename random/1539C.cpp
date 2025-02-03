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
	// cin>>t;
	while(t--){
		ll n,k,x;
		cin>>n>>k>>x;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		vector<pair<ll,ll>> p;
		ll cur_start=v[0];
		ll cur_finish=v[0];
		for(ll i=1;i<n;++i){
			if(v[i]-cur_finish<=x){
				cur_finish=v[i];
			}else{
				p.push_back({cur_start,cur_finish});
				cur_start=v[i];
				cur_finish=v[i];
			}
		}
		p.push_back({cur_start,cur_finish});
		// for(ll i=0;i<p.size();++i){
		// 	cout<<p[i].first<<" "<<p[i].second<<"\n";
		// }
		ll ans=p.size();
		vector<ll> diff;
		for(ll i=1;i<p.size();++i){
			diff.push_back(p[i].first-p[i-1].second);
		}
		sort(diff.begin(),diff.end());
		ll cnt=0;
		for(ll i=0;i<diff.size();++i){
			// cout<<diff[i]<<"\n";
			ll need_cnt=diff[i]/x;
			if(diff[i]%x==0){
				--need_cnt;
			}
			if(need_cnt<=k){
				k-=need_cnt;
				--ans;
			}
		}
		cout<<ans;
	} 
	return 0;
}