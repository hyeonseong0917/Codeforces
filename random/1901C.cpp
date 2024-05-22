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
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		ll x=v[n-1]+1;
		ll cnt=0;
		while(v[0]!=v[n-1]){
			++cnt;
			v[0]=(v[0]+x)/2;
		}
		if(cnt<=n){
			cout<<cnt<<"\n";
			for(ll i=0;i<cnt;++i){
				cout<<x<<" ";
			}cout<<"\n";
		}else{
			cout<<cnt<<"\n";
		}
	}
	return 0;
}