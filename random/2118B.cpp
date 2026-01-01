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

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll cnt=1;
		vector<pair<ll,pair<ll,ll>>> v;
		v.push_back({1,{1,n}});
		// cout<<1<<" "<<1<<" "<<n<<"\n";
		for(ll i=2;i<n;++i){
			if(i!=2){
				v.push_back({i,{1,i-1}});
				// cout<<i<<" "<<1<<" "<<i-1<<"\n";
			}
			// cout<<i<<" "<<i<<" "<<n<<"\n";
			v.push_back({i,{i,n}});
		}
		v.push_back({n,{1,n-1}});
		// cout<<n<<" "<<1<<" "<<n-1<<"\n";
		ll vs=v.size();
		cout<<vs<<"\n";
		for(ll i=0;i<vs;++i){
			cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<"\n";
		}
	} 	

	return 0;
}