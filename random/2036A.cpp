#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second<b.second;
}
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
		bool flag=0;
		for(ll i=1;i<n;++i){
			ll diff=abs(v[i]-v[i-1]);
			if(diff==5 || diff==7) continue;
			flag=1;
			break;
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 
	return 0;
}