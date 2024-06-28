#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		vector<ll> a_dp(n,0),b_dp(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		if(a[n-1]==1){
			a_dp[n-1]=1;
		}
		if(b[n-1]==1){
			b_dp[n-1]=1;
		}
		for(ll i=n-2;i>=0;--i){
			a_dp[i]=a_dp[i+1];
			b_dp[i]=b_dp[i+1];
			if(a[i]==1){
				++a_dp[i];
			}
			if(b[i]==1){
				++b_dp[i];
			}
		}
		ll fst_sum=0;
		ll sed_sum=0;
		for(ll i=0;i<n;++i){
			if(a[i]==b[i]){
				if(a[i]==1){
					if(fst_sum+a_dp[i]<sed_sum+b_dp[i]){
						++fst_sum;
					}else{
						++sed_sum;
					}
				}else if(a[i]==-1){
					if(fst_sum+a_dp[i]<sed_sum+b_dp[i]){
						--sed_sum;
					}else{
						--fst_sum;
					}
				}
			}else{
				if(a[i]==-1 || b[i]==-1){
					if(a[i]==-1){
						sed_sum+=b[i];
					}
					if(b[i]==-1){
						fst_sum+=a[i];
					}
				}else{
					if(a[i]<b[i]){
						++sed_sum;
					}else{
						++fst_sum;
					}
				}
			}
		}
		cout<<min(fst_sum,sed_sum)<<"\n";
	} 
	return 0;
}