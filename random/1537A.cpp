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
		vector<ll> h(n,0), ans(n,0);
		for(ll i=0;i<n;++i){
			cin>>h[i];
		}
		sort(h.begin(),h.end());
		// 가장 작은 diff, 가장 큰 숫자
		ll diff=2023101800;
		ll idx=-1;
		for(ll i=0;i<n-1;++i){
			if(diff>=abs(h[i]-h[i+1])){
				diff=abs(h[i]-h[i+1]);
				idx=i;
			}
		}
		// cout<<idx<<endl;
		// diff은 최소 diff, pair 쌍은 idx와 idx+1
		ans[0]=min(h[idx],h[idx+1]);
		ans[n-1]=max(h[idx],h[idx+1]);
		ll cur_idx=1;
		for(ll i=idx;i<n;++i){
			if(h[i]>h[idx+1]){
				ans[cur_idx++]=h[i];
			}
		}
		for(ll i=0;i<idx;++i){
			ans[cur_idx++]=h[i];
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}