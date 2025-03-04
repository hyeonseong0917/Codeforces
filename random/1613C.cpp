#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 1115
		// 100의 500제곱초마큼
		// i번째 공격은 배틀이 시작되고 나서 a[i]초 시점에 수행
		// k초마다 데미지 1
		// 이미 전염된 드래곤이면 새로운 독으로 갱신
		// 최소 h의 데미지를 주면 잡을 수 있음
		// 최소의 k를 써서 드래곤을 잡고싶음
		ll n,h;
		cin>>n>>h;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll L=1, R=1000000000000000000;
		ll K=R;
		while(L<=R){
			ll mid=(L+R)/2;
			bool flag=0;
			ll cur_damage=0;
			for(ll i=1;i<n;++i){
				cur_damage+=min(mid,v[i]-v[i-1]);
			}
			cur_damage+=mid;
			if(cur_damage>=h){
				K=min(K,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<K<<"\n";
	} 
	return 0;
}