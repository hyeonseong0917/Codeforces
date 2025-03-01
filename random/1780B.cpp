#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// a: 길이 n
		// k>1인 k를 고른다
		// k개의 subsegment로 배열을 나눈다
		// 각 subsegment의 합을 수열 b에 쓴다
		// 최종 score은 b[i]들의 gcd임
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			psum[i]=(i==0)?v[i]:psum[i-1]+v[i];
		}
		// k=2로 만들 수 있나??
		ll ans=1;
		for(ll i=1;i<n;++i){
			ans=max(ans,gcd(psum[i-1],psum[n-1]-psum[i-1]));
		}
		cout<<ans<<"\n";
	} 
	return 0;
}