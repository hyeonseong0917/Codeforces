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
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> psum(n+1,0);
		psum[n-1]=v[n-1];
		for(ll i=n-2;i>=0;--i){
			psum[i]=psum[i+1]+v[i];
		}
		ll ans=psum[1]*-1;
		ll sum=v[0];
		for(ll i=1;i<n;++i){
			ans=max(ans,sum+psum[i+1]*-1);
			if(v[i]<0){
				sum+=v[i]*-1;
			}else{
				sum+=v[i];
			}
		}
		cout<<ans<<"\n";
	} 	

	return 0;
}