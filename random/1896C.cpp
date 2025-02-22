#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long
map<ll,ll> m;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n,x;
		cin>>n>>x;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			v.push_back({a[i],i});
		}
		sort(v.begin(),v.end());
		sort(b.begin(),b.end());
		vector<ll> ans(n,0);
		ll L=0, idx=n-x, R=n-1;
		bool flag=0;
		while(idx<n){
			ans[idx]=b[L];
			if(v[idx].first<=ans[idx]){
				flag=1;
				break;
			}
			++idx;
			++L;
		}
		// cout<<flag;
		// continue;
		idx=n-x-1;
		while(idx>=0){
			ans[idx]=b[R];
			if(v[idx].first>ans[idx]){
				flag=1;
				break;
			}
			--idx;
			--R;
		}
		if(flag){
			cout<<"NO"<<"\n";
			continue;
		}
		vector<ll> answer(n,0);
		for(ll i=0;i<n;++i){
			ll cur_idx=v[i].second;
			answer[cur_idx]=ans[i];
		}
		cout<<"YES"<<"\n";
		for(ll i=0;i<n;++i){
			cout<<answer[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}