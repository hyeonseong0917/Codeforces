#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		// 판자 n개로 일렬로 배열되어 있음
		// n: 울타리의 판자 수
		// m: 사용 가능한 색상 수
		// a[i]: 각 색으로 칠할 수 있는 최대 판자 수
		vector<ll> v(m,0);
		vector<ll> dp(n+1,0);
		for(ll i=0;i<m;++i){
			cin>>v[i];
			++dp[v[i]];
		}
		// dp[i]: i개개이상인 거의 개수
		for(ll i=n-1;i>=1;--i){
			dp[i]+=dp[i+1];
		}
		ll ans=0;
		for(ll i=1;i<=n/2;++i){
			ll L=i, R=n-i;
			if(L==R){
				ans+=dp[L]*(dp[L]-1);
				break;
			}
			ll fst_num=dp[L]-1;
			ll sed_num=dp[R];
			ans+=fst_num*sed_num*2;
		}
		cout<<ans<<"\n";

	} 
	return 0;
}