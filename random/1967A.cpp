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
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll L=1, R=1000000000000;
		ll s=0;
		while(L<=R){
			ll mid=(L+R)/2;
			ll sum=0;
			for(ll i=0;i<n;++i){
				if(v[i]<mid){
					sum+=(mid-v[i]);
				}
			}
			if(sum<=k){
				s=max(s,mid);
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		for(ll i=0;i<n;++i){
			if(v[i]<s){
				k-=(s-v[i]);
				v[i]=s;
			}
		}
		// k가 남았음
		sort(v.begin(),v.end());
		
		
		ll cnt=0;
		for(ll i=0;i<n;++i){
			if(v[i]>s){
				++cnt;
			}
		}
		ll ans=s+(s-1)*(n-1)+cnt;
		cout<<ans<<"\n";
	}
	return 0;
}