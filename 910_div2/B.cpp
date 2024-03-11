#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ll t=0;
	cin>>t;
	while(t--){
		ll N=0;
		cin>>N;
		vector<ll> v;
		for(ll i=0;i<N;++i){
			ll a=0;
			cin>>a;
			v.push_back(a);
		}
		if(N==1){
			cout<<0<<"\n";
			continue;
		}
		ll num=v[N-1];
		ll idx=N-2;
		ll cnt=0;
		while(idx>=0){
			if(v[idx]>num){
				ll k=(v[idx]+num-1)/num;
				cnt+=k-1;
				num=v[idx]/k;
			}else{
				num=v[idx];
			}
			--idx;
		}
		cout<<cnt<<"\n";	
	}
	return 0;
}