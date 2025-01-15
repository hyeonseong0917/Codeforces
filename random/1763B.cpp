#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<pair<ll,ll>> v;
		vector<ll> h(n,0),p(n,0);
		vector<ll> dp(n,0);
		for(ll i=0;i<n;++i){
			cin>>h[i];
		}
		for(ll i=0;i<n;++i){
			cin>>p[i];
		}
		for(ll i=0;i<n;++i){
			v.push_back({h[i],p[i]});
		}
		sort(v.begin(),v.end());
		dp[n-1]=v[n-1].second;
		for(ll i=n-2;i>=0;--i){
			dp[i]=min(v[i].second,dp[i+1]);
		}
		bool flag=0;
		ll k_life=k;
		// k는 누적딜의 개념으로 생각
		while(1){
			// k의 딜을 가했음
			ll idx=2023101800;
			ll L=0, R=n-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(v[mid].first>k){
					idx=min(idx,mid);
					R=mid-1;
				}else{
					L=mid+1;
				}
			}
			// k보다 큰 hp를 가진 몬스터가 없음 -> 성공
			if(idx==2023101800){
				flag=1;
				break;
			}
			
			// 여기 아래부터는 현재 k보다 큰 hp를 가진 몬스터가 있는 상황
			k+=(k_life-dp[idx]);
			k_life-=dp[idx];
			if(k_life<=0) break;
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 
	return 0;
}