#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second<b.second;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		map<ll,ll> check;
		vector<ll> unique_num;
		for(ll i=0;i<n;++i){
			if(!check[v[i]]){
				unique_num.push_back(v[i]);
			}
			++check[v[i]];
		}
		vector<pair<ll,ll>> p;
		for(ll i=0;i<unique_num.size();++i){
			p.push_back({unique_num[i],check[unique_num[i]]});
		}
		sort(p.begin(),p.end(),comp);
		ll del_cnt=0;
		ll cur_sum=0;
		for(ll i=0;i<p.size();++i){
			ll cur_cnt=p[i].second;
			if(cur_sum+cur_cnt<=k){
				cur_sum+=cur_cnt;
				++del_cnt;
			}else{
				break;
			}
		}
		ll ans=unique_num.size();
		cout<<max(ans-del_cnt,(ll)1)<<"\n";
	} 
	return 0;
}