#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o;
	cin>>o;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> l(n,0),r(n,0),m(n,0);
		for(ll i=0;i<n;++i){
			cin>>l[i]>>r[i]>>m[i];
		}
		vector<pair<ll,pair<ll,ll>>> v;
		for(ll i=0;i<n;++i){
			v.push_back({m[i],{l[i],r[i]}});
		}
		sort(v.begin(),v.end());
		for(ll i=0;i<n;++i){
			if(k<v[i].first && v[i].second.first<=k && k<=v[i].second.second){
				k=v[i].first;
			}
		}
		cout<<k<<"\n";

	}
	return 0;
}