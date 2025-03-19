#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// a[i]+a[j]>=l && a[i]+a[j]<=r
		// 를 만족하는 i,j쌍의 개수를 구하여라라
		ll n,l,r;
		cin>>n>>l>>r;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		sort(v.begin(),v.end());
		// l<=a[i]+a[j]<=r
		// 2 5 6 9 12
		ll ans=0;
		for(ll i=0;i<n;++i){
			// 1. a[i]+a[j]>=l을 만족시키는 최소의 j
			ll L=i+1,R=n-1;
			ll fst_idx=2023101800;
			ll fst_num=l-v[i];
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]>=fst_num){
					fst_idx=min(fst_idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			// 2.a[i]+a[j]<=r을 만족시키는 최대의 j
			// r-a[i]>=a[j]
			L=i+1,R=n-1;
			ll sed_idx=-2023101800;
			ll sed_num=r-v[i];
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]<=sed_num){
					sed_idx=max(sed_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			if(fst_idx==2023101800 || sed_idx==-2023101800) continue;
			ans+=sed_idx-fst_idx+1;
		}
		cout<<ans<<"\n";
		
	} 
	return 0;
}