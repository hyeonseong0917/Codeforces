#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0), b(n,0);
		// b를 오름차순으로 만들기 위해 필요한 oper의 최소횟수
		// a[i]를 b[i]에서 빼거나 더함
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		
		// 1 2 3 4 5
		// 0 0 0 0 0
		vector<ll> fst_dp(n,0), sed_dp(n,0);
		fst_dp[n-1]=1;
		for(ll i=n-2;i>=0;--i){
			if(v[i+1]<=v[i]){
				// oper필요
				ll cur_num=v[i];
				ll cnt=1; // v[i]
				for(ll j=i+1;j<n;++j){
					ll q=(cur_num/v[j])+1;
					cnt+=q;
					cur_num=v[j]*q;
				}
				fst_dp[i]=cnt;
			}else{
				fst_dp[i]=fst_dp[i+1]+1;
			}
		}
		sed_dp[0]=1;
		ll last_num=v[0];
		for(ll i=1;i<n;++i){
			if(v[i]>=v[i-1]){
				ll cur_num=v[i];
				ll cnt=1;
				for(ll j=i-1;j>=0;--j){
					ll q=(cur_num/v[j])+1;
					cnt+=q;
					cur_num=v[j]*q;
				}
				sed_dp[i]=cnt;
			}else{
				sed_dp[i]=sed_dp[i-1]+1;
			}
		}
		ll ans=min(sed_dp[n-2],fst_dp[1]);
		for(ll i=1;i<n-1;++i){
			ans=min(ans,sed_dp[i-1]+fst_dp[i+1]);
			// cout<<i<<" "<<ans<<endl;
			// if(i==3){
			// 	cout<<sed_dp[i-1]<<" "<<fst_dp[i+1]<<endl;
			// }
		}
		cout<<ans<<"\n";
		
	} 
	return 0;
}