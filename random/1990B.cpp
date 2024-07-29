#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,x,y;
		cin>>n>>x>>y;
		vector<ll> v(n+1,1);
		ll cnt=0;
		for(ll i=x+1;i<n+1;++i){
			if(cnt%2==0){
				v[i]=-1;
			}
			++cnt;
		}
		cnt=0;
		for(ll i=y-1;i>=1;--i){
			if(cnt%2==0){
				v[i]=-1;
			}
			++cnt;
		}
		for(ll i=1;i<=n;++i){
			cout<<v[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}