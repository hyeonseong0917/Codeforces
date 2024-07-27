#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first>b.first;
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0),b(n,0);
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
			v.push_back({a[i]+b[i],i});
		}
		sort(v.begin(),v.end(),comp);
		ll as=0, bs=0;
		for(ll i=0;i<n;++i){
			if(i%2==0){
				as+=(a[v[i].second]-1);
			}else{
				bs+=(b[v[i].second]-1);
			}
		}
		cout<<as-bs<<"\n";
	} 
	return 0;
}