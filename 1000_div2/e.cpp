#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o;
	cin>>o;
	while(o--){
		map<pair<ll,ll>,ll> F;
		ll n,m1,m2;
		cin>>n>>m1>>m2;
		for(ll i=0;i<m1;++i){
			ll u,v;
			cin>>u>>v;
			F[{u,v}]=1;
			F[{v,u}]=1;
		}
		ll minus_cnt=0;
		ll plus_cnt=0;
		for(ll i=0;i<m2;++i){
			ll u,v;
			cin>>u>>v;
			if(F[{u,v}]){
				++minus_cnt;
			}else{
				++F[{u,v}];
				++F[{v,u}];
				++plus_cnt;
			}
		}
		cout<<m1-minus_cnt+plus_cnt<<"\n";	

	}
	return 0;
}