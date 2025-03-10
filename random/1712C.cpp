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
		// 1618
		// n개의 양의 정수들이 주어짐
		// 하나의 operation
		// 아무 정수 x를 고름
		// 모든 i, a[i]=x에 대해 a[i]=0을 할당
		// 최소의 오퍼레이션 수 비내림차순으로 마들기 위한
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// 3 3 2
		// 1 3 1 3
		// 4 1 5 3 2
		// 0 1 5 3 2
		// 0 0 0 3 2
		// 0 0 0 0 2

		// 2 4 1 2
		// 0 0 1 2
		// 1. 뒤에서부터 보면서 내림차순 발견시 다 0?
		// 2. 1 12 11 4 5 6 7 10 9 10 11 12
		ll idx=-1;
		vector<ll> check(n+1,0);
		for(ll i=n-1;i>=1;--i){
			if(v[i-1]>v[i]){
				idx=i;
				break;
			}
		}
		if(idx==-1){
			cout<<0<<"\n";
		}else{
			ll ans=0;
			for(ll i=0;i<idx;++i){
				if(!check[v[i]]){
					++ans;
				}
				++check[v[i]];
			}
			if(!check[v[n-1]]){
				ll cur_idx=n-1;
				while(cur_idx>=idx){
					if(check[v[cur_idx]]){
						break;
					}
					--cur_idx;
				}
				for(ll i=idx;i<=cur_idx;++i){
					if(!check[v[i]]){
						++ans;
						++check[v[i]];
					}
				}
			}else{
				for(ll i=idx;i<n;++i){
					if(!check[v[i]]){
						++ans;
						++check[v[i]];
					}
				}
			}
			cout<<ans<<"\n";
		}
	} 
	return 0;
}