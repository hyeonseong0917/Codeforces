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
		// 가장 왼쪽에 앉아있는 사람 왼쪽에 앉기 아무도 없으면 m번
		// 가장 오른쪽에 앉아있는 사람 오른쪽에 앉기 없으면 1번
		// 지정석에 앉기
		ll n,m;
		cin>>n>>m;
		vector<ll> v(n,0),check(m+1,0);
		ll L=0, R=0;
		ll cnt=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]==-1){
				++L;
			}
			if(v[i]==-2){
				++R;
			}
			if(v[i]>0){
				++check[v[i]];
				if(check[v[i]]==1){
					++cnt;
				}
			}
		}
		// m개의 좌석이 있음
		ll ans=max(L,R)+cnt;
		vector<ll> dp(m+1,0); // i번째 수까지 체크된 수의 개수
		for(ll i=1;i<=m;++i){
			if(check[i]){
				dp[i]=dp[i-1];
			}else{
				dp[i]=dp[i-1]+1;
			}
		}
		// v[i]를 처음에 앉는다면?
		ll l=0, r=m-cnt;
		for(ll i=1;i<=m;++i){
			if(!check[i]) continue;
			ans=max(ans,cnt+min(L,dp[i-1])+min(R,dp[m]-dp[i]));
			
			// if(!check[i]){
			// 	++l;
			// 	--r;
			// }else{
			// 	ans=max(ans,cnt+min(l,L)+min(r,R));
			// }
		}
		cout<<min(ans,m)<<"\n";
	}
	return 0;
}