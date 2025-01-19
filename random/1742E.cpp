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
		ll n,quest;
		cin>>n>>quest;
		vector<ll> q(quest,0);
		vector<ll> v;
		vector<ll> max_diff;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			if(i==0){
				v.push_back(a);
				max_diff.push_back(a);
			}else{
				ll vs=v.size();
				ll ms=max_diff.size();
				v.push_back(v[vs-1]+a);
				ll cur_max_diff=max_diff[ms-1];
				max_diff.push_back(max(cur_max_diff,v[i]-v[i-1]));
			}
		}
		// for(ll i=0;i<n;++i){
		// 	cout<<v[i]<<" ";
		// }cout<<"\n";
		// for(ll i=0;i<n;++i){
		// 	cout<<max_diff[i]<<" ";
		// }cout<<"\n";
		for(ll i=0;i<quest;++i){
			cin>>q[i];
		}
		for(ll i=0;i<q.size();++i){
			ll cur_num=q[i];
			ll L=0, R=n-1;
			ll idx=-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(max_diff[mid]<=cur_num){
					idx=max(idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			if(idx==-1){
				cout<<0<<" ";
			}else{
				cout<<v[idx]<<" ";
			}
		}cout<<"\n";
	} 
	return 0;
}