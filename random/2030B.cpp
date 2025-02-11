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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		sort(v.begin(),v.end());
		ll min_num=v[0];
		ll max_num=v[n-1];
		ll diff=v[n-1]-v[0];
		cout<<diff*(n-1)<<"\n";
	} 	

	return 0;
}