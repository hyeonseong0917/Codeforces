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
		ll n;
		cin>>n;
		vector<ll> v;
		ll pre_num=-1;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			if(a==pre_num) continue;
			v.push_back(a);
			pre_num=a;
		}
		ll cv=0;
		n=v.size();
		for(ll i=1;i<n;++i){
			cv+=abs(v[i]-v[i-1]);
		}
		if(cv==0 || n==1){
			cout<<1<<"\n";
			continue;
		}
		ll ans=2;
		for(ll i=1;i<n-1;++i){
			ll cur_num=v[i];
			ll L=cur_num-v[i-1];
			ll R=cur_num-v[i+1];
			if(L<0 && R<0){
				++ans;
			}
			if(L>0 && R>0){
				++ans;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}