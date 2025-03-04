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
		// non-empty team으로 n명의 개발자들을 나누고 싶음
		// 최대의 팀 수를 만들고 싶음
		// 각 팀의
		ll n,x;
		cin>>n>>x;
		vector<ll> v(n,0),dp(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// 5 10
		// 0 1  2 3 4
		// 2 5  7 9 11
		sort(v.begin(),v.end());
		if(v[n-1]>=x){
			dp[n-1]=1;
		}
		for(ll i=n-2;i>=0;--i){
			ll cnt=(x+v[i]-1)/v[i];
			if(i+cnt<=n){
				dp[i]=1;
				if(i+cnt<n){
					dp[i]+=dp[i+cnt];
				}
			}
		}
		ll ans=0;
		for(ll i=0;i<n;++i){
			ans=max(ans,dp[i]);
		}
		cout<<ans<<"\n";
		// 2 5 7 9 11
		// 0 1 2 3
		// 2 8 8 11 => x=20?
		// 0 1 2 3
		// 2 5 7 9
		// 4 6 7 9
		// dp[2]=1
		// dp[x]=1([x,y]구간 개수 * v[x]>=X)+dp[y+1]
		// 구간개수=(X+v[x]-1)/v[x]
		// 1+dp[구간개수]
	} 
	return 0;
}