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
	int o=1;
	cin>>o;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll ans=0;
		ll cnt=0;
		for(ll i=0;i<n;++i){
			if(v[i]>=k){
				cnt+=v[i];
			}
			if(v[i]==0 && cnt){
				++ans;
				--cnt;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}