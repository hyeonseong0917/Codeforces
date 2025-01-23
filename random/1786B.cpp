#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,w,h;
		cin>>n>>w>>h;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		ll L,R;
		if(n==1){
			cout<<"YES"<<"\n";
			continue;
		}
		bool flag=0;
		ll min_num=-2023101800;
		ll max_num=2023101800;
		for(ll i=0;i<n;++i){
			ll l=a[i]-w-(b[i]-h);
			ll r=a[i]+w-(b[i]+h);
			min_num=max(min_num,l);
			max_num=min(max_num,r);
		}
		if(min_num<=max_num){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 
	return 0;
}
