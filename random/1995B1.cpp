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
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		if(n==1){
			if(v[0]>m){
				cout<<0<<"\n";
			}else{
				cout<<v[0]<<"\n";
			}
			continue;
		}
		
		
		ll L=0, R=0;
		
		ll ans=0;
		// ans가 m보다 커지면 안됨
		while(L<=R && R<n-1){
			if(psum[R+1]-psum[L]+v[L]<=m && v[R+1]-v[L]<=1){
				ans=max(ans,psum[R+1]-psum[L]+v[L]);
				++R;
			}else{
				if(psum[R]-psum[L]+v[L]<=m){
					ans=max(ans,psum[R]-psum[L]+v[L]);
				}
				if(v[R+1]-v[L]>1){
					++R;
					for(ll i=L+1;i<=R;++i){
						if(v[R]-v[i]<=1){
							L=i;
							break;
						}
					}
					if(psum[R]-psum[L]+v[L]<=m){
						ans=max(ans,psum[R]-psum[L]+v[L]);
					}
				}else{
					// v[R+1]-v[L]<=1
					// psum[R+1]-psum[L]+v[L]이 m보다 컸음
					++L;
					if(R<L){
						R=L;
					}
					if(psum[R]-psum[L]+v[L]<=m){
						ans=max(ans,psum[R]-psum[L]+v[L]);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}