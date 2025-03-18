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
	int t=1;
	// cin>>t;
	while(t--){
		// 1111
		// 양의 정수 k
		// 두 수열은 k-similar
		// 엄격하게 증가
		// 같은 길이를 가짐
		// 1에서 k 사이의 양수임 모든 그들의 원소는
		// 그들은 정확히 한 포지션에서 다름
		ll n,q,k;
		cin>>n>>q>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<pair<ll,ll>> p;
		for(ll i=0;i<q;++i){
			ll a,b;
			cin>>a>>b;
			--a;
			--b;
			p.push_back({a,b});
		}
		if(n==1){
			for(ll i=0;i<q;++i){
				cout<<k-1<<"\n";
			}
			continue;
		}
		// 1 2 3 4
		// 1 2 4 5
		// 2 3, k=5
		// [2,4]
		// [2,35]
		// [13,4]

		// [2,4,6] k=8
		vector<ll> dp(n,0), psum(n,0);
		dp[0]=v[1]-2;
		dp[n-1]=k-v[n-1]+v[n-1]-v[n-2]-1;
		for(ll i=1;i<n-1;++i){
			dp[i]=v[i]-v[i-1]-1+v[i+1]-v[i]-1;
		}
		psum[0]=dp[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+dp[i];
		}
		for(ll i=0;i<q;++i){
			ll L=p[i].first;
			ll R=p[i].second;
			if(L==R){
				cout<<k-1<<"\n";
				continue;
			}
			ll sum=v[L+1]-2+k-v[R]+v[R]-v[R-1]-1;
			sum+=psum[R-1]-psum[L];
			cout<<sum<<"\n";
			// v[L:R]과 k-시밀러인 배열 몇 개 만들 수 있는지?
			// v[i]<=k
			// 정확히 한 포지션ㄴ에서 다름
			// v[L]이 다름, v[L+1]이 다름, v[L+2]가 다름..
			// 

		}
	} 
	return 0;
}