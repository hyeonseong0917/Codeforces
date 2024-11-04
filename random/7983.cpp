#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second<b.second;
}

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),comp);
		ll x=v[0].second-v[0].first+1;
		ll last=v[0].second;
		for(ll i=1;i<n;++i){
			if(last+v[i].first>v[i].second){
				x-=(last+v[i].first)-v[i].second;
				last=v[i].second;
			}else{
				last+=v[i].first;
			}
			// cout<<i<<" "<<last<<" "<<x<<endl;
		}
		cout<<x-1;
	}
	return 0;
}