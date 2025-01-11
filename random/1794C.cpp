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
		vector<ll> ans;
		for(ll i=0;i<n;++i){
			ll L=1, R=i+1;
			ll m=1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[i-mid+1]>=mid){
					m=max(m,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			ans.push_back(m);
		}
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}