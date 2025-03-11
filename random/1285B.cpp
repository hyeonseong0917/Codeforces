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
		// n개의 컵케잌 타입이 있음
		// 1에서 n까지 타입이 있고, 각각의 수는 무한함
		// 맛은 a[i]임, 음수,양수,0
		// 각 타입의 컵케익을 정확히 하나 사려고함
		// [l,r]세그먼트를 선택하여
		// y의 점수>adel의 점수
		// 1555
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> dp(n,0);
		ll sum=0;
		// 0 1 2 3 4 => 불행함
		// 1 0 2 3 4 => 행복함
		// 1 2 3 4 0 => 불행함함
		bool flag=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
			if(v[i]<=0){
				flag=1;
			}
		}
		if(!flag){
			cout<<"YES"<<"\n";
			continue;
		}

		// dp[x]: x인덱스를 마지막으로 가지는 최대 연속합?
		// dp[x]=max(dp[x-1],0)+v[x]
		dp[0]=v[0];
		for(ll i=1;i<n;++i){
			if(i==n-1){
				if(dp[i-1]<=0){
					dp[i]=v[i];
				}else{
					// dp[i-1]>0
					ll c=dp[i-1];
					ll idx=-1;
					for(ll j=i-1;j>=0;--j){
						c-=v[j];
						if(c==0){
							idx=j;
							break;
						}
					}
					if(idx==0){
						ll min_num=2023101800;
						ll cs=0;
						for(ll j=0;j<i;++j){
							cs+=v[j];
							min_num=min(min_num,cs);
						}
						dp[i]=v[i]+max(0ll,dp[i-1]-min_num);
					}else{
						dp[i]=v[i]+dp[i-1];
					}
				}
			}else{
				dp[i]=max(0ll,dp[i-1])+v[i];
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			ans=max(ans,dp[i]);
		}
		if(sum>ans){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 
	return 0;
}