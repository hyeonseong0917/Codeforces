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
		sort(v.begin(),v.end());
		ll ans=0;
		ll L=0, R=n-1;
		for(ll i=0;i<n;++i){
			if(v[i]){
				L=i;
				break;
			}
		}
		while(L<=R){
			if(sum-(R-L+1)>=n-1){
				ans=R-L+1;
				break;
			}
			++L;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}