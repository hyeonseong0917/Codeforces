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
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<vector<ll>> v;
		for(ll i=0;i<n;++i){
			vector<ll> tmp;
			for(ll j=0;j<m;++j){
				ll c;
				cin>>c;
				tmp.push_back(c);
			}
			v.push_back(tmp);
		}
		// 최소 operation으로 nice로 만드는 방법?
		// 모든 row와 column이 팰린드롬들이라면
		// 한 번의 operation마다 각 수를 +1하거나 -1 할 수 있음
		ll ans=0;
		if(n%2==1){
			ll L=0, R=m-1;
			ll c=n/2;
			while(L<=R){
				ans+=abs((v[c][L]+v[c][R])/2-v[c][L])+abs((v[c][L]+v[c][R])/2-v[c][R]);
				++L;
				--R;
			}
		}
		if(m%2==1){
			ll L=0, R=n-1;
			ll c=m/2;
			while(L<=R){
				ans+=abs((v[L][c]+v[R][c])/2-v[L][c])+abs((v[L][c]+v[R][c])/2-v[R][c]);
				++L;
				--R;
			}
		}

		for(ll i=0;i<n/2;++i){
			for(ll j=0;j<m/2;++j){
				ll a=v[i][j];
				ll b=v[i][m-1-j];
				ll c=v[n-1-i][j];
				ll d=v[n-i-1][m-1-j];
				vector<ll> tmp;
				
				tmp.push_back(a);
				tmp.push_back(b);
				tmp.push_back(c);
				tmp.push_back(d);
				sort(tmp.begin(),tmp.end());
				ll mid=(tmp[1]+tmp[2])/2;
				ans+=abs(a-mid)+abs(b-mid)+abs(c-mid)+abs(d-mid);
			}
		}
		cout<<ans<<"\n";

	} 
	return 0;
}