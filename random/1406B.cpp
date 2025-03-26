#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		bool is_plus=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]>=0){
				is_plus=1;
			}
		}
		// 5개 곱의 최대를 구한다?
		if(!is_plus){
			sort(v.rbegin(),v.rend());
			ll ans=1;
			for(ll i=0;i<5;++i){
				ans*=v[i];
			}
			cout<<ans<<"\n";
		}else{
			// 음수를 짝수 개 고르거나
			// 모두양수?
			// 음수 0개 + 양수 5개
			// 음수 2개 + 양수 3개
			// 음수 4개 + 양수 1개
			sort(v.begin(),v.end());
			ll fst_num=1;
			for(ll i=n-5;i<n;++i){
				fst_num*=v[i];
			}
			ll sed_num=1;
			sed_num=v[0]*v[1];
			for(ll i=n-3;i<n;++i){
				sed_num*=v[i];
			}
			ll trd_num=1;
			for(ll i=0;i<4;++i){
				trd_num*=v[i];
			}
			trd_num*=v[n-1];
			cout<<max(fst_num,max(sed_num,trd_num))<<"\n";

		}
	} 

	return 0;
}