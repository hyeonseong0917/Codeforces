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
	// 1053
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> cnt(n+1,0);
		vector<ll> check(n+1,0);
		vector<ll> rest;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++check[v[i]];
		}
		for(ll i=1;i<=n;++i){
			if(!check[i]){
				rest.push_back(i);
			}
		}
		vector<ll> ans;
		ans.push_back(v[0]);
		++cnt[v[0]];
		ll max_cnt=1;
		ll idx=0;
		for(ll i=1;i<n;++i){
			if(cnt[v[i]]<max_cnt){
				ans.push_back(v[i]);
				++cnt[v[i]];
			}else{
				ans.push_back(rest[idx++]);
			}
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 	

	return 0;
}