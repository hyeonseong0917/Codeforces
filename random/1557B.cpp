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
		// n개의 고유한 정수들
		// 비내림차순으로 정렬하고싶음
		// 다음 operation을 순서대로 정확히 1번 하면서

		// 수열을 k개의 서브배열들로 나눔
		// 이 서브배열들을 다시 재정렬함
		// 서브배열들을 새로운 순서로 합침
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		// k개의 서브어레이들로 나눔
		// 비내림차순으로 묶어보기 => k개보다 많으면 fail
		ll ans=1;
		for(ll i=1;i<n;++i){
			if(v[i]<v[i-1]){
				++ans;
			}
		}
		if(ans<=k){
			cout<<"Yes"<<"\n";
		}else{
			cout<<"No"<<"\n";
		}
	} 
	return 0;
}