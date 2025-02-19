#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

ll mod=998244353;

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0),dp1(n+1,0),dp2(n+1,0),dp3(n+1,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=0;i<n;++i){
			dp1[i+1]=dp1[i];
			dp2[i+1]=dp2[i];
			dp3[i+1]=dp3[i];
			if(v[i]==1){
				// 1개수 갱신
				dp1[i+1]=(dp1[i+1]+1)%mod;
			}else if(v[i]==2){
				// 2인 경우는 2를 붙이거나 1뒤에 붙일 수 있음
				dp2[i+1]=(((dp2[i+1]*2)%mod)+(dp1[i]))%mod;
			}else{
				// 3인 경우는 2 뒤에 붙이면 됨 그냥
				dp3[i+1]=(dp3[i+1]+dp2[i])%mod;
			}
		}
		cout<<dp3[n]<<"\n";
		
	} 	

	return 0;
}