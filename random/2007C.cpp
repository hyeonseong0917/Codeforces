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

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// c[i]에 a만큼 증가 or b만큼 증가
		// range of d: max(d)-min(d)
		// operation 후에 range를 계산한다.
		// 이 값을 최소화하도록
		ll n,a,b;
		cin>>n>>a>>b;
		vector<ll> v(n,0);
		a=gcd(a,b);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			v[i]%=a;
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		sort(v.begin(),v.end());
		ll diff=v[n-1]-v[0];
		for(ll i=1;i<n;++i){
			// v[i],v[i-1]
			// i번째 값을 최소로 한다고 했을 때
			// [v[i],v[i]+a-1]
			diff=min(diff,v[i-1]+a-v[i]);
		}
		cout<<diff<<"\n";
	} 	

	return 0;
}