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
		// 1142
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n,0);
		vector<ll> psum(n,0),dp(n+1,-2023101800);
		for(ll i=0;i<n;++i){
			psum[i]=0;
		}
		// 정수 x가 주어짐
		// f(k): a의 연속적인 부분수열의 최대 합 오퍼레이션 후에
		// x를 고유한 k개의 포지션에 더함
		// 빈 서브어레이의 합은 0
		// 0에서 n까지 f(k)의 최댓값을 독립적으로 구해라
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// psum[L][R]
		for(ll i=0;i<n;++i){
			psum[i]=(i==0)?v[i]:psum[i-1]+v[i];
		}
		// 4 2
		// 4 1 3 2

		// 3 5
		//  0  1  2
		// -2 -7 -1
		// -2 -7 4
		// -2 -2 4
		// 3 -2 4

		// k==0, 가장 큰 부분합 vs 0
		// 
		// k==1, x를 
		// psum[L][R]
		// dp[x]=psum[L'][R']+x*k
		// R'-L'+1==x
		// dp[x]=max(dp[x],psum[y]-psum[y-x+1]+x*k)

		// dp[x]: 길이 x인 부분합 중 최대
		for(ll i=1;i<=n;++i){
			for(ll j=0;j+i<=n;++j){
				dp[i]=max(dp[i],psum[j+i-1]-psum[j]+v[j]);
			}
		}
		ll pre_sum=-2023101800;
		for(ll i=0;i<=n;++i){
			// i개에 x를 더함
			ll cur_num=0;
			for(ll j=i;j<=n;++j){
				// 길이 i인 최대 psum
				cur_num=max(cur_num,i*x+dp[j]);
			}
			cur_num=max(cur_num,pre_sum);
			cout<<cur_num<<" ";
			pre_sum=cur_num;
		}cout<<"\n";
	} 
	return 0;
}