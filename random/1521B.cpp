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
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<pair<pair<ll,ll>,pair<ll,ll>>> p;
		ll min_num=v[0];
		ll idx=0;
		for(ll i=0;i<n;++i){
			if(v[i]<min_num){
				min_num=v[i];
				idx=i;
			}
		}
		ll R=idx+1, cur_num=v[idx];
		while(R<n){
			p.push_back({{idx,R},{cur_num,cur_num+R-idx}});
			++R;
		}
		ll L=idx-1;
		while(L>=0){
			p.push_back({{idx,L},{cur_num,cur_num+idx-L}});
			--L;
		}
		ll ps=p.size();
		cout<<ps<<"\n";
		for(ll i=0;i<ps;++i){
			ll a=p[i].first.first+1;
			ll b=p[i].first.second+1;
			ll x=p[i].second.first;
			ll y=p[i].second.second;
			cout<<a<<" "<<b<<" "<<x<<" "<<y<<"\n";
		}
	} 	

	return 0;
}