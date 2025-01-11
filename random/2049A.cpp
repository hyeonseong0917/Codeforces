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
		// n<=50
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// subarray를 해당 subarray의 mex로 대체한다
		// 다 0이면 0
		bool is_all_zero=1;
		bool is_zero_exist=0;
		for(ll i=0;i<n;++i){
			if(v[i]){
				is_all_zero=0;
			}else{
				is_zero_exist=1;
			}
		}
		if(is_all_zero){
			cout<<0<<"\n";
			continue;
		}
		if(is_zero_exist){
			// 123400
			// 001234
			// 010110
			// 언제 001234인지??
			ll last_idx=-1;
			bool flag=0;
			for(ll i=0;i<n;++i){
				if(v[i]>0){
					if(last_idx==-1){
						last_idx=i;
					}else{
						if(i!=last_idx+1){
							flag=1;
							break;
						}else{
							last_idx=i;
						}
					}
				}
			}
			if(flag){
				cout<<2<<"\n";
			}else{
				cout<<1<<"\n";
			}
		}else{
			// 0없음
			cout<<1<<"\n";
		}

	} 
	return 0;
}