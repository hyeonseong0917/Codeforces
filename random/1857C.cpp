#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll cs=n*(n-1)/2;
		vector<ll> a(cs,0);
		vector<ll> ans(n,0);
		for(ll i=0;i<cs;++i){
			cin>>a[i];
		}
		sort(a.begin(),a.end());
		vector<pair<ll,ll>> v;
		ll cnt=1;
		ll num=a[0];
		for(ll i=1;i<cs;++i){
			if(num==a[i]){
				++cnt;
			}else{
				v.push_back({num,cnt});
				cnt=1;
				num=a[i];
			}
		}
		v.push_back({num,cnt});
		ll vs=v.size();

		// -2 -2 -2 -2 -1 -1 -1 -1 -1 -1
		// -2 -1 -1 -1 -1
		
		// v: [{-2,4},{-1,6}]
		// ans: [ , , , ,0]
		ans[n-1]=v[vs-1].first;
		ll idx=n-2;
		ll v_idx=vs-1;
		while(v_idx>=0 && idx>=0){
			if(v[v_idx].second<=0){
				--v_idx;
				continue;
			}
			ans[idx--]=v[v_idx].first;
			v[v_idx].second-=(n-idx-1);
		}
		// 5
		// 3 5 7 7 9
		// 3 3 3 3 5 5 5 7 7 7
		
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}