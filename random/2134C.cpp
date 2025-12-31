#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n+1,0);
		for(ll i=1;i<=n;++i){
			cin>>v[i];
		}
		ll ans=0;
		for(ll i=2;i<=n;++i){
			if(i%2!=0) continue;
			ll L=i-1;
			ll R=i+1;
			if(v[L]>v[i]){
				ans+=v[L]-v[i];
				v[L]=v[i];
			}
			if(R<=n){
				if(v[R]>v[i]){
					ans+=v[R]-v[i];
					v[R]=v[i];
				}
			}
		}
		for(ll i=2;i<=n;++i){
			if(i%2!=0) continue;
			ll L=i-1;
			ll R=i+1;
			ll c=v[L];
			if(R<=n){
				c+=v[R];
			}
			if(c>=v[i]){
				ll diff=c-v[i];
				ans+=diff;
				if(R<=n){
					v[R]-=diff;
					v[R]=max(0ll,v[R]);
				}
			}
		}
		cout<<ans<<"\n";
		
	} 	

	return 0;
}