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
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n,0);
		map<ll,ll> check;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++check[v[i]];
		}
		sort(v.rbegin(),v.rend());
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(!check[v[i]]) continue;
			--check[v[i]];
			if(v[i]%x!=0){
				++ans;
			}else{
				if(check[v[i]/x]){
					--check[v[i]/x];
				}else{
					++ans;
				}
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}