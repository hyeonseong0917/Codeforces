#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// k=2
		// a[i]: 코인의 개수
		// 처음에 p개의 코인을 가지고 있음
		// 최대하 많은 물품을 사고싶음
		// 1. 하나의 물품을 삼
		// 2. 하나의 물품을 사고 현재 산 물품의 가격을 초과하지 않는
		// 다른 물품 하나를 골라서 그것도 가져갈 수 있음
		// 최종적으로 지불하는 금악으 a[i]
		ll n,p,k;
		cin>>n>>p>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// p=6
		// 0 1 2 3 4
		// 2 3 4 5 7
		// dp[x]: x번째 인덱스까지 샀을 때 최소비용
		// dp[0]=2
		// dp[1]=3
		// dp[2]=6=4+dp[0] vs 
		// dp[3]=dp[2]+5 vs 5+dp[1]
		sort(v.begin(),v.end());
		vector<ll> dp(n,0);
		dp[0]=v[0];
		dp[1]=v[1];
		for(ll i=2;i<n;++i){
			dp[i]=v[i]+min(dp[i-1],dp[i-2]);
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(p>=dp[i]){
				ans=i+1;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}