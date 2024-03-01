#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
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
		ll n,x;
		cin>>n>>x;
		map<ll,ll> m;
		ll k=0;
		k=max(x,(ll)2);
		ll cnt=0;
		if((n-x)%2==0){
			ll fst_num=(n-x)/2;	
			for(ll t=1;t<=(ll)sqrt(fst_num);++t){
				if(fst_num%t==0){
					if(!m[t] && t>=x-1){
						// cout<<t<<endl;
						m[t]=1;
						++cnt;	
					}
					if(!m[fst_num/t] && fst_num/t>=x-1){
						// cout<<fst_num/t<<endl;
						++m[fst_num/t];
						++cnt;
					}
				}
			}
		}
		if(x==1){
			cout<<cnt<<"\n";
			continue;
		}
		if((n+x-2)%2==0){
			ll sed_num=(n+x-2)/2;	
			for(ll t=1;t<=(ll)sqrt(sed_num);++t){
				if(sed_num%t==0){
					if(!m[t] && t>=x-1){
						// cout<<t<<endl;
						m[t]=1;
						++cnt;	
					}
					if(!m[sed_num/t] && sed_num/t>=x-1){
						// cout<<sed_num/t<<endl;
						++m[sed_num/t];
						++cnt;
					}
				}
			}
		}
		cout<<cnt<<"\n";

	}	
	return 0;
}