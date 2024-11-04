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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		psum[0]=v[0];
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+v[i];
		}
		string s;
		cin>>s;
		ll L=0, R=s.size()-1;
		vector<pair<ll,ll>> p;
		while(L<R){
			if(s[L]!='L'){
				++L;
				continue;
			}
			if(s[R]!='R'){
				--R;
				continue;
			}
			p.push_back({L,R});
			++L;
			--R;
		}
		ll ans=0;
		for(ll i=0;i<p.size();++i){
			ans+=psum[p[i].second]-psum[p[i].first]+v[p[i].first];
		}
		cout<<ans<<"\n";
	}
	return 0;
}