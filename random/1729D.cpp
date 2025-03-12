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
		// 1003
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		vector<ll> c;
		for(ll i=0;i<n;++i){
			c.push_back(b[i]-a[i]);
		}
		sort(c.begin(),c.end());
		ll ans=0;
		ll L=0, R=n-1;
		while(L<R){
			if(c[L]+c[R]>=0){
				++L;
				--R;
				++ans;
			}else{
				++L;
			}
		}
		cout<<ans<<"\n";
	} 

	return 0;
}