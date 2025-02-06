#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long
ll dp[300000+1][2];
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// i번쨰 포켓몬의 힘은 a[i], a[i]는 다 고유함
		// 1<=b1<b2<b3..<bk<=n 골라서 a[b1],a[b2],a[bk]
		// army의 힘은 a[b1]-a[b2]+a[b3]-a[b4]
		// maximal strength를 알고싶음
		ll n,q;
		cin>>n>>q;
		vector<ll> v(n,0);
		ll ans=0;
		ll tmp=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			tmp=max(tmp,v[i]);
			dp[i][0]=0;
			dp[i][1]=0;
		}		
		// dp[x][0]: x인덱스까지 +로 끝났을 때 최댓값
		// dp[x][1]: x인덱스까지 -로 끝났을 때 최댓값
		// dp[x][0]=dp[x-1][1]+v[x] vs dp[x-1][0]
		// dp[x][1]=dp[x-1][0]-v[x] vs dp[x-1][1]
		// 0 1 2
		// 400 1 2
		// dp[0][0]=400, dp[0][1]=0
		// dp[1][1]=dp[0][0]-v[1]=399
		// dp[1][0]=1
		// dp[2][0]=
		dp[0][0]=v[0];
		for(ll i=1;i<n;++i){
			dp[i][0]=max(dp[i-1][1]+v[i],dp[i-1][0]);
			dp[i][1]=max(dp[i-1][0]-v[i],dp[i-1][1]);
		}
		for(ll i=0;i<n;++i){
			ans=max(ans,max(dp[i][0],dp[i][1]));
		}
		cout<<ans<<"\n";
	} 

	return 0;
}