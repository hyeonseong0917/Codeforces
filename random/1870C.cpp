#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		vector<ll> l_dp(n,0), r_dp(n,0);
		vector<ll> ans(k+1,0);
		map<ll,ll> m;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		r_dp[n-1]=v[n-1];
		l_dp[0]=v[0];
		for(ll i=1;i<n-1;++i){
			l_dp[i]=max(l_dp[i-1],v[i]);
		}
		for(ll i=n-2;i>=0;--i){
			r_dp[i]=max(r_dp[i+1],v[i]);
		}
		for(ll i=0;i<n;++i){
			ll min_idx, max_idx;
			min_idx=i-1;
			max_idx=i+1;
			if(i==0) min_idx=0;
			if(i==n-1) max_idx=n-1;
			// min_idx구하기
			ll L=0, R=min_idx;
			if(l_dp[R]<v[i]){
				min_idx=i;
			}else{
				while(L<=R){
					ll mid=(L+R)/2;
					if(l_dp[mid]>=v[i]){
						min_idx=min(min_idx,mid);
						R=mid-1;
					}else{
						L=mid+1;
					}
				}
			}
			
			// if(i==1){
			// 	cout<<min_idx<<endl;
			// }
			// max_idx 구하기
			L=max_idx, R=n-1;
			if(r_dp[L]<v[i]){
				max_idx=i;
			}else{
				while(L<=R){
					ll mid=(L+R)/2;
					if(r_dp[mid]>=v[i]){
						L=mid+1;
						max_idx=max(max_idx,mid);
					}else{
						R=mid-1;
					}
				}
			}
			
			// cout<<i<<" "<<v[i]<<" "<<min_idx<<" "<<max_idx<<endl;
			m[v[i]]=2*(max_idx-min_idx+1);
		}
		for(ll i=1;i<=k;++i){
			if(!m[i]){
				ans[i]=0;
			}else{
				ans[i]=m[i];
			}
		}
		for(ll i=1;i<=k;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}