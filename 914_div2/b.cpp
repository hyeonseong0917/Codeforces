#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
vector<pair<ll,ll>> p;
vector<ll> v;
ll psum[100000+1];
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		p.clear();
		v.clear();
		map<ll,ll> m;
		for(ll i=0;i<n;++i){
			psum[i]=0;
		}
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			p.push_back({i,a});
		}
		sort(p.begin(),p.end(),comp);
		psum[0]=p[0].second;
		for(ll i=1;i<n;++i){
			psum[i]=psum[i-1]+p[i].second;
		}
		ll R=0;
		ll L=0;
		while(L<n-1){
			ll pidx=L;
			R=max(R,L+1);
			while(R<n){
				if(p[R].second<=psum[pidx]){
					++pidx;
					++R;
				}else{
					--R;
					break;
				}
			}
			// cout<<L<<" "<<R<<endl;
			if(R==n) --R;
			for(ll i=L;i<=R;++i){
				m[p[i].first]=R;
			}
			L=R+1;
		}
		m[p[n-1].first]=n-1;
		for(int i=0;i<n;++i){
			cout<<m[i]<<" ";
		}cout<<"\n";
	
	}	
	return 0;
}