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
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll psum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			psum+=v[i];
		}
		sort(v.begin(),v.end());
		ll ans=psum;
		for(ll i=1;i<n;++i){
			for(ll j=1;j<=v[i];++j){
				if(v[i]%j==0){
					ans=min(ans,psum-v[i]-v[0]+v[i]/j+v[0]*j);
				}
			}
		}
		cout<<ans<<"\n";
	} 	

	return 0;
}