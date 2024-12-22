#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n+1,0), psum(n+1,0);
		psum[1]=1;
		for(ll i=2;i<=n;++i){
			psum[i]=psum[i-1]+i*i;
		}
		ll ans=psum[n-1];
		for(ll i=n-1;i>=2;--i){
			// i에서 n까지 swap
			ll sum=psum[i-1];
			ll c=i+n;
			ll max_num=(i-1)*(i-1);
			for(ll j=i;j<=n;++j){
				sum+=j*(c-j);
				max_num=max(max_num,j*(c-j));
			}
			ans=max(ans,sum-max_num);
		}
		ll tmp=0;
		ll tmp_max=-1;
		for(ll i=1;i<=n;++i){
			tmp+=i*(n-i+1);
			tmp_max=max(tmp_max,i*(n-i+1));
		}
		ans=max(ans,tmp-tmp_max);
		cout<<ans<<"\n";
	}
	return 0;
}