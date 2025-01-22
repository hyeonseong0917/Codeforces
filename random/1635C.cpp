#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		vector<ll> max_num(n,0), dp(n,2023101800);
		max_num[n-1]=n-1;
		for(ll i=n-2;i>=0;--i){
			if(a[i]<=a[max_num[i+1]]){
				max_num[i]=max_num[i+1];
			}else{
				max_num[i]=i;
			}
		}
		map<ll,pair<ll,ll>> m;
		for(ll i=1;i<n-1;++i){
			ll cur_num=a[i]-a[max_num[i+1]];
			m[cur_num]={i,max_num[i+1]};
		}
		for(ll i=n-2;i>=0;--i){
			ll cur_num=a[i]-a[max_num[i+1]];
			dp[i]=min(dp[i+1],cur_num);
		}
		vector<pair<ll,pair<ll,ll>>> v;
		for(ll i=0;i<n-1;++i){
			ll cur_num=dp[i+1];
			if(a[i]<=cur_num) continue;
			a[i]=cur_num;
			v.push_back({i,{m[cur_num].first, m[cur_num].second}});
		}
		bool flag=0;
		ll vs=v.size();
		for(ll i=0;i<n-1;++i){
			if(a[i]>a[i+1]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<-1<<"\n";
			continue;
		}
		cout<<vs<<"\n";
		for(ll i=0;i<vs;++i){
			cout<<v[i].first+1<<" "<<v[i].second.first+1<<" "<<v[i].second.second+1<<"\n";
		}
	} 
	return 0;
}
