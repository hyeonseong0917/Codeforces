#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o=1;
	while(o--){
		ll n,m;
		cin>>n>>m;
		ll J;
		cin>>J;
		vector<ll> v(J,0);
		for(ll i=0;i<J;++i){
			cin>>v[i];
		}
		ll ans=0;
		ll L=1, R=m;
		for(ll i=0;i<J;++i){
			if(L<=v[i] && v[i]<=R) continue;
			if(v[i]<L){
				ans+=(L-v[i]);
				L=v[i];
				R=v[i]+m-1;
				continue;
			}
			if(v[i]>R){
				ans+=(v[i]-R);
				R=v[i];
				L=v[i]-m+1;
				continue;
			}
		}
		cout<<ans;
	}
	return 0;
}