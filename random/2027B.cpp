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
		// m
		// 스탈린 sort란??
		// 2번째 원소부터 시작해서, 비내림차순이 될 때까지 진행하는데
		// 해당 원소가 그 전의 원소보다 작다면 삭제함
		// 아무 subarray에 스탈린 sort를 무제한으로 진행해서
		// non-increasing으로 만들 수 있으면 vulnerable

		// [3,6,4,9,2,5,2]
		// [3,6,9,9,9,9]
		// 6보다 큰게 1개라면?? 큰거 지우기.. 끝
		// 현재 수보다 큰거 2개 이상이면 현재 수 지우기
		// 현재 수 지우기 vs 현재 수보다 큰 수들 다 지우기
		// [3,6,4,9,2,5,2,13,12,11]
		// [3,6,9]
		// [6,4,2,5,2]
		// [6,4,7,5,2]
		
		// [3,6,4,9,2,5,2]
		// 목표는 내림차순으로 만드는 것

		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll max_num=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			max_num=max(max_num,v[i]);
		}
		ll ans=2023101800;
		for(ll i=0;i<n;++i){
			// i번째 수를 최강으로
			ll fst_cnt=i;
			
			ll sed_cnt=0;
			for(ll j=i+1;j<n;++j){
				if(v[j]>v[i]){
					++sed_cnt;
				}
			}
			ans=min(ans,fst_cnt+sed_cnt);
		}
		cout<<ans<<"\n";

	} 
	return 0;
}