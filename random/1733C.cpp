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
		// L<R인 L과 R을 고른다
		// v[L]+v[R]이 홀수라면, v[R]에 v[L]을 넣는다
		// v[L]+v[R]이 짝수라면, v[L]에 v[R]을 넣는다
		// 최대 n번의 operation으로 v를 비내림차순으로 만든다

		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		vector<pair<ll,ll>> p;
		p.push_back({1,n});
		if((v[0]+v[n-1])%2==0){
			v[0]=v[n-1];
		}else{
			v[n-1]=v[0];
		}
		for(ll i=1;i<n-1;++i){
			if((v[0]+v[i])%2==1){
				p.push_back({1,i+1});
			}else{
				p.push_back({i+1,n});
			}
		}
		ll ps=p.size();
		cout<<ps<<"\n";
		for(ll i=0;i<ps;++i){
			cout<<p[i].first<<" "<<p[i].second<<"\n";
		}
	} 
	return 0;
}