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
	if(a.second==b.second){
		return a.first>b.first;
	}
	return a.second>b.second;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 수열 b의 점수를 k개의 원소를 가진다고 했을 때,
		// s[0]+s[1]+s[2]+...
		// m개의 원소를 가진 n개의 수열들
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
		vector<pair<ll,ll>> p;
		
		for(ll i=0;i<n;++i){
			vector<ll> psum(m+1,0);
			for(ll j=0;j<m;++j){
				psum[j]=(j==0)?v[i][j]:psum[j-1]+v[i][j];
			}
			vector<ll> ppsum(m+1,0);
			for(ll j=0;j<m;++j){
				ppsum[j]=(j==0)?psum[j]:psum[j-1]+v[i][j];
			}
			ll cur_psum=0;
			for(ll j=0;j<m;++j){
				cur_psum+=ppsum[j];
			}
			p.push_back({cur_psum,psum[m-1]});
		}
		sort(p.begin(),p.end(),comp);
		// for(ll i=0;i<n;++i){
		// 	cout<<p[i].first<<" "<<p[i].second<<"\n";
		// }
		ll ans=0;
		ll cur_psum=0;
		for(ll i=0;i<n;++i){
			ans+=cur_psum*m+p[i].first;
			cur_psum+=p[i].second;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}