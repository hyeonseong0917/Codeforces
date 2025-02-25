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
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll L=0, R=n-1;
		ll ans=0;
		while(L<=R){
			if(L==R) break;
			ans+=v[R--]-v[L++];
		}
		cout<<ans<<"\n";
	} 
	return 0;
}