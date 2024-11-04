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
	ll o;
	cin>>o;
	while(o--){
		vector<pair<ll,ll>> v;
		ll n,s,m;
		cin>>n>>s>>m;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		ll max_num=max(v[0].first, m-v[n-1].second);
		for(ll i=0;i<n-1;++i){
			max_num=max(max_num,v[i+1].first-v[i].second);
		}
		if(max_num>=s){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}