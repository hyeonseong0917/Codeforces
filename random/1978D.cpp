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
		ll n,c;
		cin>>n>>c;
		vector<ll> v(n,0), psum(n,0), before_max(n,0), after_max(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		after_max[n-1]=v[n-1];
		for(ll i=n-2;i>=0;--i){
			after_max[i]=max(after_max[i+1],v[i]);
		}
		before_max[0]=v[0];
		for(ll i=1;i<n;++i){
			before_max[i]=max(before_max[i-1],v[i]);
		}
		vector<ll> ans(n,0);
		if(after_max[1]>v[0]+c){
			ans[0]=1;
		}
		if(before_max[n-2]>=v[n-1] || v[0]+c>=v[n-1]){
			ans[n-1]=n-1;
		}
		
		for(ll i=1;i<n-1;++i){
			ll tmp=c;
			ll cnt=0;
			if(before_max[i-1]>=v[i] || after_max[i+1]>v[i] || v[0]+tmp>=v[i]){
				tmp+=psum[i-1];
				cnt+=i;
				if(after_max[i+1]>v[i]+tmp){
					++cnt;
				}
				ans[i]=cnt;
			}
		}
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}