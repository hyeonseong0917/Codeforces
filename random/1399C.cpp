#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// n명의 사람들
		// i번째 참가자의 무게는 w[i]
		// 두 명으로 이루어진 팀만
		// 토탈 몸무게가 같아야함
		// 최대의 팀 수?
		// 1009
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> check(50+1,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++check[v[i]];
		}
		// n<=50, v[i]<=50
		sort(v.begin(),v.end());
		// 1 1 1 1 2 2 2 2
		ll ans=0;
		for(ll i=2;i<=100;++i){
			// 합이 i인 경우
			ll cnt=0;
			for(ll j=1;j<min(i,51ll);++j){
				for(ll k=1;k<min(i,51ll);++k){
					if(j>k) continue;
					if(j+k==i){
						if(j==k){
							cnt+=check[j]/2;
						}else{
							cnt+=min(check[j],check[k]);
						}
					}
				}
			}
			
			ans=max(ans,cnt);
		}
		cout<<ans<<"\n";

	} 	

	return 0;
}