#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<pair<ll,ll>> v;
		vector<ll> a;
		map<ll,ll> m;
		for(ll i=0;i<n;++i){
			ll c;
			cin>>c;
			if(!m[c]){
				++m[c];
				a.push_back(c);
			}else{
				++m[c];
			}
		}
		if(n==1){
			cout<<1<<"\n";
			continue;
		}
		sort(a.begin(),a.end());
		for(ll i=0;i<a.size();++i){
			v.push_back({a[i],m[a[i]]});
		}
		ll L=0, R=0, ans=0;
		ll vs=v.size();
		vector<ll> psum(vs,0);
		psum[0]=v[0].second;
		for(ll i=1;i<vs;++i){
			psum[i]=psum[i-1]+v[i].second;
		}
		while(L<=R && R<vs){
			// ++R 가능한지?
			if(R+1<vs && v[R+1].first-v[L].first+1<=k && v[R+1].first==v[R].first+1){
				++R;
				ans=max(ans,psum[R]-psum[L]+v[L].second);
			}else{
				ans=max(ans,psum[R]-psum[L]+v[L].second);
				if(L==R){
					++L;
					++R;
				}else{
					++L;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}