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
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll L=0, R=n-1;
		bool flag=0;
		ll cur_max=n, cur_min=1;
		while(L<=R){
			// cout<<L<<" "<<R<<" "<<cur_min<<" "<<cur_max<<endl;
			if(L==R){
				flag=1;
				break;
			}
			bool tmp=0;
			if(cur_max==v[L]){
				--cur_max;
				++L;
				tmp=1;
				continue;
			}
			if(cur_min==v[L]){
				++cur_min;
				++L;
				tmp=1;
				continue;
			}
			if(cur_max==v[R]){
				--cur_max;
				--R;
				tmp=1;
				continue;
			}
			if(cur_min==v[R]){
				++cur_min;
				--R;
				tmp=1;
				continue;
			}
			if(!tmp) break;
		}
		if(flag){
			cout<<-1<<"\n";
		}else{
			cout<<L+1<<" "<<R+1<<"\n";
		}
	} 
	return 0;
}