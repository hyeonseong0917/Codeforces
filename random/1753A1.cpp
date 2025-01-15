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
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(i%2==0){
				sum+=v[i];
			}else{
				sum-=v[i];
			}
		}
		if(sum==0){
			cout<<1<<"\n";
			cout<<1<<" "<<n<<"\n";
			continue;
		}
		sum=max(sum,sum*-1);
		if(sum%2==1){
			cout<<-1<<"\n";
			continue;
		}
		// v[i]-v[i+1]+v[i+2]-v[i+2]
		vector<pair<ll,ll>> ans;
		for(ll i=0;i<n-1;i+=2){
			if(v[i]==v[i+1]){
				ans.push_back({i,i+1});
			}else{
				ans.push_back({i,i});
				ans.push_back({i+1,i+1});
			}
		}
		ll k=ans.size();
		cout<<k<<"\n";
		for(ll i=0;i<k;++i){
			cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
		}
	} 
	return 0;
}