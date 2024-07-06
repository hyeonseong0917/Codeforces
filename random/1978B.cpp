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
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll sum=0;
		ll val=0;
		vector<ll> diff;
		for(ll i=1;i<n;++i){
			if(v[i]<v[i-1]){
				diff.push_back(v[i-1]-v[i]);
			}
		}
		if(diff.empty()){
			cout<<0<<"\n";
			continue;
		}
		sort(diff.begin(),diff.end());
		int ds=diff.size();
		for(ll i=0;i<ds;++i){
			diff[i]-=val;
			if(diff[i]<=0) continue;
			sum+=diff[i]*(ds-i);
		}
		cout<<sum<<"\n";
	} 
	return 0;
}