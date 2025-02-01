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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.rbegin(),v.rend());
		// 4 3 2 2 1
		// 4 3 2 2 1
		// k=8
		ll sum=0;
		ll ans=2023101800;
		for(ll i=0;i<n;++i){
			sum+=v[i];
			if(sum==k){
				ans=0;
				break;
			}
			if(sum>k){
				sum-=v[i];
				ans=k-sum;
				break;
			}else{
				// sum<=k
				ans=min(ans,k-sum);
			}
		}
		cout<<ans<<"\n";


	} 
	return 0;
}