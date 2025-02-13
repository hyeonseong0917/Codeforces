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
		bool is_minus_exist=0;
		ll ans=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]<0){
				is_minus_exist=1;
				ans=v[i];
			}
		}
		if(is_minus_exist){
			cout<<ans<<"\n";
		}else{
			sort(v.begin(),v.end());
			cout<<v[n-1]<<"\n";
		}
	} 	

	return 0;
}