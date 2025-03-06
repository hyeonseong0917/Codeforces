#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// 1917
		// n개 정수의 선물을 샀다. 친구들에게 공평하게 배분
		// a[1],a[2]... k명의 친구들
		// 모든 정수를 배분하려고 함
		// i번쨰 친구는 w[i]개의 정수를 받을것임
		// happiness: 친구가 받는 최소의 정수와 최대 정수의 합
		// 모든 친구들의 행복의 합을 최대로 하고싶다
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i]; // Lee가 가진 정수들
		}
		vector<ll> w(k,0);
		for(ll i=0;i<k;++i){
			cin>>w[i]; // 각 친구들에게 주고싶은 선물의 개수
		}
		vector<ll> g[n+1];
		sort(v.begin(),v.end());
		sort(w.begin(),w.end());
		ll R=n-1;
		for(ll i=0;i<k;++i){
			g[i].push_back(v[R--]);
		}
		ll ans=0;
		for(ll i=0;i<k;++i){
			if(w[i]==1){
				ans+=g[i][0]*2;
			}else{
				while(g[i].size()<w[i]){
					g[i].push_back(v[R--]);
				}
				ans+=g[i][0]+g[i][w[i]-1];
			}
		}
		cout<<ans<<"\n";
		// 1 7 13 17
		// 1 3
		// 17
		// 10 10 10 10 11 11
		// 3 3
		// w[i]의 합은 n임
		// 행복의 합을 최대로 하고싶으면 어떻게 해야할까
		// 
		
	} 
	return 0;
}