#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> c(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			c[i]=v[i];
		}
		if(n==1){
			if(v[0]==0){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
			continue;
		}
		map<ll,ll> m;
		vector<ll> unique_num;
		sort(c.begin(),c.end());
		ll mex=0;
		for(ll i=0;i<n;++i){
			if(c[i]==mex){
				++mex;
			}
		}
		for(ll i=0;i<n;++i){
			++m[v[i]];
		}
		// cout<<mex<<"\n";
		if(mex==n){
			cout<<"NO"<<"\n";
			continue;
		}
		ll mex_min_idx=-1;
		ll mex_max_idx=-1;
		for(ll i=0;i<n;++i){
			if(v[i]==mex+1){
				mex_min_idx=i;
				break;
			}
		}
		for(ll i=n-1;i>=0;--i){
			if(v[i]==mex+1){
				mex_max_idx=i;
				break;
			}
		}
		if(mex_min_idx==-1){
			bool flag=0;
			for(ll i=0;i<n;++i){
				if(m[v[i]]>=2 || v[i]>mex+1){
					flag=1;
					break;
				}
			}
			if(flag){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}else{
			bool flag=0;
			for(ll i=mex_min_idx;i<=mex_max_idx;++i){
				--m[v[i]];
				if(v[i]<mex && !m[v[i]]){
					flag=1;
					break;
				}
				v[i]=mex;
			}
			
			if(!flag){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}
	}
	return 0;
}