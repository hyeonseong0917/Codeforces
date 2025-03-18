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
		// 길이 n인 배열 a가 있음
		// 처음에 다 red로 색칠되어있음
		// k개의 원소를 정확히 골라서 blue로 칠함
		// 그리고 최소 하나의 레드 원소가 있으면
		// 비용: 처음에 칠한 k개의 요소 합
		// 마지막에 파란색으로 칠해진 요소의 값
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll ans=0;
		if(k==1){
			ll x=0;
			if(v[0]<v[n-1]){
				ll tmp=v[n-1];
				v[n-1]=v[0];
				v[0]=tmp;
			}
			for(ll i=1;i<n;++i){
				x=max(v[i],x);
			}
			ans+=x+v[0];
		}else{
			sort(v.rbegin(),v.rend());
			// k=5
			// 11 10 9 8 7 6 5 4 3 2 1
			for(ll i=0;i<k+1;++i){
				ans+=v[i];
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}