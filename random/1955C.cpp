#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		vector<ll> v;
		cin>>n>>k;
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			v.push_back(a);
		}
		ll L=0, R=n-1;
		ll cnt=0;
		while(L<=R && k){
			bool flag=0;
			if(L==R){
				if(k>=v[L] && v[L] && k){
					++cnt;
				}
				break;
			}
			if(v[L]<=v[R]){
				if(k<(2*v[L])-1){
					flag=1;
				}else{
					k-=(2*v[L])-1;
					v[R]-=(v[L]-1);
					v[L]=0;
					++L;
					++cnt;
					if(k){
						--v[R];
						--k;
						if(!v[R]){
							++cnt;
							--R;
						}
					}
				}
			}else{
				// v[L]>v[R]
				if(k<v[R]*2){
					flag=1;
				}else{
					k-=2*v[R];
					v[L]-=v[R];
					v[R]=0;
					--R;
					++cnt;
				}
				
			}
			if(flag){
				break;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}