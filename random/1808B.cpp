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
		// n개의 카드로 이루어진 덱
		// 각 카드들은 m이 써져있다? m개가 써져있다?
		// n명의 플레이어들은 덱으로부터 카드 하나씩을 받는다
		// 플레이어들은 파티를 짜고, 각 파티는 한 번씩만 게임한다
		// 몇 개의 칩이 쓰였는지? 승자에게?
		ll n,m;
		cin>>n>>m;
		vector<vector<ll>> v;
		for(ll i=0;i<n;++i){
			vector<ll> tmp;
			for(ll j=0;j<m;++j){
				ll a;
				cin>>a;
				tmp.push_back(a);
			}
			v.push_back(tmp);
		}
		ll ans=0;
		for(ll i=0;i<m;++i){
			vector<ll> tmp;
			for(ll j=0;j<n;++j){
				tmp.push_back(v[j][i]);
			}
			sort(tmp.begin(),tmp.end());
			ll sum=0;
			for(ll j=1;j<n;++j){
				sum+=tmp[j]-tmp[0];
			}
			ll cnt=n-1;
			ans+=sum;
			for(ll j=1;j<n-1;++j){
				ll diff=tmp[j]-tmp[j-1];
				sum-=diff*cnt;
				ans+=sum;
				--cnt;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}