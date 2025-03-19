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
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first>b.first;
}
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// 1909
		// n명의 친구들 초대
		// 각 친구 i에게는 k[i]를 할당함
		// 인근 샾에는 m개의 유니크한 가능한 선물들이 있음
		// j번째 선물은 c[j]달러의 비용 필요
		// 하나의 선물을 2번 이상 못삼
		// 선물 j를 살 때, j<=k[i]인 경우에만 구매 가능
		// 친구 i가 선물 j를 받으려면, j<=k[i]
		// 친구 i에게 선물 대신에 c[k[i]]를 그냥 줄수도 있
		// 모든 친구들에게 선물을 주는 최소 비용 구하기
		ll n,m;
		cin>>n>>m;
		vector<ll> k(n+1,0); //1<=k<=m // 부담감
		vector<ll> c(m+1,0);
		vector<pair<ll,ll>> p;
		
		for(ll i=1;i<=n;++i){
			cin>>k[i];
			p.push_back({k[i],i});
		}
		sort(p.begin(),p.end(),comp);
		// c는 오름차순 정렬되어 있음
		// 1. i번째 친구의 부담감보다 작거나 같은 선물만받음
		// 2. 선물을 받거나 아니면 c[k[i]]의 현금을 받음
		// 나는 최소 비용만 쓰고싶음음
		for(ll i=1;i<=m;++i){
			cin>>c[i];
		}
		ll ans=0;
		ll L=1;
		for(ll i=0;i<n;++i){
			ll cur_num=p[i].first;
			ll cur_idx=p[i].second;
			if(cur_num>=L){
				ans+=c[L];
				++L;
			}else{
				ans+=c[k[cur_idx]];
			}
			// cout<<i<<" "<<ans<<endl;
		}
		cout<<ans<<"\n";
		// 1 2 3  4  5
		// 2 3 2  4  2
		// 3 5 12 20 

		
	} 
	return 0;
}