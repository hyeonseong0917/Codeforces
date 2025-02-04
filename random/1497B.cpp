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
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0);
		map<ll,ll> check;
		ll ans=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++check[v[i]%m];
			if(v[i]%m==0 && ans==0){
				++ans;
			}
		}
		for(ll i=1;i<=m/2;++i){
			if(!check[i] && !check[m-i]) continue;
			ll min_num=min(check[i],check[m-i]);
			ll max_num=max(check[i],check	[m-i]);
			ans+=max(1ll,max_num-min_num);
		}
		// sort(p.begin(),p.end());
		// for(ll i=0;i<p.size();++i){
		// 	// cout<<i<<" "<<p[i]<<"\n";
		// 	if(!check[p[i]]) continue;
		// 	++ans;
		// 	ll c=p[i];
		// 	// cout<<i<<" "<<c<<endl;
		// 	while(1){
		// 		if(!check[c]) break;
		// 		--check[c];
		// 		c=m-c;
		// 	}
		// }
		cout<<ans<<"\n";
	} 

	return 0;
}