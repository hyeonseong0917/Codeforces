#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
vector<ll> v;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		ll n,x;
		cin>>x>>n;
		v.clear();
		for(ll i=1;i<=sqrt(x);++i){
			if(x%i==0){
				v.push_back(i);
				if(x%i!=i){
					v.push_back(x/i);
				}
			}
		}
		sort(v.begin(),v.end());
		ll ans=1;
		for(ll i=0;i<v.size();++i){
			if(x%v[i]==0){
				if(n<=x/v[i]){
					ans=max(ans,v[i]);
				}
				if(n<=v[i]){
					ans=max(ans,x/v[i]);
				}
			}
		}
		cout<<ans<<"\n";
		// cout<<idx<<" "<<v[idx]<<"\n";
		
		
	}
	return 0;
}