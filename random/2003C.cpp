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
		string s;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		cin>>s;
		ll min_l,max_r;
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
		ll L=min_l+1, R=min_l+1;
		while(L<=R && L<max_r && R<max_r){
			
		}

	}
	return 0;
}