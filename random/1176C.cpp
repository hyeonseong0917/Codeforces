#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int o=1;
	// cin>>o;
	while(o--){
		// 1533
		// 4 8 15 16 23 42 중 하나임 각 수는
		// 최소한의 원소를 지워서 수열을 good으로 만들기
		// 길이 k인 수열은 good이다 언제? k가 6으로 나누어 떨어지고
		// k/6개의 서브시퀀스로 배열을 나눌 수 있을 때
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> d(6,0);
		d[0]=4;
		d[1]=8;
		d[2]=15;
		d[3]=16;
		d[4]=23;
		d[5]=42;
		vector<ll> dp(6,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		for(ll i=0;i<n;++i){
			ll idx=-1;
			for(ll j=0;j<6;++j){
				if(d[j]==v[i]){
					idx=j;
				}
			}
			if(idx==0){
				++dp[idx];
			}else{
				if(dp[idx-1]){
					--dp[idx-1];
					++dp[idx];
				}
			}
		}
		
		cout<<n-dp[5]*6<<"\n";
	} 

	return 0;
}