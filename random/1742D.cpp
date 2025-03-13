#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		// 1056
		// n개의 양의 정수
		// 1<=a[i]<=1000
		// i+j의 ㅚ댓값을 찾아라. a[i]와 a[j]가 코프라임인
		//  1 2 3 4 5 6 7
		// [1,3,5,2,4,7,7]
		ll n;
		cin>>n;
		vector<ll> v(n+1,0);
		vector<ll> dp(1000+1,0);
		ll ans=-1;
		for(ll i=1;i<=n;++i){
			cin>>v[i];
			dp[v[i]]=max(dp[v[i]],i);
		}
		for(ll i=1;i<=1000;++i){
			if(!dp[i]) continue;
			for(ll j=1;j<=1000;++j){
				if(!dp[j]) continue;
				if(gcd(i,j)==1){
					ans=max(ans,dp[i]+dp[j]);
				}
			}
		}
		cout<<ans<<"\n";
		
	} 

	return 0;
}