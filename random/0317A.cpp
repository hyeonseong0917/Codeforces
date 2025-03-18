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
		ll n,k;
		cin>>n>>k;
		// k는 홀수, 최소 3이상
		// n을 0으로 만들기
		// 매번 x를 선택해 n에서 뺄 수 있음
		// 1<=x<=k
		// n이 짝수라면 x도 짝수
		// n이 홀수라면 x도 홀수
		// n을 0으로 만드는데 필요한 최소 연산 횟수
		// n  k
		// 39 7
		// 32 6
		// 26 6

		// 40 7
		// 34 6
		ll ans=0;
		if(n%2==1){
			n-=k;
			--k;
		}else{
			n-=(k-1);
			--k;
		}
		++ans;
		if(n==0){
			cout<<ans<<"\n";
			continue;
		}
		ans+=(n+k-1)/k;
		cout<<ans<<"\n";
		// n은 지금 짝수
	} 
	return 0;
}