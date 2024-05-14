#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0), ans;
		for(ll i=0;i<n-1;++i){
			cin>>v[i];
		}
		ans.push_back(v[0]+1);
		for(ll i=0;i<n-2;++i){
			ll k=1;
			while(1){
				if(k*ans[i]+v[i]<=v[i+1]){
					++k;
				}else{
					break;
				}
			}
			ans.push_back(k*ans[i]+v[i]);
		}
		ans.push_back(ans[n-2]+v[n-2]);
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}
	
	return 0;
}