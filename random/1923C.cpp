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
		ll n,q;
		cin>>n>>q;
		vector<ll> v(n,0);
		//dp[i]: i인덱스까지 1의 개수
		vector<ll> dp(n,0);
		vector<ll> psum(n,0);
		ll cur_num=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		psum[0]=v[0];
		for(ll i=0;i<n;++i){
			if(v[i]==1){
				++cur_num;
			}
			dp[i]=cur_num;
			psum[i]=psum[i-1]+v[i];
		}
		for(ll i=0;i<q;++i){
			ll l,r;
			cin>>l>>r;
			ll cnt=r-l+1;
			--l;
			--r;
			ll one_cnt=dp[r];
			if(l>0){
				one_cnt-=dp[l-1];
			}

		}
	}
	
	return 0;
}