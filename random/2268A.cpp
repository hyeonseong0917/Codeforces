#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n+1,0);
		for(ll i=1;i<=n;++i){
			cin>>v[i];
		}
		ll L=k;
		ll R=n-k+1;
		// ll tmp=L;
		// L=min(L,R);
		// R=max(tmp,R);
		ll cnt=n-k+1;
		ll ans=0;
		vector<ll> check(n+1,0);
		vector<ll> p;
		while(L<R && cnt--){
			if(v[L]<=v[R]){
				ans+=v[R];
				++check[R];
				--R;
			}else{
				ans+=v[L];
				++check[L];
				++L;
			}
		}
		// cout<<ans<<"\n";
		p.push_back(0);
		for(ll i=1;i<=n;++i){
			if(!check[i]){
				p.push_back(v[i]);
			}
		}
		ll ps=p.size();
		L=k;
		R=ps-k;
		while(cnt--){
			ans+=max(p[L],p[R]);
			// cout<<ans<<" "<<L<<" "<<R<<endl;
			--R;
			++L;
		}
		//  L>=R
		cout<<ans<<"\n";
	} 	

	return 0;
}