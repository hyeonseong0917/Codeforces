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
		// 1459
		// 0에서 100 사이의 점수 획득 가능
		// 독립적으로 스테이지 수행
		// k-k/4개의 가장 높은 점수를 가진 스테이지 선택?
		// 최소 몇 개의 스테이지가 더 진행되어야
		// llya의 결과보다 크거나 같아지는지?
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}		
		sort(a.rbegin(),a.rend());
		sort(b.rbegin(),b.rend());
		ll as=0, bs=0;
		for(ll i=0;i<n-n/4;++i){
			as+=a[i];
			bs+=b[i];
		}
		if(as>=bs){
			cout<<0<<"\n";
			continue;
		}
		ll cnt=2023101800;
		// cnt개의 라운드를 추가로 진행했을 때
		ll L=1, R=10000000;
		while(L<=R){
			// mid개의 라운드를 추가로 진행
			ll mid=(L+R)/2;
			ll c=(n+mid)-(n+mid)/4;
			ll cur_as=0;
			ll cur_bs=0;
			
			// 이 때 a의 점수
			cur_as=100*min(mid,c);
			ll diff=c-mid;
			for(ll i=0;i<diff;++i){
				cur_as+=a[i];
			}
			// 이 때 b의 점수
			for(ll i=0;i<min(n,c);++i){
				cur_bs+=b[i];
			}
			if(cur_as>=cur_bs){
				cnt=min(cnt,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<cnt<<"\n";
	} 

	return 0;
}