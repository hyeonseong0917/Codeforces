#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back


int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){	
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> psum(n,0);
		string s;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(i==0){
				psum[i]=v[i];
			}else{
				psum[i]=psum[i-1]+v[i];
			}
		}
		cin>>s;
		ll min_l=-1,max_r=-1;
		for(ll i=0;i<n;++i){
			if(s[i]=='L'){
				min_l=i;
				break;
			}
		}
		for(ll i=n-1;i>=0;--i){
			if(s[i]=='R'){
				max_r=i;
				break;
			}
		}
		if(min_l==-1 || max_r==-1 || max_r<min_l){
			cout<<0<<"\n";
			continue;
		}
		ll ans=psum[max_r]-psum[min_l]+v[min_l];
		ll L=min_l+1, R=max_r-1;
		while(L<R){
			if(s[L]=='L'){
				while(L<R){
					if(s[R]=='R'){
						break;
					}
					--R;
				}
				if(L<R){
					ans+=psum[R]-psum[L]+v[L];
				}
				++L;
				--R;
			}else{
				++L;
			}
		}
		cout<<ans<<"\n";

	}
	return 0;
}