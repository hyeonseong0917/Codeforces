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
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}

		ll ans=0;
		if(n==2){
			ans=min(v[0],v[1]);
			cout<<ans<<"\n";
			continue;
		}
		for(ll i=0;i<=n-3;++i){
			vector<ll> tmp;
			for(ll j=0;j<3;++j){
				tmp.push_back(v[i+j]);
			}
			sort(tmp.begin(),tmp.end());
			ans=max(ans,tmp[1]);
		}
		
		cout<<ans<<"\n";
		
		

	}
	return 0;
}