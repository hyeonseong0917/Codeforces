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
		if(n==2){
			ll ans=max(0ll,v[0]-v[1]);
			cout<<ans<<"\n";
		}else{
			ll ans=0;
			if(n%2==0){
				v.push_back(0);
			}
			for(ll i=1;i<n;i+=2){
				if(v[i-1]+v[i+1]<=v[i]) continue;
				if(v[i-1]>v[i]){
					ans+=v[i-1]-v[i];
					v[i-1]=v[i];
				}
				if(v[i+1]>v[i]){
					ans+=v[i+1]-v[i];
					v[i+1]=v[i];
				}
				if(v[i]<v[i-1]+v[i+1]){
					ll c=min(v[i+1],v[i-1]+v[i+1]-v[i]);
					ans+=c;
					v[i+1]-=c;
				}
			}
			cout<<ans<<"\n";
		}
	} 	

	return 0;
}