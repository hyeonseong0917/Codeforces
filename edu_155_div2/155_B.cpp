#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
vector<ll> a,b;

int main(){
	// your code goes here
	ll t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		a.clear();
		b.clear();
		ll min_a=1222232421;
		ll min_b=1222232421;
		for(ll i=0;i<n;++i){
			ll c=0;
			cin>>c;
			min_a=min(min_a,c);
			a.push_back(c);
		}
		
		for(ll i=0;i<n;++i){
			ll c=0;
			cin>>c;
			min_b=min(min_b,c);
			b.push_back(c);
		}

		ll fst_sum=n*min_a, sed_sum=n*min_b;
		for(int i=0;i<n;++i){
			fst_sum+=b[i];
		}
		for(int i=0;i<n;++i){
			sed_sum+=a[i];
		}
		cout<<min(fst_sum,sed_sum)<<"\n";
	}
	return 0;
}