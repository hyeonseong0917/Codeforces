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
		vector<ll> a(n+1,0),b(n+1,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		ll ans=0;
		for(ll i=0;i<n-1;++i){
			if(a[i]>b[i+1]){
				ans+=a[i]-b[i+1];
			}
		}
		ans+=a[n-1];
		cout<<ans<<"\n";
	} 
	return 0;
}