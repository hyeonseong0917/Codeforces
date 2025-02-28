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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		ll ans=-2023101800;
		for(ll i=0;i<n-1;++i){
			ll tmp=sum-v[i]-v[i+1];
			tmp+=v[i]*-1+v[i+1]*-1;
			ans=max(ans,tmp);
		}
		cout<<ans<<"\n";

	} 
	return 0;
}