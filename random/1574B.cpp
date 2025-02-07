#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	// cin>>t;
	// 1203
	while(t--){
		// n명의 heroes, 힘은 a[i]
		// 아무 히어로의 힘을 1 증가 -> 코인 써서
		// m개의 드래곤, 방어막 x[i]와 공격력 y[i]
		// 드래곤의 방어력이 x라면 x이상의 공격력을 가진 병사 보내야함
		// 나머지 남은 병사들의 전체 공격력 합이 y이상이어야함
		// i번째 드래곤에 대해 성을 방어하기 위해 필요한 최소 코인
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll psum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			psum+=v[i];
		}
		ll m;
		cin>>m;
		sort(v.begin(),v.end());
		vector<pair<ll,ll>> p;
		for(ll i=0;i<m;++i){
			ll x,y;
			cin>>x>>y;
			p.push_back({x,y});
		}
		vector<ll> ans;
		for(ll i=0;i<m;++i){
			ll x=p[i].first;
			ll y=p[i].second;
			ll g=0;
			
			// 2 3 3 6
			// 4 14
			// x를 i번쨰, i+1번째..로 선택할수록 psum은 감소세
			// v[i]<=x && psum-v[i]<=y면 이 떄 최적
			// 아니라면? v[i]>=x && psum-v[i]>=y도 최적
			// v[i]>x && psum-v[i]<=y라면 R감소
			// v[i]<x && psum-v[i]>=y라면 L증가

			ll L=0, R=n-1;
			ll ans=x+y;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid]<=x && psum-v[mid]<=y){
					ans=min(ans,x-v[mid]+y-(psum-v[mid]));
					break;
				}else if(v[mid]>=x && psum-v[mid]>=y){
					ans=0;
					break;
				}else{
					// a<=x && b<=y, a>=x && b>=y 둘 다 만족x
					if(v[mid]>x && psum-v[mid]<=y){
						ans=min(ans,y-(psum-v[mid]));
						R=mid-1;
					}else{
						ans=min(ans,x-v[mid]);
						L=mid+1;
					}
				}
			}
			cout<<ans<<"\n";
			// |x-v[mid]|+|y-psum+v[mid]|
			// 더 개선하는 방법
			// 1. x>=v[mid] & y<(psum-v[mid])
			// 1. x-v[mid]-y+psum-v[mid]

			// 2. x<v[mid] && y>=(psum-v[mid])
			// 2. v[mid]-x+y-psum+v[mid]
			
		}
	} 

	return 0;
}