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
		map<ll,ll> m;
		vector<ll> cnt_three;
		map<ll,ll> check;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++m[v[i]];
		}
		if(n<=2){
			cout<<0<<"\n";
			continue;
		}
		// n>=3
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(m[v[i]]>=3 && !check[v[i]]){
				check[v[i]]=1;
				ll cur_num=m[v[i]];
				ans+=(cur_num*(cur_num-1)*(cur_num-2))/6;
			}
		}
		sort(v.begin(),v.end());
		vector<ll> tmp;
		map<ll,ll> unique_check;
		for(ll i=0;i<n;++i){
			if(!unique_check[v[i]]){
				unique_check[v[i]]=1;
				tmp.push_back(v[i]);
			}
		}
		ll ts=tmp.size();
		vector<ll> psum(ts,0);
		psum[0]=m[tmp[0]];
		for(ll i=1;i<ts;++i){
			psum[i]=psum[i-1]+m[tmp[i]];
		}
		for(ll i=ts-1;i>=1;--i){
			if(m[tmp[i]]>=2){
				ans+=((m[tmp[i]]*(m[tmp[i]]-1))/2)*psum[i-1];
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}