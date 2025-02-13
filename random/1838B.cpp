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
		vector<ll> check(n+1,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			check[v[i]]=i;
		}
		if(v[0]==1 || v[n-1]==1){
			ll sed_idx=check[2];
			if(v[0]==1){
				cout<<sed_idx+1<<" "<<n<<"\n";
			}else{
				cout<<sed_idx+1<<" "<<1<<"\n";
			}
		}else{
			// 1을 사이드로 보내야함
			ll fst_idx=check[1];
			ll sed_idx=check[2];
			ll n_idx=check[n];
			ll L=min(fst_idx,sed_idx);
			ll R=max(fst_idx,sed_idx);
			if(L<n_idx && n_idx<R){
				cout<<1<<" "<<1<<"\n";
			}else{
				
				if(n_idx<L){
					cout<<L+1<<" "<<n_idx+1<<"\n";
				}else{
					cout<<R+1<<" "<<n_idx+1<<"\n";
				}
			}

		}
	} 	

	return 0;
}