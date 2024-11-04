#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		map<ll,ll> m;
		ll max_num=0;
		ll max_cnt=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++m[v[i]];
			if(max_cnt<m[v[i]]){
				max_cnt=m[v[i]];
				max_num=v[i];
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(v[i]!=max_num) ++ans;
		}
		cout<<ans<<"\n";

	}
	return 0;
}