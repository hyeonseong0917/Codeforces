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
	int t=1;
	// cin>>t;
	while(t--){
		// 2개의 n티어 케이크를 사고싶음
		// 각 케이크는 n개의 서로 다른 티어들로 구성됨
		// 크기 1에서 크기 n까지
		// 2명이 케이크를 사려는데 반드시 오름차순으로 사야함
		ll n;
		cin>>n;
		vector<vector<ll>> v;
		for(ll i=0;i<=n;++i){
			vector<ll> tmp;
			v.push_back(tmp);
		}
		for(ll i=0;i<n*2;++i){
			ll c;
			cin>>c;
			v[c].push_back(i);
		}
		ll ans=v[1][0]+v[1][1];
		for(ll i=2;i<=n;++i){
			ll fst_num=abs(v[i][0]-v[i-1][0])+abs(v[i][1]-v[i-1][1]);
			ll sed_num=abs(v[i][0]-v[i-1][1])+abs(v[i][1]-v[i-1][0]);
			ans+=min(fst_num,sed_num);
		}
		cout<<ans;

	} 
	return 0;
}