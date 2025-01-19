#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second>b.second;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// n개의 선반, k개의 병들
		// i번째 병들은 인덱스 b[i]와 cost c[i]
		ll n,k;
		cin>>n>>k;
		vector<ll> b(k,0), c(k,0);
		for(ll i=0;i<k;++i){
			cin>>b[i]>>c[i];
		}
		map<ll,ll> m;
		vector<ll> unique_num;
		for(ll i=0;i<k;++i){
			if(!m[b[i]]){
				unique_num.push_back(b[i]);
			}
			m[b[i]]+=c[i];
		}
		// cout<<m[1]<<endl;
		vector<pair<ll,ll>> p;
		for(ll i=0;i<unique_num.size();++i){
			p.push_back({unique_num[i],m[unique_num[i]]});
		}
		sort(p.begin(),p.end(),comp);
		ll sum=0;
		ll cnt=0;
		for(ll i=0;i<p.size();++i){
			sum+=p[i].second;
			++cnt;
			if(cnt==n) break;
		}
		cout<<sum<<"\n";
	} 
	return 0;
}