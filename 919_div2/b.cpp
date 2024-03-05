#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	ll psum[200000+1];
	while(t--){
		ll N,K,X;
		vector<ll> v;
		cin>>N>>K>>X;
		for(ll i=0;i<N;++i){
			ll a=0;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		psum[0]=v[0];
		for(ll i=1;i<N;++i){
			psum[i]=psum[i-1]+v[i];
		}
		ll sum=-2000000000-1;
		for(ll i=0;i<=K;++i){
			ll cur_idx=N-1-i;
			if(cur_idx<0){
				sum=max(sum,(ll)0);
				break;	
			} 
			if(cur_idx<X){
				sum=max(psum[cur_idx]-2*psum[cur_idx],sum);
			}else{
				sum=max(psum[cur_idx]-2*(psum[cur_idx]-psum[cur_idx-X]),sum);	
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}