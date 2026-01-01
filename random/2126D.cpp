#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
bool comp(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
	return a.first.first<b.first.first;
}
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<pair<pair<ll,ll>,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({{a,b},c});
		}
		sort(v.begin(),v.end(),comp);
		for(ll i=0;i<n;++i){
			ll L=v[i].first.first;
			ll R=v[i].first.second;
			ll C=v[i].second;
			if(L<=k && k<=R){
				k=max(k,C);
			}
		}
		cout<<k<<"\n";
	} 	

	return 0;
}