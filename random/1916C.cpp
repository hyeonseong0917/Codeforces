#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0), psum(n,0), odd_cnt(n,0), even_cnt(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		if(v[0]%2==0){
			++even_cnt[0];
		}else{
			++odd_cnt[0];
		}
		for(ll i=1;i<n;++i){
			if(v[i]%2==0){
				even_cnt[i]=even_cnt[i-1]+1;
				odd_cnt[i]=odd_cnt[i-1];
			}else{
				odd_cnt[i]=odd_cnt[i-1]+1;
				even_cnt[i]=even_cnt[i-1];
			}
		}
		for(ll k=1;k<=n;++k){
			if(k==1){
				cout<<v[0]<<" ";
			}else{
				ll cur_odd_num=odd_cnt[k-1];
				ll cnt=cur_odd_num/3;
				if(cur_odd_num%3==1){
					++cnt;
				}
				cout<<psum[k-1]-cnt<<" ";
			}
		}cout<<"\n";
	} 
	return 0;
}