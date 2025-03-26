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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> c(26,0);
		ll ans=0;
		// 0 0 0
		// 1
		// 2 2
		// 3
		for(ll i=0;i<n;++i){
			++c[v[i]];
			if(c[0]>=3 && c[1]>=1 && c[2]>=2 && c[5]>=1 && c[3]>=1){
				ans=i+1;
				break;
			}
			
		}
		cout<<ans<<"\n";
	} 

	return 0;
}