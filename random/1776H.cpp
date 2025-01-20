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
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		ll L=n-1, R=n-1;
		ll ans=0;
		ll cnt=0;
		while(L>=0){
			if(a[L]==b[R]){
				ans+=cnt;
				cnt=0;
				--R;
				--L;
			}else{
				--L;
				++cnt;
				if(L==-1){
					ans+=cnt;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}