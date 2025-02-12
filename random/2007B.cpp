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
		// a1,a2..an
		// m개의 operation, 그녀가 행하려는
		// + l r: 모든 L<=a[i]<=R 대해 ++a[i]
		// - l r: 모든 L<=a[i]<=R에 대해 --a[i]
		// m번의 operation 후에 가장 큰 수는?
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<pair<char,pair<ll,ll>>> p;
		for(ll i=0;i<m;++i){
			char c;
			ll a,b;
			cin>>c>>a>>b;
			p.push_back({c,{a,b}});
		}
		sort(v.begin(),v.end());
		// 1 1 2 2 3
		ll max_num=v[n-1];
		vector<ll> ans; // 각 operation이 끝날 때마다 최대의 수?
		for(ll i=0;i<m;++i){
			char c=p[i].first;
			ll L=p[i].second.first;
			ll R=p[i].second.second;
			if(c=='+'){
				// L과 R 사이에 있는 모든 수 +1
				if(L<=max_num && max_num<=R){
					ans.push_back(max_num+1);
					++max_num;
				}else{
					ans.push_back(max_num);
				}
			}else{
				// L과 R 사이에 있는 모든 수 -1
				if(L<=max_num && max_num<=R){
					ans.push_back(max_num-1);
					--max_num;
				}else{
					ans.push_back(max_num);
				}
			}
		}
		for(ll i=0;i<m;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 	

	return 0;
}