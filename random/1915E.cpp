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
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(i%2==1){
				v[i]*=-1;
			}
		}
		psum[0]=v[0];
		map<ll,ll> m;
		++m[psum[0]];
		bool flag=0;
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
			if(psum[i]==0){
				flag=1;
			}
			++m[psum[i]];
		}
		
		for(ll i=0;i<n;++i){
			if(m[psum[i]]>=2){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}