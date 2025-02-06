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
		ll n;
		cin>>n;
		// a+b=n, lcm(a,b)가 최소가 되도록
		// 짝수면 무조건 2등분
		// 홀수면
		// 최소공배수가 최소?
		// 최대공약수가 최대??
		// a,b가 있을 때 최대공약수가 최대 두 수의
		// b가 a의 배수면 ㄱㅊ?
		// a=a
		// b=a*k (k>=1)
		// n=(k+1)*a -> 이 떄 LCM은 a*k
		// 9: 3,6 4,5

		// 1. n의 모든 약수들 구하기
		vector<ll> v;
		for(ll i=1;i<=sqrt(n);++i){
			if(n%i==0){
				v.push_back(i);
				if(i*i!=n){
					v.push_back(n/i);
				}
			}
		}
		sort(v.begin(),v.end());
		ll a=1,b=n-1;
		ll ans=n-1;
		for(ll i=0;i<v.size();++i){
			ll k_plus_one=n/v[i];
			--k_plus_one;
			if(!k_plus_one) continue;
			if(ans>k_plus_one*v[i]){
				ans=k_plus_one*v[i];
				a=v[i];
				b=n-v[i];
			}
		}
		cout<<a<<" "<<b<<"\n";
	} 

	return 0;
}