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
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		sort(a.begin(),a.end());
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			psum[i]=(i==0)?b[0]:psum[i-1]+b[i];
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			// i번째 스테이지 클리어한경우의 스코어의 최댓값을 구한다
			// 가능하다면 최대의 x * (i+1) 이 현재점수일것임
			ll L=0, R=1000000000;
			ll max_x=0;
			while(L<=R){
				ll x=(L+R)/2;
				// x로 i번째스테이지까지 가능함??
				// 1. x보다 크거나 같은거 a에 몇 개 있는지?
				// 2. i번째 스테이지 클리어까지: psum[i]개
				// 2<=1 이라면 성립, L=x+1
				// 아니라면 R=x-1
				// 1. x보다 크거나 같은 최소의 인덱스를 찾는다
				ll l=0, r=n-1;
				ll min_idx=n;
				while(l<=r){
					ll m=(l+r)/2;
					if(a[m]>=x){
						min_idx=min(min_idx,m);
						r=m-1;
					}else{
						l=m+1;
					}
				}
				if(min_idx==n){
					R=x-1;
				}else{
					ll atk_cnt=n-min_idx;
					if(atk_cnt>=psum[i]){
						max_x=max(max_x,x);
						L=x+1;
					}else{
						R=x-1;
					}
				}
			}
			ll c=(ll)(max_x*(ll)(i+1));
			ans=max(ans,c);
		}
		cout<<ans<<"\n";
	} 	

	return 0;
}