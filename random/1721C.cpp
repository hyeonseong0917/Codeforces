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
		// 1330
		// a: 비내림차순 정렬
		// b를 만들어야함
		// 1. 배열 a를 만듦. n개의 임의의 음이아닌 정수
		// 2. b[i]=a[i]+d[i]로 교체함. 모든 b[i]에 대해
		// 3. b를 비내림차순으로 정렬
		// 결과 b가 주어짐. 각 i에 대해 d[i]의 최솟값과 최댓값
		// b를 얻기 위해 선택할 수 있는
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		vector<ll> fst_vec(n,0), sed_vec(n,0);
		// 최솟값 -> a[i]기준 크거나 같은 처음 값과의 차이이
		for(ll i=0;i<n;++i){
			ll cur_num=a[i];
			ll L=0, R=n-1;
			ll min_num=2023101800;
			while(L<=R){
				ll mid=(L+R)/2;
				if(b[mid]>=cur_num){
					min_num=min(min_num,b[mid]);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			fst_vec[i]=min_num-cur_num;
		}
		for(ll i=0;i<n;++i){
			cout<<fst_vec[i]<<" ";
		}cout<<"\n";
		ll L=n-2, R=n-1;
		sed_vec[R]=b[R]-a[R];
		while(L>=0){
			if(L==R){
				sed_vec[L]=b[R]-a[L];
				--L;
				continue;
			}
			if(b[L]>=a[L+1]){
				sed_vec[L]=b[R]-a[L];
				--L;
			}else{
				--R;
			}
		}
		for(ll i=0;i<n;++i){
			cout<<sed_vec[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}