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
		// n개의 사탕들
		// i번째 사탕은 w[i]의 무게를 가짐
		// a와 b는 사탕을 먹음
		// a는 왼쪽끝부터, b는 오른쪽 끝부터
		// 둘 다 같은 무게의 사탕을 먹는게 목표임. 최대 먹을 수 있는 사탕의 개수는?
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> ldp(n,0),rdp(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			ldp[i]=(i==0)?v[i]:ldp[i-1]+v[i];
		}
		for(ll i=n-1;i>=0;--i){
			rdp[i]=(i==n-1)?v[i]:rdp[i+1]+v[i];
		}
		ll L=0;
		ll R=n-1;
		ll ans=0;
		while(L<R){
			if(ldp[L]==rdp[R]){
				ans=max(ans,L+1+n-R);
				++L;
				--R;
			}else if(ldp[L]<rdp[R]){
				++L;
			}else{
				--R;
			}
		}
		cout<<ans<<"\n";
		

	} 	

	return 0;
}