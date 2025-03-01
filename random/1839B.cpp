#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long


bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first<b.first;
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		// 1. 꺼진 앰프들 중 하나를 선택하여 켬
		// b[i]점수를 획득. 
		// 2. a[i]<=x인 (x는 켜진 앰프의 개수) 앰프들은 고장
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),comp);
		ll x=0;
		ll ans=0;
		// a[i]가 작은 순으로 켜보기
		vector<ll> check(n+1,0);
		for(ll i=0;i<n;++i){
			ll a=v[i].first;
			ll b=v[i].second;
			if(check[a]==a) continue;
			++check[a];
			ans+=b;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}