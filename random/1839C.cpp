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
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(v[n-1]==1){
			cout<<"NO"<<"\n";
			continue;
		}
		ll idx=n-1;
		vector<ll> ans;
		while(idx>=0){
			ll cnt=1;
			--idx;
			while(idx>=0){
				if(v[idx]==1){
					++cnt;
					--idx;
				}else{
					break;
				}
			}
			for(ll i=0;i<cnt-1;++i){
				ans.push_back(0);
			}
			ans.push_back(cnt-1);
		}
		cout<<"YES"<<"\n";
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";

	} 
	return 0;
}