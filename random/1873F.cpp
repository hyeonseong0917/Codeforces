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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0),h(n,0),psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=0;i<n;++i){
			cin>>h[i];
		}
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		if(n==1){
			if(v[0]<=k){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
			continue;
		}
		ll L=0, R=0;
		ll ans=0;
		while(R<=n-2){
			if(psum[R+1]-psum[L]+v[L]<=k && h[R]%h[R+1]==0){
				++R;
				ans=max(ans,R-L+1);
			}else{
				++L;
				if(L>R){
					R=L;
				}
			}
			// cout<<L<<" "<<R<<" "<<ans<<"\n";
		}
		if(ans==0){
			for(ll i=0;i<n;++i){
				if(v[i]<=k){
					ans=1;
					break;
				}
			}
		}
		cout<<ans<<"\n";

	}
	
	return 0;
}