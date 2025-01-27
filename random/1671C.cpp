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
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		vector<ll> psum(n,0);
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		ll L=0, R=n-1;
		ll idx=-1;
		while(L<=R){
			ll mid=(L+R)/2;
			if(psum[mid]<=x){
				idx=max(idx,mid);
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		ll ans=idx+1;
		// cout<<ans<<"\n";
		for(ll i=0;i<=idx;++i){
			ans+=(x-psum[i])/(i+1);
		}
		cout<<ans<<"\n";
	} 
	return 0;
}