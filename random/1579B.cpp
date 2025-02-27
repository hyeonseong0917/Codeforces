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
		vector<pair<pair<ll,ll>,ll>> p;
		// 0 1 2 3 4
		// 2 5 1 4 3
		// 2 1 5 4 3
		// 1 2 5 4 3
		// 1 2 4 5 3
		// 1 2 
		for(ll i=1;i<n;++i){
			ll idx=-1;
			for(ll j=i-1;j>=0;--j){
				if(v[j]>v[i]){
					idx=j;
				}else{
					break;
				}
			}
			if(idx!=-1){
				vector<ll> tmp;
				tmp.push_back(v[i]);
				for(ll j=idx;j<i;++j){
					tmp.push_back(v[j]);
				}
				ll cnt=0;
				for(ll j=idx;j<=i;++j){
					v[j]=tmp[cnt++];
				}
				p.push_back({{idx,i},i-idx});
			}
		}
		ll ps=p.size();
		cout<<ps<<"\n";
		for(ll i=0;i<ps;++i){
			cout<<p[i].first.first+1<<" "<<p[i].first.second+1<<" "<<p[i].second<<"\n";
		}

	} 
	return 0;
}