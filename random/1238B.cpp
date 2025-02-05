#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n,r;
		cin>>n>>r;
		map<ll,ll> check;
		vector<ll> v(n,0);
		vector<ll> p;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(!check[v[i]]){
				++check[v[i]];
				p.push_back(v[i]);
			}
		}
		sort(p.rbegin(),p.rend());
		ll cnt=0;
		for(ll i=0;i<p.size();++i){
			p[i]-=r*cnt;
			if(p[i]<=0) continue;
			++cnt;
		}
		cout<<cnt<<"\n";
	} 

	return 0;
}